/**
  ******************************************************************************
  * @file           : main.cpp
  * @brief          : Main program body
  * LED matrix 8x8 on STM32F3Discovery MCU board
  * COLUMS (active HIGH)  : Pins = <PB8 - PB15>
  * ROWS (active LOW)     : Pins = <PC0 - PC8>
  ******************************************************************************
  */

#define ETL_COMPILER_IAR

#include "main.h"
#include "gpio.h"
#include "cmsis_os.h"
#include "cmsis_os2.h"
//#include "FreeRTOS.h"
#include "task.h"
#include "io.hpp"
#include "matrix.hpp"
#include "etl/array.h"
#include "display.hpp"
//#include "freertos.hpp"

void SystemClock_Config();

osTimerId thread_led_all = nullptr;  // timer id
osTimerId thread_rows = nullptr;  // timer id
osTimerId thread_scroll_right = nullptr;  // timer id

static constexpr auto TIME_ROWS = 4000;
static constexpr auto TIME_SCROLL_RIGHT = 2000;
static constexpr auto TIME_LED_ALL = 8000;


auto pixels_check = [](){
    for (int row_num = 0; row_num < 8; row_num++) {
      io::pins_default();
      for (int i = 0; i < 8; i++) {
        io::write_row(row_num, 1 << i);
        osDelay(10);
      }
    }
};

auto scroll_down_rows = [](auto line, auto delay){
    for (int i = 0; i < 8; i++) {
      io::pins_default();

      io::write_row(i, line);
      osDelay(delay);
    }
};


void callback_led_all(void *arg){
  pixels_check();
  osTimerStart(thread_led_all, TIME_LED_ALL);
  osThreadYield();
}

void callback_rows(void *arg){
  scroll_down_rows(0xff, 50);
  osTimerStart(thread_rows, TIME_ROWS);
  osThreadYield();
}

void callback_scroll_right(void *arg){
  for (int i = 0; i < 8; i++) {
    scroll_down_rows(1 << i, 10);
  }
    osTimerStart(thread_rows, TIME_SCROLL_RIGHT);  
    osThreadYield();
}

void create_periodic_thread() {
  uint32_t exec1 = 1;  // argument for the timer call back function
  uint32_t exec2 = 2;  // argument for the timer call back function


  thread_led_all = osTimerNew(callback_led_all, osTimerPeriodic, &exec1, NULL);
  if (thread_led_all != NULL) {  // One-shoot timer created
  }

  thread_rows = osTimerNew(callback_rows, osTimerPeriodic, &exec2, NULL);
  if (thread_rows != NULL) {  // Periodic timer created
  }

  thread_scroll_right = osTimerNew(callback_scroll_right, osTimerPeriodic, nullptr, NULL);
  if (thread_scroll_right != NULL) {
  }

  osTimerStart(thread_led_all, 8000);  // start timer
  osTimerStart(thread_rows, 1000);  // start timer
  osTimerStart(thread_scroll_right, 4000);  // start timer
}

void task_update_display(void *arg){
  auto matrix = Matrix({1, 2, 4, 8, 16, 32, 64, 128});
  auto d = Display(100);

  while (1) {
    d = matrix;
    osThreadYield();
  }

}

auto task_attribute = [](const auto name, const auto priority,
                         const auto stack) {
  osThreadAttr_t attributes = {};
  attributes.name = name;
  attributes.priority = priority;
  attributes.stack_size = stack;
  return attributes;
};

auto create_thread = [](auto& func, auto priority) {
  auto led_attributes = task_attribute("", priority, 512);
  osThreadNew(func, NULL, &led_attributes);
};

int main() {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  io::pins_default();

  Display disp;
  auto matrix = Matrix({1, 2, 4, 8, 16, 32, 64, 128});

  // init Rtos
  osKernelInitialize();

  //create_thread(led_by_led, static_cast<osPriority_t>(30));
  //create_thread(led_scroll_down, static_cast<osPriority_t>(30));
  create_thread(task_update_display, (osPriority_t)0);
  create_periodic_thread();

  osKernelStart();

  
  osThreadTerminate(NULL);

  //Should not come here

  while (1) {
    /* USER CODE END WHILE */
    HAL_GPIO_TogglePin(LD9_GPIO_Port, LD9_Pin);
    HAL_GPIO_TogglePin(LD4_GPIO_Port, LD4_Pin);
    HAL_Delay(1000);
  }
}

void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks
*/
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks
*/
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

void Error_Handler(void) {
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}
