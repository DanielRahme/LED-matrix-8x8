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
void toggle_led_func(void *argument);


void iterate_leds_in_row(io::pin row)
{
  for (int i = 0; i < 8; i++) {
    io::write_row(row, 1 << i);
    HAL_Delay(50);
  }
}

void led_by_led(void* arg = nullptr)
{
    for (;;) {
        for (int row_num = 0; row_num < 8; row_num++) {
            iterate_leds_in_row(static_cast<io::pin>(row_num));
            io::pins_default();
        }
        osThreadTerminate(NULL);
    };
}

auto init_rtos = [](){
  osKernelInitialize();
  //MX_FREERTOS_Init();
  //task_toggle_ledHandle = osThreadNew(toggle_led_func, NULL, &task_toggle_led_attributes);
  osThreadAttr_t attributes = {};
  attributes.name = "defaultTask";
  attributes.priority = (osPriority_t)osPriorityNormal;
  attributes.stack_size = 512;
  osThreadNew(led_by_led, NULL, &attributes);

  osKernelStart();
};


auto init = [](){
};

int main()
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  io::pins_default();

  init_rtos();

  //led_by_led();


  while (1)
  {
    /* USER CODE END WHILE */
	  HAL_GPIO_TogglePin(LD9_GPIO_Port, LD9_Pin);
	  HAL_GPIO_TogglePin(LD4_GPIO_Port, LD4_Pin);
	  HAL_Delay(1000);
  }
}

void SystemClock_Config(void)
{
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
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
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
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}



void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}
