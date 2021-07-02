/*
 * clock.c
 *
 *  Created on: 11 May 2021
 *      Author: AngusD
 */

#include "clock.h"

// FUNCTIONS-----------------------------------------------------------------------------------------

// set clock to 72MHz big boy speeds
void makeItGoFast(void)
{
 //turn on external crystal
 RCC->CR |= RCC_CR_HSEON;

 //wait for HSE crystal be stable
 //there are better ways to handle this
 while(!(RCC->CR & RCC_CR_HSERDY));

 //activate prefetch buffer but it should already be on
 FLASH->ACR |= FLASH_ACR_PRFTBE;

 // Flash 2 wait state
 FLASH->ACR &= ~(FLASH_ACR_LATENCY);  //reset just to be sure
 FLASH->ACR |= (uint32_t)0x1;


 //configure RCC and PLL settings while PLL is off
 RCC->CFGR &= ~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE |  RCC_CFGR_PLLMULL);  //reset

 RCC->CFGR &= ~(RCC_CFGR_PLLXTPRE); //PLLXTPRE bit set to 0
 RCC->CFGR |= RCC_CFGR_PLLSRC;      //pll source
 RCC->CFGR |= RCC_CFGR_PLLMULL9;    //pll miultiplier
 RCC->CFGR |= RCC_CFGR_HPRE_DIV1;   //AHB prescaler
 RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;  //APB1 presacaler
 RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;  //APB2 prescaler


 //turn on PLL
 RCC->CR |= RCC_CR_PLLON;
 while (!(RCC->CR & RCC_CR_PLLRDY));

 //set pll as clock source
 RCC->CFGR &= ~(RCC_CFGR_SW);  //reset just in case
 RCC->CFGR |= RCC_CFGR_SW_PLL;
 while (!(RCC->CFGR & RCC_CFGR_SWS_PLL));

 SystemCoreClockUpdate();
}
// ------------------------------------------------------------------------------------------------



