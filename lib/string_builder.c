/**
 ******************************************************************************
 * @file    	string_builder.c
 * @author		Claude Stephane M. Kouame; claude.kouame@csmk59.de
 * @version 	V1.0
 * @date		2021.11.2
 * @brief  	Module for using string manipulation.
 ******************************************************************************
 */

#include "string_builder.h"

string_builder_t str_builder;

void string_builder_init(void)
{
	clear();
	str_builder.size = 0;
	str_builder.res_size = 0;
	str_builder.str = (char *)malloc(sizeof(char) * STR_DEFAULT_SIZE);
	str_builder.capacity = STR_DEFAULT_SIZE;
	str_builder.prepend_char = &prepend_char;
	str_builder.append_char = &append_char;
	str_builder.append_str = &append_str;
	str_builder.char_at = &char_at;
	str_builder.clear = &clear;
	str_builder.clear_res = &clear_res;
	str_builder.int_to_string = &int_to_string;
}

void prepend_char(char c)
{
	int i = str_builder.res_size;
	while (i > 0)
	{
		*(str_builder.res + i) = *(str_builder.res + (i - 1));
		i -= 1;
	}
	*(str_builder.res) = c;
	// update size
	str_builder.res_size += 1;
}

void append_char(char c)
{

	if (str_builder.size + 1 >= str_builder.capacity)
	{
		char *to_free = str_builder.str;
		// increase str capacity
		uint64_t new_capacity = str_builder.capacity * str_builder.capacity;
		char *new_str = (char *)malloc(sizeof(char) * new_capacity);
		// TODO check malloc result!
		for (int i = 0; i < str_builder.size; i++)
		{
			new_str[i] = str_builder.str[i];
		}
		str_builder.str = new_str;
		str_builder.capacity = new_capacity;
		free(to_free);
	}
	// append char
	*(str_builder.str + str_builder.size) = c;
	*(str_builder.str + (str_builder.size + 1)) = '\0';
	// update size
	str_builder.size += 1;
}

void append_str(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		str_builder.append_char(*(str + i++));
	}
}

char char_at(uint16_t index)
{
	if (index < str_builder.size && index > -1)
	{
		return *(str_builder.str + index);
	}
	return '\0';
}

char digit_to_char(uint32_t n)
{
	return (char)('0' + n);
}

void int_to_string(int32_t n)
{
	str_builder.clear_res();
	uint8_t neg_flag = 0;
	if (n < 0)
	{
		neg_flag = 1;
		n = n * -1;
	}
	else if (n == 0)
	{
		str_builder.prepend_char(digit_to_char(n));
	}
	else
	{
		while (n != 0)
		{

			uint32_t num = n % 10;
			str_builder.prepend_char(digit_to_char(num));
			n /= 10;
		}
	}
	if (neg_flag)
		str_builder.prepend_char('-');
}

void clear(void)
{
	for (int i = 0; i < str_builder.size; i++)
		*(str_builder.str + i) = '\0';
	str_builder.size = 0;
}
void clear_res(void)
{
	str_builder.res_size = 0;
	for (int i = 0; i < RES_DEFAUT_SIZE; i++)
		*(str_builder.res + i) = '\0';
}
