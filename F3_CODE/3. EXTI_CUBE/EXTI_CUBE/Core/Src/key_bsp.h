#ifndef __KEY_BSP_H_
#define	__KEY_BSP_H_

#include "stm32f303xc.h"
#include "stm32f3xx.h"

#define KEY_GPIO_PORT GPIOA
#define KEY_GPIO_PIN GPIO_PIN_0

#define KEY_ON GPIO_PIN_SET
#define KEY_OFF GPIO_PIN_RESET

void KEY_GPIO_Init(void);
uint8_t KEY_scan(void);

#endif /* __KEY_BSP_H_ */
