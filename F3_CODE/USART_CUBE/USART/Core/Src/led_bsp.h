#ifndef __LED_BSP_H_
#define	__LED_BSP_H_

#include "stm32f303xc.h"
#include "stm32f3xx.h"

#define LED_LD4_ON 			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET)
#define LED_LD4_OFF 		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET)
#define LED_LD4_TOGGLE 		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_8)

#define LED_LD3_ON 			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET)
#define LED_LD3_OFF 		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET)
#define LED_LD3_TOGGLE 		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_9)

#define LED_LD5_ON 			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET)
#define LED_LD5_OFF 		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET)
#define LED_LD5_TOGGLE 		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_10)

#define LED_LD7_ON 			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET)
#define LED_LD7_OFF 		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET)
#define LED_LD7_TOGGLE 		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_11)

#define LED_LD9_ON 			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET)
#define LED_LD9_OFF 		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET)
#define LED_LD9_TOGGLE 		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_12)

#define LED_LD10_ON 		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET)
#define LED_LD10_OFF 		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET)
#define LED_LD10_TOGGLE 	HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13)

#define LED_LD8_ON `		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET)
#define LED_LD8_OFF 		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET)
#define LED_LD8_TOGGLE 		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14)

#define LED_LD6_ON `		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET)
#define LED_LD6_OFF 		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET)
#define LED_LD6_TOGGLE 		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_15)

void LED_GPIO_Init(void);

#endif /* __BSP_LED_H_ */
