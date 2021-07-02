/*
 * HAL_timer.c
 *
 *  Created on: Apr 12, 2021
 *      Author: AngusD
 */

#include "HAL_timer.h"



// FUNCTIONS-----------------------------------------------------------------------------------------

/*********************************************************
 * 				TIMER INITIALISATION
 *
 *
 **********************************************************/
void timer_init(GP_TIMER_TYPE timer_type)
{
	if (timer_type.timer == TIMER1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	if (timer_type.timer == TIMER2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}

	if (timer_type.timer == TIMER3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}

	if (timer_type.timer == TIMER4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}
}

//---------------------------------------------------------------------------------------------------
/****************************************************************************************************
 * 					TIMER COUNTER
 * this function requires: timer number, alignment, direction, top and prescaler.
 *
 * in this function the timer counts up to the specified top value with a prescaler value
 * the combination of these determines the frequency of the timer. both these numbers
 * can range from 0-65535
 *
 *
 *  where:
 *
 *  peripheral clock
 * ------------------   = timer frequency
 *  prescaler * top
 *
 * 		 or,
 *
 *  peripheral clock
 * ------------------
 *     prescaler		= timer frequency
 * ------------------
 * 		  top
 *
 * for each given timer:
 * the top value is fed into the ARR register
 * the prascaler is fed into the PSC register
 *
 ******************************************************************************************************/
void timer_up_down(GP_TIMER_TYPE timer_type)
{
	if (timer_type.timer == TIMER1)
	{
		if((timer_type.alignment == CENTRE_ALIGNED1))
		{
			TIM1->CR1 |= (1<<5);
		}

		if((timer_type.alignment == CENTRE_ALIGNED2))
		{
			TIM1->CR1 |= (1<<6);
		}

		if((timer_type.alignment == CENTRE_ALIGNED3))
		{
			TIM1->CR1 |= (1<<5) | (1<<6);
		}

		//peripheral clock / prescaler / arr = timer freqency
		//peripheral clock / ( prescaler*arr) = timer frequency
		TIM1->PSC = timer_type.prescaler; // set prescaler
		TIM1->ARR = timer_type.top;  // set auto reload ( what the timer counts to)

		if ((timer_type.on_off == enable))
		{
			TIM1->CR1 |= TIM_CR1_CEN; // enables the clock and starts count
		}

	} // end timer 2

	if (timer_type.timer == TIMER2)
	{
		if((timer_type.alignment == CENTRE_ALIGNED1))
		{
			TIM2->CR1 |= (1<<5);
		}

		if((timer_type.alignment == CENTRE_ALIGNED2))
		{
			TIM2->CR1 |= (1<<6);
		}

		if((timer_type.alignment == CENTRE_ALIGNED3))
		{
			TIM2->CR1 |= (1<<5) | (1<<6);
		}

		//peripheral clock / prescaler / arr = timer freqency
		//peripheral clock / ( prescaler*arr) = timer frequency
		TIM2->PSC = timer_type.prescaler; // set prescaler
		TIM2->ARR = timer_type.top;  // set auto reload ( what the timer counts to)

		if ((timer_type.on_off == enable))
		{
			TIM2->CR1 |= TIM_CR1_CEN; // enables the clock and starts count
		}

	} // end timer 2

	if (timer_type.timer == TIMER3)
	{
		if((timer_type.alignment == CENTRE_ALIGNED1))
		{
			TIM3->CR1 |= (1<<5);
		}

		if((timer_type.alignment == CENTRE_ALIGNED2))
		{
			TIM3->CR1 |= (1<<6);
		}

		if((timer_type.alignment == CENTRE_ALIGNED3))
		{
			TIM3->CR1 |= (1<<5) | (1<<6);
		}

		//peripheral clock / prescaler / arr = timer freqency
		//peripheral clock / ( prescaler*arr) = timer frequency
		TIM3->PSC = timer_type.prescaler; // set prescaler
		TIM3->ARR = timer_type.top;  // set auto reload ( what the timer counts to)

		if ((timer_type.on_off == enable))
		{
			TIM3->CR1 |= TIM_CR1_CEN; // enables the clock and starts count
		}

	} // end timer 3

	if (timer_type.timer == TIMER4)
	{
		if((timer_type.alignment == CENTRE_ALIGNED1))
		{
			TIM4->CR1 |= (1<<5);
		}

		if((timer_type.alignment == CENTRE_ALIGNED2))
		{
			TIM4->CR1 |= (1<<6);
		}

		if((timer_type.alignment == CENTRE_ALIGNED3))
		{
			TIM4->CR1 |= (1<<5) | (1<<6);
		}

		//peripheral clock / prescaler / arr = timer freqency
		//peripheral clock / ( prescaler*arr) = timer frequency
		TIM4->PSC = timer_type.prescaler; // set prescaler
		TIM4->ARR = timer_type.top;  // set auto reload ( what the timer counts to)

		if ((timer_type.on_off == enable))
		{
			TIM4->CR1 |= TIM_CR1_CEN; // enables the clock and starts count
		}
	} // end timer 4
} // end timer up down

//---------------------------------------------------------------------------------------------------
/****************************************************************************************************
 * 					TIMER PWM
 * this function requires: timer number, alignment, direction, top, prescaler, channel, and duty cycle.
 *
 *
 *  peripheral clock
 *  -----------------
 *  prescaler (PSC)   = pwm frequency
 *  -----------------
 *  	top (ARR)
 *
 *  	or,
 *
 *  peripheral clock
 *  ----------------- = pwm frequency
 *  prescaler * top
 *
 *  	and,
 *
 *  	 CCR4
 *  ----------------- = pwm duty cycle
 *     top (ARR)
 *
 * for PWM output it is important to set up the poir and pin using HAL_GPIO
 * the pin needs to be set to alternate function output with a speed of 50mhz
 *
 *
 	 	 	 	 	 	 DUMMY CODE

  GPIO_TYPE myGPIO3; // decalre name for gpio structure

  // fill structure with all relevent information, port, pin, seed etc
  myGPIO3.port = PORTB;
  myGPIO3.pin = 9;
  myGPIO3.mode = OUTPUT_MODE;
  myGPIO3.mode_type = OUTPUT_ALT_FUNCTION;
  myGPIO3.speed = SPEED_50MHZ;

  // pass structure to gpio_init function to initialise the port and clock
  gpio_init(myGPIO3);

 *
 *
 *
 *
 ****************************************************************************************************/
void pulse_width_modulation (GP_TIMER_TYPE timer_type)
{
	if (timer_type.timer == TIMER1)
	{

		if((timer_type.alignment == CENTRE_ALIGNED1))
		{
			TIM1->CR1 |= (1<<5);
		}

		if((timer_type.alignment == CENTRE_ALIGNED2))
		{
			TIM1->CR1 |= (1<<6);
		}

		if((timer_type.alignment == CENTRE_ALIGNED3))
		{
			TIM1->CR1 |= (1<<5) | (1<<6);
		}

		// channel select
		switch(timer_type.channel)
		{
			  case CHANNEL1:
				TIM1->CCER |= TIM_CCER_CC1E;
				TIM1->CR1 |= TIM_CR1_ARPE;
				TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE;
				TIM1->PSC = timer_type.prescaler; // set prescaler
				TIM1->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM1->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM1->EGR |= TIM_EGR_UG;
			    break;

			  case CHANNEL2:
				TIM1->CCER |= TIM_CCER_CC2E;
				TIM1->CR1 |= TIM_CR1_ARPE;
				TIM1->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2PE;
				TIM1->PSC = timer_type.prescaler; // set prescaler
				TIM1->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM1->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM1->EGR |= TIM_EGR_UG;
			    break;

			  case CHANNEL3:
				TIM1->CCER |= TIM_CCER_CC3E;
				TIM1->CR1 |= TIM_CR1_ARPE;
				TIM1->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3PE;
				TIM1->PSC = timer_type.prescaler; // set prescaler
				TIM1->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM1->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM1->EGR |= TIM_EGR_UG;
			    break;

			  case CHANNEL4:
				TIM1->CCER |= TIM_CCER_CC4E;
				TIM1->CR1 |= TIM_CR1_ARPE;
				TIM1->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4PE;
				TIM1->PSC = timer_type.prescaler; // set prescaler
				TIM1->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM1->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM1->EGR |= TIM_EGR_UG;
			    break;
		 } // end switch

		if ((timer_type.on_off == enable))
		{
			TIM1->CR1 |= TIM_CR1_CEN;
		}
	} // end if timer 1

	if (timer_type.timer == TIMER2)
	{

		if((timer_type.alignment == CENTRE_ALIGNED1))
		{
			TIM2->CR1 |= (1<<5);
		}

		if((timer_type.alignment == CENTRE_ALIGNED2))
		{
			TIM2->CR1 |= (1<<6);
		}

		if((timer_type.alignment == CENTRE_ALIGNED3))
		{
			TIM2->CR1 |= (1<<5) | (1<<6);
		}

		// channel select
		switch(timer_type.channel)
		{
			  case CHANNEL1:
				TIM2->CCER |= TIM_CCER_CC1E;
				TIM2->CR1 |= TIM_CR1_ARPE;
				TIM2->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE;
				TIM2->PSC = timer_type.prescaler; // set prescaler
				TIM2->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM2->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM2->EGR |= TIM_EGR_UG;
			    break;

			  case CHANNEL2:
				TIM2->CCER |= TIM_CCER_CC2E;
				TIM2->CR1 |= TIM_CR1_ARPE;
				TIM2->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2PE;
				TIM2->PSC = timer_type.prescaler; // set prescaler
				TIM2->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM2->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM2->EGR |= TIM_EGR_UG;
			    break;

			  case CHANNEL3:
				TIM2->CCER |= TIM_CCER_CC3E;
				TIM2->CR1 |= TIM_CR1_ARPE;
				TIM2->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3PE;
				TIM2->PSC = timer_type.prescaler; // set prescaler
				TIM2->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM2->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM2->EGR |= TIM_EGR_UG;
			    break;

			  case CHANNEL4:
				TIM2->CCER |= TIM_CCER_CC4E;
				TIM2->CR1 |= TIM_CR1_ARPE;
				TIM2->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4PE;
				TIM2->PSC = timer_type.prescaler; // set prescaler
				TIM2->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM2->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM2->EGR |= TIM_EGR_UG;
			    break;
		 } // end switch

		if ((timer_type.on_off == enable))
		{
			TIM2->CR1 |= TIM_CR1_CEN;
		}
	} // end if timer 2


	if (timer_type.timer == TIMER3)
	{

		if((timer_type.alignment == CENTRE_ALIGNED1))
		{
			TIM3->CR1 |= (1<<5);
		}

		if((timer_type.alignment == CENTRE_ALIGNED2))
		{
			TIM3->CR1 |= (1<<6);
		}

		if((timer_type.alignment == CENTRE_ALIGNED3))
		{
			TIM3->CR1 |= (1<<5) | (1<<6);
		}

		// channel select
		switch(timer_type.channel)
		{
			  case CHANNEL1:
				TIM3->CCER |= TIM_CCER_CC1E;
				TIM3->CR1 |= TIM_CR1_ARPE;
				TIM3->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE;
				TIM3->PSC = timer_type.prescaler; // set prescaler
				TIM3->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM3->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM3->EGR |= TIM_EGR_UG;
			    break;

			  case CHANNEL2:
				TIM3->CCER |= TIM_CCER_CC2E;
				TIM3->CR1 |= TIM_CR1_ARPE;
				TIM3->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2PE;
				TIM3->PSC = timer_type.prescaler; // set prescaler
				TIM3->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM3->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM3->EGR |= TIM_EGR_UG;
			    break;

			  case CHANNEL3:
				TIM3->CCER |= TIM_CCER_CC3E;
				TIM3->CR1 |= TIM_CR1_ARPE;
				TIM3->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3PE;
				TIM3->PSC = timer_type.prescaler; // set prescaler
				TIM3->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM3->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM3->EGR |= TIM_EGR_UG;
			    break;

			  case CHANNEL4:
				TIM3->CCER |= TIM_CCER_CC4E;
				TIM3->CR1 |= TIM_CR1_ARPE;
				TIM3->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4PE;
				TIM3->PSC = timer_type.prescaler; // set prescaler
				TIM3->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM3->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM3->EGR |= TIM_EGR_UG;
			    break;
		 } // end switch

		if ((timer_type.on_off == enable))
		{
			TIM3->CR1 |= TIM_CR1_CEN;
		}
	} // end if timer 3


	if (timer_type.timer == TIMER4)
	{

		if((timer_type.alignment == CENTRE_ALIGNED1))
		{
			TIM4->CR1 |= (1<<5);
		}

		if((timer_type.alignment == CENTRE_ALIGNED2))
		{
			TIM4->CR1 |= (1<<6);
		}

		if((timer_type.alignment == CENTRE_ALIGNED3))
		{
			TIM4->CR1 |= (1<<5) | (1<<6);
		}

		// channel select
		switch(timer_type.channel)
		{
			  case CHANNEL1:
				TIM4->CCER |= TIM_CCER_CC1E;
				TIM4->CR1 |= TIM_CR1_ARPE;
				TIM4->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE;
				TIM4->PSC = timer_type.prescaler; // set prescaler
				TIM4->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM4->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM4->EGR |= TIM_EGR_UG;
			    break;

			  case CHANNEL2:
				TIM4->CCER |= TIM_CCER_CC2E;
				TIM4->CR1 |= TIM_CR1_ARPE;
				TIM4->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2PE;
				TIM4->PSC = timer_type.prescaler; // set prescaler
				TIM4->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM4->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM4->EGR |= TIM_EGR_UG;
			    break;

			  case CHANNEL3:
				TIM4->CCER |= TIM_CCER_CC3E;
				TIM4 ->CR1 |= TIM_CR1_ARPE;
				TIM4->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3PE;
				TIM4->PSC = timer_type.prescaler; // set prescaler
				TIM4->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM4->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM4->EGR |= TIM_EGR_UG;
			    break;

			  case CHANNEL4:
				TIM4->CCER |= TIM_CCER_CC4E;
				TIM4 ->CR1 |= TIM_CR1_ARPE;
				TIM4->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4PE;
				TIM4->PSC = timer_type.prescaler; // set prescaler
				TIM4->ARR = timer_type.top;  // set auto reload ( what the timer counts to)
				TIM4->CCR4 = (timer_type.top*timer_type.duty)/100;
				TIM4->EGR |= TIM_EGR_UG;
			    break;
		 } // end switch

		if ((timer_type.on_off == enable))
		{
			TIM4->CR1 |= TIM_CR1_CEN;
		}
	} // end if timer 4
} // end pwm

//---------------------------------------------------------------------------------------------------







