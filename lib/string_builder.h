/**
 ******************************************************************************
 * @file    	string_builder.h
 * @author		Claude Stephane M. Kouame; claude.kouame@csmk59.de
 * @version 	V1.0
 * @date		2021.11.2
 * @brief  	Module for using string manipulation.
 ******************************************************************************
 */

#ifndef UTILS_STRING_BUILDER_H_
#define UTILS_STRING_BUILDER_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define STR_DEFAULT_SIZE 10
#define RES_DEFAUT_SIZE 16

typedef struct
{
	uint64_t size;
	uint64_t res_size;
	uint64_t capacity;
	char *str;
	char res[RES_DEFAUT_SIZE]; // for conversion , int to string
	void (*String_Builder_Prepend_Char)(char);
	void (*String_Builder_Append_Char)(char);
	void (*String_Builder_Append_Str)(char *);
	char (*String_Builder_Char_At)(uint16_t index);
	void (*String_Builder_Clear)(void);
	void (*String_Builder_Clear_Res)(void);
	void (*String_Builder_Int_To_String)(int32_t);

} String_Builder_t;

void String_Builder_Init(void);
void String_Builder_Append_Char(char);
void String_Builder_Prepend_Char(char);
void String_Builder_Append_Str(char *);
char String_Builder_Char_At(uint16_t index);
int32_t String_Builder_To_Int(void);
char String_Builder_Digit_To_Char(uint32_t n);
void String_Builder_Int_To_String(int32_t n);
void String_Builder_Clear(void);
void String_Builder_Clear_Res(void);

extern String_Builder_t mStrBuildBuffer;

#endif /* UTILS_STRING_BUILDER_H_ */
