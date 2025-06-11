/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Variable.h"
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
#define keyr_1_Pin GPIO_PIN_4
#define keyr_1_GPIO_Port GPIOE
#define keyr_3_Pin GPIO_PIN_5
#define keyr_3_GPIO_Port GPIOE
#define keyr_2_Pin GPIO_PIN_6
#define keyr_2_GPIO_Port GPIOE
#define PWR_4G_Pin GPIO_PIN_12
#define PWR_4G_GPIO_Port GPIOD
#define RST_4G_Pin GPIO_PIN_13
#define RST_4G_GPIO_Port GPIOD
#define encoder3_2_Pin GPIO_PIN_15
#define encoder3_2_GPIO_Port GPIOA
#define encoder3_2_EXTI_IRQn EXTI15_10_IRQn
#define encoder3_1_Pin GPIO_PIN_3
#define encoder3_1_GPIO_Port GPIOD
#define encoder3_1_EXTI_IRQn EXTI3_IRQn
#define encoder2_1_Pin GPIO_PIN_6
#define encoder2_1_GPIO_Port GPIOD
#define encoder2_1_EXTI_IRQn EXTI9_5_IRQn
#define keyl_1_Pin GPIO_PIN_4
#define keyl_1_GPIO_Port GPIOB
#define encoder1_1_Pin GPIO_PIN_5
#define encoder1_1_GPIO_Port GPIOB
#define encoder1_1_EXTI_IRQn EXTI9_5_IRQn
#define keyl_3_Pin GPIO_PIN_6
#define keyl_3_GPIO_Port GPIOB
#define keyl_2_Pin GPIO_PIN_7
#define keyl_2_GPIO_Port GPIOB
#define encoder1_2_Pin GPIO_PIN_0
#define encoder1_2_GPIO_Port GPIOE
#define encoder1_2_EXTI_IRQn EXTI0_IRQn
#define encoder2_2_Pin GPIO_PIN_1
#define encoder2_2_GPIO_Port GPIOE
#define encoder2_2_EXTI_IRQn EXTI1_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
