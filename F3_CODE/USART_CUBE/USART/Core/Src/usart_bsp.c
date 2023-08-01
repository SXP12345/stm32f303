#include "usart_bsp.h"

UART_HandleTypeDef huart;

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{	
	GPIO_InitTypeDef USART_GPIO_Init;

	/* Enable the USARTx interface clock */
	__HAL_RCC_USART1_CLK_ENABLE();

	/* UART pins configuration */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	USART_GPIO_Init.Mode = GPIO_MODE_AF_PP;
	USART_GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
	USART_GPIO_Init.Pull = GPIO_NOPULL;
	USART_GPIO_Init.Pin = GPIO_PIN_4|GPIO_PIN_5;
	USART_GPIO_Init.Alternate = GPIO_AF7_USART1;
	HAL_GPIO_Init(GPIOC, &USART_GPIO_Init);

	/*  */
}

void USART_Init(void)
{
	
}