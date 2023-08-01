#include "usart_bsp.h"

UART_HandleTypeDef huart;

void USART_Config(void)
{
	/* Configuring the Clock Source */
	RCC_PeriphCLKInitTypeDef PeriphClkInit;
	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
	PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
	HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);

	/* Initialize the UART low level resources by implementing the HAL_UART_MspInit() API */
	/* HAL_UART_MspInit() API is called in HAL_UART_Init(&huart1) */
	/* HAL_UART_MspInit() API is not used here */
	__HAL_RCC_USART1_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	
	GPIO_InitTypeDef UART_GPIO_Init;
	UART_GPIO_Init.Alternate = GPIO_AF7_USART1;
	UART_GPIO_Init.Pin = GPIO_PIN_4 | GPIO_PIN_5;
	UART_GPIO_Init.Mode = GPIO_MODE_AF_PP;
	UART_GPIO_Init.Pull = GPIO_PULLUP;
	UART_GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOC, &UART_GPIO_Init);

	HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
	
	huart.Instance = USART1;
	huart.Init.BaudRate = 115200;
	huart.Init.WordLength = UART_WORDLENGTH_8B;
	huart.Init.StopBits = UART_STOPBITS_1;
	huart.Init.Parity = UART_PARITY_NONE;
	huart.Init.Mode = UART_MODE_TX_RX;
	huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart.Init.OverSampling = UART_OVERSAMPLING_16;
	huart.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	huart.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	HAL_UART_Init(&huart);
}

int fputc(int ch, FILE *f)
{
	HAL_UART_Transmit(&huart, (uint8_t *)&ch, 1, 1000);
	return (ch);
}

int fgetc(FILE *f)
{
	int ch;
	HAL_UART_Receive(&huart, (uint8_t *)&ch, 1, 1000);
	return (ch);
}



