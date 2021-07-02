/*
 * HAL_UART.h
 *
 *  Created on: 27 Apr 2021
 *      Author: AngusD
 */

#ifndef SRC_HAL_UART_H_
#define SRC_HAL_UART_H_

#include"stm32f1xx.h" // CUBEIDE
//#include"stm32f10x.h" // KEIL

// select UART/USART
#define UART1					((uint32_t) 0x01)
#define UART2					((uint32_t) 0x02)

// baud rate select
#define BAUD2400				((uint32_t) 0x00)
#define BAUD9600				((uint32_t) 0x01)
#define BAUD19200				((uint32_t) 0x02)
#define BAUD57600				((uint32_t) 0x03)
#define BAUD115200				((uint32_t) 0x04)
#define BAUD230400				((uint32_t) 0x05)
#define BAUD460800				((uint32_t) 0x06)
#define BAUD921600				((uint32_t) 0x07)
#define BAUD2250000				((uint32_t) 0x08)
#define BAUD4500000				((uint32_t) 0x09)


void USART_init (uint32_t usart, uint32_t baud_rate);



// 					function prototypes
//--------------------------------------------------------
//                    UART/USART CONFIGURATION
void USART_init (uint32_t usart, uint32_t baud_rate);
//
//--------------------------------------------------------
//                      FUNCTIONS
//
void PutChar(USART_TypeDef* USARTx, uint8_t ch);
void PutString(USART_TypeDef* USARTx, uint8_t * str);
void PutNumber(USART_TypeDef* USARTx, uint32_t x);
void UART_Carriage_Return(void);
//
//--------------------------------------------------------
//                     USER FUNCTIONS
void UART1_transmit (char *message);
void UART2_transmit (char *message);
//
//--------------------------------------------------------
#endif /* SRC_HAL_UART_H_ */
