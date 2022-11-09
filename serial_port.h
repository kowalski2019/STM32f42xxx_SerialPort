/**
  ******************************************************************************
  * @file    	serial_port.h
  * @author		Claude Stephane M. Kouame
  * @version 	V1.0
  * @date		15.07.2021
  * @brief  	Module for using the UART/USART on the waveshare-board.
  ******************************************************************************
*/

#ifndef SERIAL_PORT_SERIAL_PORT_H_
#define SERIAL_PORT_SERIAL_PORT_H_

#include "stm32f4xx.h"
#include <stdint.h>

/* Mapping of LED gpio-port and -pins. */
#define UART_TX_PIN GPIO_PIN_9
#define UART_RX_PIN GPIO_PIN_10


/* --- Public functions (prototypes) */
void SERIAL_PORT_Init(void);
void serial_port_println(char *data);
void serial_port_print(char *data);
void serial_port_write_int(int32_t num);
void test_serial_port(void);

#endif /* SERIAL_PORT_SERIAL_PORT_H_ */
