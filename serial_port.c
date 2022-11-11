
/**
 ******************************************************************************
 * @file    	serial_port.c
 * @author		Claude Stephane M. Kouame; claude.kouame@csmk59.de
 * @version 	V1.0
 * @date		2021.7.15
 * @brief  	Module for using the UART/USART on the waveshare-board.
 ******************************************************************************
 */

/* Includes */

#include "serial_port.h"
#include <string.h>
#include "lib/string_builder.h"

static UART_HandleTypeDef uart1;
static GPIO_InitTypeDef gpio_init_struct;

static void SERIAL_PORT_GPIO_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	gpio_init_struct.Pin = UART_TX_PIN | UART_RX_PIN;
	gpio_init_struct.Mode = GPIO_MODE_AF_PP;
	gpio_init_struct.Pull = GPIO_NOPULL;
	gpio_init_struct.Speed = GPIO_SPEED_HIGH;
	gpio_init_struct.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOA, &gpio_init_struct);
}

static void SERIAL_PORT_UART_Init(void)
{
	__HAL_RCC_USART1_CLK_ENABLE();

	uart1.Instance = USART1;
	uart1.Init.BaudRate = 115200;
	uart1.Init.WordLength = UART_WORDLENGTH_8B;
	uart1.Init.StopBits = UART_STOPBITS_1;
	uart1.Init.Parity = UART_PARITY_NONE;
	uart1.Init.Mode = UART_MODE_TX_RX;
	uart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart1.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init(&uart1);
}

/**
 *
 */
void SERIAL_PORT_Init(void)
{
	SERIAL_PORT_GPIO_Init();
	SERIAL_PORT_UART_Init();
	string_builder_init();
}

/**
 *
 */
void serial_port_println(char *data)
{
	char *next_line = "\n\r";
	HAL_UART_Transmit(&uart1, (uint8_t *)data, strlen(data), HAL_MAX_DELAY);
	HAL_UART_Transmit(&uart1, (uint8_t *)next_line, strlen(next_line), HAL_MAX_DELAY);
}

/**
 *
 */
void serial_port_write_int(int32_t num)
{
	str_builder.int_to_string(num);
	serial_port_print(str_builder.res);
}

void serial_port_print(char *data)
{
	HAL_UART_Transmit(&uart1, (uint8_t *)data, strlen(data), HAL_MAX_DELAY);
}

void test_serial_port(void)
{
	SERIAL_PORT_Init();

	while (1)
	{
		serial_port_print("Hello world");
		serial_port_println("");
		HAL_Delay(1000);
	}
}
