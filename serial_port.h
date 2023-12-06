/**
 ******************************************************************************
 * @file    	serial_port.h
 * @author		Claude Stephane M. Kouame; claude.kouame@csmk59.de
 * @version 	V1.0
 * @date	    2021.7.15
 * @brief  	    Module for using the UART/USART on the waveshare-board.
 ******************************************************************************
 */

#ifndef SERIAL_PORT_SERIAL_PORT_H_
#define SERIAL_PORT_SERIAL_PORT_H_

#include "stm32f4xx.h"
#include <stdint.h>

/* Mapping of UART TX and RX gpio-port and -pins. */
#define UART_TX_PIN GPIO_PIN_9
#define UART_RX_PIN GPIO_PIN_10

/* --- Public functions (prototypes) */
void Serial_Port_Init(void);
void Serial_Port_Println(char *data);
void Serial_Port_Print(char *data);
void Serial_Port_Write_Int(int32_t num);
void Serial_Port_Test(void);

#endif /* SERIAL_PORT_SERIAL_PORT_H_ */
