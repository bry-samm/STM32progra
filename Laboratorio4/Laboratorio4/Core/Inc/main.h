/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define d_display_Pin GPIO_PIN_0
#define d_display_GPIO_Port GPIOC
#define e_display_Pin GPIO_PIN_1
#define e_display_GPIO_Port GPIOC
#define f_display_Pin GPIO_PIN_2
#define f_display_GPIO_Port GPIOC
#define g_display_Pin GPIO_PIN_3
#define g_display_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define ledJ1_1_Pin GPIO_PIN_12
#define ledJ1_1_GPIO_Port GPIOB
#define ledJ1_2_Pin GPIO_PIN_13
#define ledJ1_2_GPIO_Port GPIOB
#define ledJ1_3_Pin GPIO_PIN_14
#define ledJ1_3_GPIO_Port GPIOB
#define ledJ1_4_Pin GPIO_PIN_15
#define ledJ1_4_GPIO_Port GPIOB
#define ledJ2_1_Pin GPIO_PIN_6
#define ledJ2_1_GPIO_Port GPIOC
#define ledJ2_2_Pin GPIO_PIN_7
#define ledJ2_2_GPIO_Port GPIOC
#define ledJ2_3_Pin GPIO_PIN_8
#define ledJ2_3_GPIO_Port GPIOC
#define ledJ2_4_Pin GPIO_PIN_9
#define ledJ2_4_GPIO_Port GPIOC
#define a_display_Pin GPIO_PIN_8
#define a_display_GPIO_Port GPIOA
#define b_display_Pin GPIO_PIN_9
#define b_display_GPIO_Port GPIOA
#define c_display_Pin GPIO_PIN_10
#define c_display_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define pb_start_Pin GPIO_PIN_10
#define pb_start_GPIO_Port GPIOC
#define pb_start_EXTI_IRQn EXTI15_10_IRQn
#define pbJ1_Pin GPIO_PIN_11
#define pbJ1_GPIO_Port GPIOC
#define pbJ1_EXTI_IRQn EXTI15_10_IRQn
#define pbJ2_Pin GPIO_PIN_12
#define pbJ2_GPIO_Port GPIOC
#define pbJ2_EXTI_IRQn EXTI15_10_IRQn
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
