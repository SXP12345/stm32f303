#include "adc_bsp.h"

ADC_HandleTypeDef hadc;

void ADC_Config(void)
{
	__HAL_RCC_ADC12_CLK_ENABLE();
	RCC_PeriphCLKInitTypeDef PeriphClkInit;
	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC12;
	PeriphClkInit.Adc12ClockSelection = RCC_ADC12PLLCLK_DIV2;
	HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);

	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_Init;
	GPIO_Init.Pin = GPIO_PIN_0;
	GPIO_Init.Pull = GPIO_NOPULL;
	GPIO_Init.Mode = GPIO_MODE_ANALOG;
	HAL_GPIO_Init(GPIOA, &GPIO_Init);
	
	__HAL_RCC_DMA1_CLK_ENABLE();
	DMA_HandleTypeDef hadc_dma;
	hadc_dma.Instance = DMA1_Channel1;
	hadc_dma.Init.Direction = DMA_PERIPH_TO_MEMORY;
	hadc_dma.Init.PeriphInc = DMA_PINC_DISABLE;
	hadc_dma.Init.MemInc = DMA_MINC_ENABLE;
	hadc_dma.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
	hadc_dma.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
	hadc_dma.Init.Mode = DMA_CIRCULAR;
	hadc_dma.Init.Priority = DMA_PRIORITY_VERY_HIGH;
	HAL_DMA_Init(&hadc_dma);
	
	HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
	
	hadc.Instance = ADC1;
	hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
	hadc.Init.Resolution = ADC_RESOLUTION_12B;
	hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc.Init.ScanConvMode = ADC_SCAN_DISABLE;
	hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	hadc.Init.LowPowerAutoWait = DISABLE;
	hadc.Init.ContinuousConvMode = ENABLE;
	hadc.Init.NbrOfConversion = 1;
	hadc.Init.DiscontinuousConvMode = DISABLE;
	hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc.Init.DMAContinuousRequests = DISABLE;
	hadc.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
	HAL_ADC_Init(&hadc);

	ADC_ChannelConfTypeDef sConfig;
//	sConfig.Channel = ADC_CHANNEL_VREFINT;
	sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
	sConfig.Offset = 0x000;
	sConfig.OffsetNumber = ADC_OFFSET_NONE;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_181CYCLES_5;
	sConfig.SingleDiff = ADC_SINGLE_ENDED;
	HAL_ADC_ConfigChannel(&hadc, &sConfig);

	HAL_Delay(1000);
	HAL_ADCEx_Calibration_Start(&hadc, ADC_SINGLE_ENDED);
}

/*
(++) ADC conversion by interruption: 
          (+++) Activate the ADC peripheral and start conversions
                using function HAL_ADC_Start_IT()
          (+++) Wait for ADC conversion completion by call of function
                HAL_ADC_ConvCpltCallback()
                (this function must be implemented in user program)
                (or for injected group: HAL_ADCEx_InjectedConvCpltCallback() )
          (+++) Retrieve conversion results 
                using function HAL_ADC_GetValue()
                (or for injected group: HAL_ADCEx_InjectedGetValue() )
          (+++) Stop conversion and disable the ADC peripheral 
                using function HAL_ADC_Stop_IT()
*/



