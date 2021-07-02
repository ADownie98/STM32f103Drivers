/*
 * HAL_UART.c
 *
 *  Created on: 27 Apr 2021
 *      Author: AngusD
 */
#include "HAL_UART.h"


void USART_init (uint32_t usart, uint32_t baud_rate)
{
	if (usart == UART1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

		switch(baud_rate)
		{
		case BAUD2400:
		  USART1->BRR = 0x7530;
		  break;
		case BAUD9600:
		  USART1->BRR = 0x1D4C;
		  break;
		case BAUD19200:
		  USART1->BRR = 0x0EA6;
		  break;
		case BAUD57600:
	      USART1->BRR = 0x04E2;
		  break;
		case BAUD115200:
		  USART1->BRR = 0x0271;
		  break;
		case BAUD230400:
		  USART1->BRR = 0x0138;
		  break;
		case BAUD460800:
		  USART1->BRR = 0x009C;
		  break;
		case BAUD921600:
		  USART1->BRR = 0x004E;
		  break;
		case BAUD2250000:
		  USART1->BRR = 0x0020; // non functional
		  break;
		case BAUD4500000:
		  USART1->BRR = 0x0010; // non functional
		  break;
		}

		USART1->CR1 |= USART_CR1_RE | USART_CR1_TE | USART_CR1_UE;
	}

	if (usart == UART2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

		// set baud rate in BRR
		switch(baud_rate)
		{
		case BAUD2400:
		  USART2->BRR = 0x7530;
		  break;
		case BAUD9600:
		  USART2->BRR = 0x1D4C;
		  break;
		case BAUD19200:
		  USART2->BRR = 0x0EA6;
		  break;
		case BAUD57600:
	      USART2->BRR = 0x04E2;
		  break;
		case BAUD115200:
		  USART2->BRR = 0x0271;
		  break;
		case BAUD230400:
		  USART2->BRR = 0x0138;
		  break;
		case BAUD460800:
		  USART2->BRR = 0x009C;
		  break;
		case BAUD921600:
		  USART2->BRR = 0x004E;
		  break;
		case BAUD2250000:
		  USART2->BRR = 0x0020;
		  break;
		case BAUD4500000:
		  USART2->BRR = 0x0010;
		  break;
		}

		/// start uart in 8 bit mode, 1 stop bit, 0 parity bit
		USART2->CR1 |= USART_CR1_RE | USART_CR1_TE | USART_CR1_UE;
	}



}

//-------------------------------------------------------------------------

void UART1_transmit (char *message)
{
	USART1->DR = message;  //send message out
    while (!(USART1->SR & USART_SR_TC)); // wait for transmission to finish
}

//-------------------------------------------------------------------------

void UART2_transmit (char *message)
{
	USART2->DR = message;  //send message out
    while (!(USART2->SR & USART_SR_TC)); // wait for transmission to finish
}

//-------------------------------------------------------------------------

void PutChar(USART_TypeDef* USARTx, uint8_t ch)
{
  while(!(USARTx->SR & USART_SR_TXE));
  USARTx->DR = ch;
}

//-------------------------------------------------------------------------

void PutString(USART_TypeDef* USARTx, uint8_t * str)
{
  while(*str != 0)
  {
    PutChar(USARTx, *str);
    str++;
  }
}

//-------------------------------------------------------------------------

void PutNumber(USART_TypeDef* USARTx, uint32_t x)
{
  char value[10]; //a temp array to hold results of conversion
  int i = 0; //loop index

  do
  {
    value[i++] = (char)(x % 10) + '0'; //convert integer to character
    x /= 10;
  } while(x);

  while(i) //send data
  {
    PutChar(USARTx, value[--i]);
  }
}
//-------------------------------------------------------------------------

void UART_Carriage_Return(void)
{
	PutChar(USART1, '\r');
	PutChar(USART1, '\n');
}



/*

 */







/*
 /-----------------------| UART CODE |------------------------------------------
        //USART1 / GPIOA clock enable
 RCC->APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN;

 //remaping if needed
 //AFIO->MAPR |= AFIO_MAPR_USART1_REMAP ; //remap RX TX to PB7 PB6

 //pin configurations: PA9- TX is set to ALternate-push-pull and 50MHz
 GPIOA->CRH |= GPIO_CRH_MODE9 | GPIO_CRH_CNF9_1;
 GPIOA->CRH &= ~(GPIO_CRH_CNF9_0);


  // PIN PA10 is the RX pin and it has to be set to input &FLOATING
   //this is the rest value of the pin so we dont do anything to it



 //USART DIV value
 USART1->BRR = 0x0100; //for 72MHZ on APB2 bus
 //USART1->BRR = 0x0EA6; //for 36MHZ on APB2 bus


// for when using interrupts ( disbale if polling)
 //enable RXNE and TXE interrupts on USART SIDE
 USART1->CR1 |= USART_CR1_RXNEIE | USART_CR1_TXEIE;

 //----------  RX enable        TX enable     UART enable
 USART1->CR1 |= USART_CR1_RE | USART_CR1_TE | USART_CR1_UE;



 //ENABLE interrupt for USART1 on NVIC side
 //NVIC_EnableIRQ(USART1_IRQn);



 // poll UART status register in while(1) loop

 if (USART1->SR & USART_SR_RXNE) //if RX is not empty
	    {
	     char temp = USART1->DR; //fetch the data received
	     USART1->DR = temp;  //send it back out
	     while (!(USART1->SR & USART_SR_TC)); //wait for TX to be complete
	    }





 // interrupt handler for when using interrupts
 void USART1_IRQHandler(void)
 {

  //check if we are here because of RXNE interrupt
  if (USART1->SR & USART_SR_RXNE) //if RX is not empty
  {
   char temp = USART1->DR; //fetch the data received
   USART1->DR = temp;  //send it back out
   while (!(USART1->SR & USART_SR_TC));
  }

  //check if we are here because of TXEIE interrupt
  if (USART1->SR & USART_SR_TXE) //if RX is not empty
  {
   //handle transmit completion here
  }

 }
 */
