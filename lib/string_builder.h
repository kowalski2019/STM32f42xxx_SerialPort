/*
 * utils.h
 *
 *  Created on: Nov 2, 2021
 *      Author: csmk
 */

#ifndef UTILS_STRING_BUILDER_H_
#define UTILS_STRING_BUILDER_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {
	uint64_t size;
	uint64_t res_size;
	char *str;
	char *res; // for conversion
	void (*prepend_char)(char);
	void (*append_char)(char);
	void (*append_str)(char *);
	char (*char_at)(uint16_t index);
	void (*clear)(void);
	void (*clear_res)(void);
	void (*int_to_string)(uint32_t);

}string_builder_t;

void string_builder_init(string_builder_t *builder);
void append_char(char);
void prepend_char(char);
void append_str(char*);
char char_at(uint16_t index);
uint32_t to_int(void);
char int_to_char(uint32_t n);
void int_to_string(uint32_t n);
void clear(void);
void clear_res(void);

//extern string_builder_t str_builder;

#endif /* UTILS_STRING_BUILDER_H_ */
