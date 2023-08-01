#include "led_bsp.h"

void LED_GPIO_Init(void)
{
	GPIO_InitTypeDef LED_GPIO_Init;

	__HAL_RCC_GPIOE_CLK_ENABLE();

	LED_GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
	LED_GPIO_Init.Pull = GPIO_PULLDOWN;
	LED_GPIO_Init.Speed = GPIO_SPEED_FREQ_MEDIUM;
	LED_GPIO_Init.Pin = GPIO_PIN_8;
	LED_GPIO_Init.Pin |= GPIO_PIN_9;
	LED_GPIO_Init.Pin |= GPIO_PIN_10;
	LED_GPIO_Init.Pin |= GPIO_PIN_11;
	LED_GPIO_Init.Pin |= GPIO_PIN_12;
	LED_GPIO_Init.Pin |= GPIO_PIN_13;
	LED_GPIO_Init.Pin |= GPIO_PIN_14;
	LED_GPIO_Init.Pin |= GPIO_PIN_15;
	HAL_GPIO_Init(GPIOE, &LED_GPIO_Init);
}

