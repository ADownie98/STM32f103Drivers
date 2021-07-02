/*
 * HAL_adc.c
 *
 *  Created on: Apr 13, 2021
 *      Author: AngusD
 */

#include "HAL_adc.h"




// FUNCTIONS-----------------------------------------------------------------------------------------
/**********************************************************
 * 				ADC INITIALISATION
 * enables APB2 clock for adc 1 or 2 or both
 * 12 bit resolution so o 0 - 4095
 *
 *
 *
 **********************************************************/
void adc_init(ADC_TYPE adc_config)
{
	// initalise adc clocks on APB2 bus
	if (adc_config.adc_number == ADC_1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;


		// initialise adc prescalers
		if (adc_config.prescaler == TWO)
		{
			RCC->CFGR |= RCC_CFGR_ADCPRE_DIV2;
		}

		if (adc_config.prescaler == FOUR)
		{
			RCC->CFGR |= RCC_CFGR_ADCPRE_DIV4;
		}

		if (adc_config.prescaler == SIX)
		{
			RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;
		}

		if (adc_config.prescaler == EIGHT)
		{
			RCC->CFGR |= RCC_CFGR_ADCPRE_DIV8;
		}


		switch(adc_config.channel)
		{
		case ADC_CHANNEL0:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL1:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL2:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL3:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL4:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL5:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL6:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL7:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL8:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL9:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;
		} // end switch
	} // end adc 1

	if (adc_config.adc_number == ADC_2)
	{
		RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;

		// initialise adc prescalers
		if (adc_config.prescaler == TWO)
		{
			RCC->CFGR |= RCC_CFGR_ADCPRE_DIV2;
		}

		if (adc_config.prescaler == FOUR)
		{
			RCC->CFGR |= RCC_CFGR_ADCPRE_DIV4;
		}

		if (adc_config.prescaler == SIX)
		{
			RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;
		}

		if (adc_config.prescaler == EIGHT)
		{
			RCC->CFGR |= RCC_CFGR_ADCPRE_DIV8;
		}


		switch(adc_config.channel)
		{
		case ADC_CHANNEL0:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL1:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL2:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL3:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL4:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL5:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL6:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL7:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL8:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;

		case ADC_CHANNEL9:
			adc_get_samples(adc_config);
			adc_get_sequence(adc_config);
		break;
		} // end switch
	}// end adc 2

	ADC1->SQR1 |= ((adc_config.conversions) << 20);

} // end adc_init

//----------------------------------------------------------------------------------------------------
/**********************************************************
 * 				    	ADC GET SEQUENCE
 *
 *sets conversion sequence for multiple adc channels
 *
 **********************************************************/

void adc_get_sequence(ADC_TYPE adc_config)
{
	// set sequence
	 //ADC1->SQR3 |= ((adc_config.channel) << (adc_config.sequence));
	if (adc_config.adc_number == ADC_1)
	{
		if ((adc_config.sequence) == FIRST || SECOND || THIRD || FOURTH || FIFTH || SIXTH)
		{
			ADC1->SQR3 |= ((adc_config.channel) << (adc_config.sequence));
		}
		if ((adc_config.sequence) == SEVENTH || EIGHTH || NINETH || TENTH)
		{
			ADC1->SQR2 |= ((adc_config.channel) << (adc_config.sequence));
		}
	}

	if (adc_config.adc_number == ADC_2)
	{
		if ((adc_config.sequence) == FIRST || SECOND || THIRD || FOURTH || FIFTH || SIXTH)
		{
			ADC2->SQR3 |= ((adc_config.channel) << (adc_config.sequence));
		}
		if ((adc_config.sequence) == SEVENTH || EIGHTH || NINETH || TENTH)
		{
			ADC2->SQR2 |= ((adc_config.channel) << (adc_config.sequence));
		}
	}
}



//----------------------------------------------------------------------------------------------------
/**********************************************************
 * 				    	ADC GET SAMPLES
 *
 *sets the conversion rate for each adc channel
sets
000: 1.5 cycles 	1
001: 7.5 cycles 	2
010: 13.5 cycles	3
011: 28.5 cycles	4
100: 41.5 cycles	5
101: 55.5 cycles	6
110: 71.5 cycles	7
111: 239.5 cycles	8
 *
 **********************************************************/

void adc_get_samples(ADC_TYPE adc_config)
{
	if (adc_config.adc_number == ADC_1)
	{
		// set the sample rate acording to SMPR2 register for channels < 9
		if (adc_config.channel <= 9)
		{
			ADC1->SMPR2 |= ((adc_config.sample_rate) << (adc_config.channel));
		}

		// set the sample rate acording to SMPR2 register for channels < 9

		if (adc_config.channel > 9)
		{
			ADC1->SMPR1 |= ((adc_config.sample_rate) << (adc_config.channel));
		}
	}

	if (adc_config.adc_number == ADC_2)
	{
		// set the sample rate acording to SMPR2 register for channels < 9
		if (adc_config.channel <= 9)
		{
			ADC2->SMPR2 |= ((adc_config.sample_rate) << (adc_config.channel));
		}

		// set the sample rate acording to SMPR2 register for channels < 9

		if (adc_config.channel > 9)
		{
			ADC2->SMPR1 |= ((adc_config.sample_rate) << (adc_config.channel));
		}
	}

}



//----------------------------------------------------------------------------------------------------
/**********************************************************
 * 				    	ADC GET NO. CONVERSIONS
 *
 *
 *
 **********************************************************/

void adc_get_conversions(ADC_TYPE adc_config)
{
	if (adc_config.adc_number == ADC_1)
	{		ADC1->SQR1 |= ((adc_config.conversions) << 20);
	}
	if (adc_config.adc_number == ADC_2)
	{		ADC2->SQR1 |= ((adc_config.conversions) << 20);
	}
}



//----------------------------------------------------------------------------------------------------
/**********************************************************
 * 				    	ADC START CONTINUOUS
 *
 *
 *
 **********************************************************/

void adc_start_cont(ADC_TYPE adc_config)
{





}


//----------------------------------------------------------------------------------------------------
/**********************************************************
 * 				    	ADC START SCAN
 *
 *
 *
 **********************************************************/

uint32_t* adc_start_scan(uint32_t conversions)
{
	//uint16_t adc_start_scan(ADC_TYPE adc_config) // 16 bit function name
	static uint32_t adc_vals[10];
	//uint16_t adc_vals[(adc_config.conversions + 1)];

	RCC->AHBENR |= RCC_AHBENR_DMA1EN; // set clock for dma on ahb bus

	// enable adc in scan mode
	ADC1->CR1 |= ADC_CR1_SCAN;
	ADC1->CR2 |= ADC_CR2_DMA;

	DMA1_Channel1 -> CPAR = (uint32_t)(&(ADC1->DR)); // get data from adc 1
	DMA1_Channel1 -> CMAR = (uint32_t)adc_vals; // store value in samples
	DMA1_Channel1 -> CNDTR = conversions + 1;
	// 16 bit data size
	//DMA1_Channel1 -> CCR |= DMA_CCR_CIRC | DMA_CCR_MINC |  DMA_CCR_PSIZE_0 |  DMA_CCR_MSIZE_0;
	// 32 bit data size
	DMA1_Channel1 -> CCR |= DMA_CCR_CIRC | DMA_CCR_MINC |  DMA_CCR_PSIZE_0 |  DMA_CCR_PSIZE_1 |  DMA_CCR_MSIZE_1; // set mode to circular and  store data in memory
	DMA1_Channel1 -> CCR |= DMA_CCR_EN;

	// enable the adc and set to continuous mode
	ADC1->CR2 |= ADC_CR2_ADON | ADC_CR2_CONT;


	HAL_Delay(1);

	// turn on a second time to actually turn on
	ADC1->CR2 |= ADC_CR2_ADON;
	// run the calibration
	ADC1->CR2 |= ADC_CR2_CAL;
	HAL_Delay(2);

	return adc_vals;
}







// for continouous mode
/*
void ADC1_2_IRQHandler(void)
{
	//check if we are here because of end of conversion flag is set
	// the end of conversion flg is cleared by reading the data register (DA)
	if(ADC1->SR & ADC_SR_EOC)
	{
		val = ADC1->DR;
	}
}
*/


// for scan mode

/*
// samples[my_adc.conversions + 1] = adc_start_scan(my_adc);
// enable adc in scan mode
ADC1->CR1 |= ADC_CR1_SCAN;
ADC1->CR2 |= ADC_CR2_DMA;

// dma settings
DMA1_Channel1 -> CPAR = (uint32_t)(&(ADC1->DR)); // get data from adc 1
DMA1_Channel1 -> CMAR = (uint32_t)samples; // stor value in samples
DMA1_Channel1 -> CNDTR = 3;
DMA1_Channel1 -> CCR |= DMA_CCR_CIRC | DMA_CCR_MINC |  DMA_CCR_PSIZE_0 |  DMA_CCR_MSIZE_0;
DMA1_Channel1 -> CCR |= DMA_CCR_EN;



// enable the adc and set to continuous mode
ADC1->CR2 |= ADC_CR2_ADON | ADC_CR2_CONT;


//HAL_Delay(1);

// turn on a second time to actually turn on
ADC1->CR2 |= ADC_CR2_ADON;
//HAL_Delay(1);
// run the calibration
ADC1->CR2 |= ADC_CR2_CAL;
//HAL_Delay(2);



 */
