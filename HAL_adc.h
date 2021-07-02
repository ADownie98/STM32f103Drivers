/*
 * HAL_adc.h
 *
 *  Created on: Apr 19, 2021
 *      Author: AngusD
 */

#ifndef SRC_HAL_ADC_H_
#define SRC_HAL_ADC_H_

#include"stm32f1xx.h" // CUBEIDE
//#include"stm32f10x.h" // KEIL

// select adc 1 or 2
#define ADC_1					((uint32_t) 0x01)
#define ADC_2					((uint32_t) 0x02)

// adc channels
#define ADC_CHANNEL0			((uint32_t) 0x00)
#define ADC_CHANNEL1			((uint32_t) 0x01)
#define ADC_CHANNEL2			((uint32_t) 0x02)
#define ADC_CHANNEL3			((uint32_t) 0x03)
#define ADC_CHANNEL4			((uint32_t) 0x04)
#define ADC_CHANNEL5			((uint32_t) 0x05)
#define ADC_CHANNEL6			((uint32_t) 0x06)
#define ADC_CHANNEL7			((uint32_t) 0x07)
#define ADC_CHANNEL8			((uint32_t) 0x08)
#define ADC_CHANNEL9			((uint32_t) 0x09)

// adc modes
#define ADC_MODE_CONT		((uint32_t) 0x00)
#define ADC_MODE_SCAN			((uint32_t) 0x01)

// conversion sequence
#define FIRST					((uint32_t) 0x00)
#define SECOND					((uint32_t) 0x05)
#define THIRD					((uint32_t) 0x0A)
#define FOURTH					((uint32_t) 0x0F)
#define FIFTH					((uint32_t) 0x14)
#define SIXTH					((uint32_t) 0x19)
#define SEVENTH					((uint32_t) 0x1E)
#define EIGHTH					((uint32_t) 0x00)
#define NINETH					((uint32_t) 0x05)
#define TENTH   				((uint32_t) 0x0A)

// prescaler and conversions
#define TWO 					((uint32_t) 0x02)
#define FOUR 					((uint32_t) 0x04)
#define SIX 					((uint32_t) 0x06)
#define EIGHT 					((uint32_t) 0x08)

// sampling rate
#define SAMPLE_1				((uint32_t) 0x00)
#define SAMPLE_2				((uint32_t) 0x01)
#define SAMPLE_3				((uint32_t) 0x02)
#define SAMPLE_4				((uint32_t) 0x03)
#define SAMPLE_5				((uint32_t) 0x04)
#define SAMPLE_6				((uint32_t) 0x05)
#define SAMPLE_7				((uint32_t) 0x06)
#define SAMPLE_8				((uint32_t) 0x07)

// number of conversions
#define CONV1					((uint32_t) 0x00)
#define CONV2					((uint32_t) 0x01)
#define CONV3					((uint32_t) 0x02)
#define CONV4					((uint32_t) 0x03)
#define CONV5					((uint32_t) 0x04)
#define CONV6					((uint32_t) 0x05)
#define CONV7					((uint32_t) 0x06)
#define CONV8					((uint32_t) 0x07)
#define CONV9					((uint32_t) 0x08)
#define CONV10					((uint32_t) 0x09)


//configuration structure
typedef struct
{
    uint32_t    adc_number;

    uint32_t    channel;

    uint32_t    prescaler;

    uint32_t    sample_rate;

    uint32_t    mode;

    uint32_t    conversions;

    uint32_t    sequence;

} ADC_TYPE;




// 					function prototypes
//--------------------------------------------------------
//                    ADC CONFIGURATION
void adc_init(ADC_TYPE adc_config);
//
//--------------------------------------------------------
//                    INTERNAL FUNCTIONS
void adc_get_sequence(ADC_TYPE adc_config);
void adc_get_samples(ADC_TYPE adc_config);
void adc_get_conversions(ADC_TYPE adc_config);
//
//--------------------------------------------------------
//                     USER FUNCTIONS
void adc_start_cont(ADC_TYPE adc_config);
uint32_t* adc_start_scan(uint32_t conversions);
//
//--------------------------------------------------------
/*
						DUMMY CODE

// first the initialisation struct must be declared with all parameters filled


// declare a global or local variable which is a pointer to a uint32_t which will contain the information from the adcs


uint32_t *samples;



ADC_TYPE my_adc;


my_adc.adc_number = ADC_1;
my_adc.channel = ADC_CHANNEL7;
my_adc.prescaler = SIX;
my_adc.sample_rate = SAMPLE_6;
my_adc.conversions = CONV3;
my_adc.mode = ADC_MODE_SCAN;
my_adc.sequence = SECOND;


adc_init(my_adc);

// prescaler of 6 is used to keep adc clock below 14MHz
// using adc1 channel 7
// using smaple rate 6, this can be increase up to sample rate 1 which can be found in the get_samples() function

// ensure that the number of conversions and the sequences are correct or else the conversions taking place will be incorrect
// then call adc_start_scan and store the information in the pointer

samples = adc_start_scan(CONV3);



then in the while(1) loop
this samples variable can be indexed as an array or each adc channel in the sequence


if ( samples[0] < 2000)
  {
	  gpio_write(PORTA,0,HIGH);
  }
  if ( samples[0] > 2000)
  {
	  gpio_write(PORTA,0,LOW);

  }


  if ( samples[1] > 2000)
  {
	  gpio_write(PORTC,13,HIGH);
  }
  if (samples[1] < 2000 )
  {
	  gpio_write(PORTC,13,LOW);
  }



  if (samples[2] < 2000 )
  {
	  gpio_write(PORTB,12,HIGH);
  }
 */



#endif /* SRC_HAL_ADC_H_ */
