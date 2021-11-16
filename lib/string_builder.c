/*
 * utils.c
 *
 *  Created on: Nov 2, 2021
 *      Author: csmk
 */

#include "string_builder.h"

string_builder_t str_builder;

void string_builder_init(void)
{
	clear();
	str_builder.size = 0;
	str_builder.res_size = 0;
	str_builder.prepend_char = &prepend_char;
	str_builder.append_char = &append_char;
	str_builder.append_str = &append_str;
	str_builder.char_at = &char_at;
	str_builder.clear = &clear;
	str_builder.clear_res = &clear_res;
	str_builder.int_to_string = &int_to_string;
}

void prepend_char(char c) {
	int i = str_builder.res_size;
	while(i > 0) {
		*(str_builder.res + i) = *(str_builder.res + (i - 1));
		i -= 1;
	}
	*(str_builder.res) = c;
	// update size
	str_builder.res_size += 1;
}

void append_char(char c)
{
	char *old_str = str_builder.str;
	char *new_str = (char *)malloc(sizeof(char) * (str_builder.size + 1));
	int i = 0;
	for (;i < str_builder.size; i++) new_str[i] = str_builder.str[i];
	new_str[i++] = c;
	new_str[i] = '\0';
	// update size
	str_builder.size += 1;
	// update str
	str_builder.str = new_str;
	// free old_str
	free(old_str);
}

void append_str(char* str)
{
	for (int i = 0; i < strlen(str); i++) {
		str_builder.append_char(*(str + i));
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

char digit_to_char(uint32_t n) {
	switch(n) {
		case 0: return '0'; break;
		case 1: return '1'; break;
		case 2: return '2'; break;
		case 3: return '3'; break;
		case 4: return '4'; break;
		case 5: return '5'; break;
		case 6: return '6'; break;
		case 7: return '7'; break;
		case 8: return '8'; break;
		case 9: return '9'; break;
		default: return '\0'; break;
	}
}

void int_to_string(int32_t n) {
	str_builder.clear_res();
	uint8_t neg_flag = 0;
	if (n < 0) {
		neg_flag = 1;
	    n = n * -1;
	}
	else if (n == 0) {
		str_builder.prepend_char(digit_to_char(n));
	}
	else {
		while(n != 0) {

		uint32_t num = n % 10;
		str_builder.prepend_char(digit_to_char(num));
		n /= 10;
		}
	}
	if(neg_flag)
		str_builder.prepend_char('-');
}

void clear(void)
{
	str_builder.size = 0;
	str_builder.str = (char *)malloc(sizeof(char) * 0);
	*str_builder.str = '\0';
}
void clear_res(void)
{
	str_builder.res_size = 0;
	for (int i = 0; i < 16; i++) *(str_builder.res + i) = '\0';
}
