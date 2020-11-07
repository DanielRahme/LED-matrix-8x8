/**
  ******************************************************************************
  * @file           : main.cpp
  * @brief          : Main program body
  * LED matrix 8x8 on STM32F3Discovery MCU board
  * COLUMS (active HIGH)  : Pins = <PB8 - PB15>
  * ROWS (active LOW)     : Pins = <PC0 - PC8>
  ******************************************************************************
  */
#include "main.h"
#include "gpio.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"
#include "io.hpp"
#include "freertos.hpp"

void SystemClock_Config();

void led_by_led(void* arg = nullptr) {
  for (;;) {
    for (int row_num = 0; row_num < 8; row_num++) {
      io::pins_default();

      for (int i = 0; i < 8; i++) {
        io::write_row(static_cast<io::pin>(row_num), 1 << i);
        osDelay(50);
      }
    }
    osThreadYield();
    osDelay(1000);
  };
  osThreadTerminate(NULL);
}

void led_scroll_down(void* arg = nullptr) {
  for (;;) {
    for (int i = 0; i < 8; i++) {
      io::pins_default();

      auto row_num = static_cast<io::pin>(i);
      io::write_row(row_num, 0xff);
      osDelay(50);
    }

    osThreadYield();
    osDelay(2000);
  };
  osThreadTerminate(NULL);
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

  // init Rtos
  osKernelInitialize();

  create_thread(led_by_led, static_cast<osPriority_t>(30));
  create_thread(led_scroll_down, static_cast<osPriority_t>(30));

  osKernelStart();

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
