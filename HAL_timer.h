/*
 * HAL_timer.h
 *
 *  Created on: Apr 12, 2021
 *      Author: AngusD
 */

#ifndef SRC_HAL_TIMER_H_
#define SRC_HAL_TIMER_H_

#include"stm32f1xx.h" // CUBEIDE
//#include"stm32f10x.h" // KEIL

// TIMER ENABLES
#define disable 			0
#define enable 				1

// COUNTER DIRECTIONS
#define UP					((uint32_t) 0x00)
#define DOWN				((uint32_t) 0x01)

// TIMERS
#define TIMER1				((uint32_t) 0x01)
#define TIMER2				((uint32_t) 0x02)
#define TIMER3				((uint32_t) 0x03)
#define TIMER4				((uint32_t) 0x04)

// CHANNELS
#define CHANNEL1			((uint32_t) 0x01)
#define CHANNEL2			((uint32_t) 0x02)
#define CHANNEL3			((uint32_t) 0x03)
#define CHANNEL4			((uint32_t) 0x04)

// TIMER ALIGNMENTS
#define EDGE_ALIGNED		((uint32_t) 0x00)
#define CENTRE_ALIGNED1		((uint32_t) 0x01)
#define CENTRE_ALIGNED2		((uint32_t) 0x02)
#define CENTRE_ALIGNED3		((uint32_t) 0x03)

// TIMER MODES
#define INPUT_CAPTURE
#define OUTPUT_COMPARE
#define PWM
#define ONE_PULSE


// initialisation structure
typedef struct
{
    uint32_t    timer;

    uint32_t    alignment;

    uint32_t    direction;

    uint32_t    on_off;

    uint32_t    prescaler;

    uint32_t    top;

    uint32_t    duty;

    uint32_t    channel;

} GP_TIMER_TYPE;






// 						function prototypes
//--------------------------------------------------------
//                      TIMER CONFIGURATION
void timer_init(GP_TIMER_TYPE timer_type); // initialises timer clock
//
//--------------------------------------------------------
//                      TIMER FUNCTIONS
void timer_up_down(GP_TIMER_TYPE timer_type); // sets timer to up/down counter
void pulse_width_modulation (GP_TIMER_TYPE timer_type); // sets timer to pwm mode
//
//--------------------------------------------------------

/*********************************************************
 *
 * please see initialisation structure for timer parameters required to function
 *
 *
 *					DUMMY CODE
 *
 	GP_TIMER_TYPE myTIMER;

 	myTIMER.timer = TIMER4;
 	myTIMER.channel = CHANNEL4;
 	myTIMER.alignment = EDGE_ALIGNED;
	myTIMER.direction = UP;
	myTIMER.on_off = enable;
	myTIMER.prescaler = 72;
	myTIMER.top = 1000;
	myTIMER.duty = 50;

	void config_timer(myTIMER);

	pulse_width_modulation(myTIMER);
 *
 *
 *
 *
 **********************************************************/


#endif /* SRC_HAL_TIMER_H_ */
