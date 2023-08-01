#include "key_bsp.h"

void KEY_GPIO_Init(void)
{
	GPIO_InitTypeDef KEY_GPIO_Init;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	KEY_GPIO_Init.Mode = GPIO_MODE_INPUT;
	KEY_GPIO_Init.Pin = KEY_GPIO_PIN;
	KEY_GPIO_Init.Pull = GPIO_PULLDOWN;
	KEY_GPIO_Init.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(KEY_GPIO_PORT, &KEY_GPIO_Init);
}

uint8_t KEY_scan(void)
{
	if(HAL_GPIO_ReadPin(KEY_GPIO_PORT, KEY_GPIO_PIN) == KEY_ON)
	{
		HAL_Delay(50);
		if(HAL_GPIO_ReadPin(KEY_GPIO_PORT, KEY_GPIO_PIN) == KEY_OFF)
		{
			return KEY_OFF;
		}
		else
		{
			while(HAL_GPIO_ReadPin(KEY_GPIO_PORT, KEY_GPIO_PIN) == KEY_ON);
			return KEY_ON;
		}
	}
	else
	{
		return KEY_OFF;
	}
}

