#ifndef __EXTI_BSP_H_
#define	__EXTI_BSP_H_

#include "stm32f303xc.h"
#include "stm32f3xx.h"
#include "key_bsp.h"
#include "led_bsp.h"

#define KEY_EXTI_NVIC_PRIORITYGROUP NVIC_PRIORITYGROUP_0
#define KEY_EXTI_IRQn EXTI0_IRQn
#define KEY_EXTI_PreemptPriority 0
#define KEY_EXTI_SubPriority 0


void KEY_EXTI_Config(void);
void KEY_EXTI_Callback(void);



#endif /* __EXTI_BSP_H_ */
