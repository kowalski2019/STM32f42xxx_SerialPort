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

String_Builder_t mStrBuildBuffer;

void String_Builder_Init(void)
{
	String_Builder_Clear();
	mStrBuildBuffer.size = 0;
	mStrBuildBuffer.res_size = 0;
	mStrBuildBuffer.str = (char *)malloc(sizeof(char) * STR_DEFAULT_SIZE);
	mStrBuildBuffer.capacity = STR_DEFAULT_SIZE;
	mStrBuildBuffer.String_Builder_Prepend_Char = &String_Builder_Prepend_Char;
	mStrBuildBuffer.String_Builder_Append_Char = &String_Builder_Append_Char;
	mStrBuildBuffer.String_Builder_Append_Str = &String_Builder_Append_Str;
	mStrBuildBuffer.String_Builder_Char_At = &String_Builder_Char_At;
	mStrBuildBuffer.String_Builder_Clear = &String_Builder_Clear;
	mStrBuildBuffer.String_Builder_Clear_Res = &String_Builder_Clear_Res;
	mStrBuildBuffer.String_Builder_Int_To_String = &String_Builder_Int_To_String;
}

void String_Builder_Prepend_Char(char c)
{
	int i = mStrBuildBuffer.res_size;
	while (i > 0)
	{
		*(mStrBuildBuffer.res + i) = *(mStrBuildBuffer.res + (i - 1));
		i -= 1;
	}
	*(mStrBuildBuffer.res) = c;
	// update size
	mStrBuildBuffer.res_size += 1;
}

void String_Builder_Append_Char(char c)
{

	if (mStrBuildBuffer.size + 1 >= mStrBuildBuffer.capacity)
	{
		char *to_free = mStrBuildBuffer.str;
		// increase str capacity
		uint64_t new_capacity = mStrBuildBuffer.capacity * mStrBuildBuffer.capacity;
		char *new_str = (char *)malloc(sizeof(char) * new_capacity);
		// TODO check malloc result!
		for (int i = 0; i < mStrBuildBuffer.size; i++)
		{
			new_str[i] = mStrBuildBuffer.str[i];
		}
		mStrBuildBuffer.str = new_str;
		mStrBuildBuffer.capacity = new_capacity;
		free(to_free);
	}
	// append char
	*(mStrBuildBuffer.str + mStrBuildBuffer.size) = c;
	*(mStrBuildBuffer.str + (mStrBuildBuffer.size + 1)) = '\0';
	// update size
	mStrBuildBuffer.size += 1;
}

void String_Builder_Append_Str(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		mStrBuildBuffer.String_Builder_Append_Char(*(str + i++));
	}
}

char String_Builder_Char_At(uint16_t index)
{
	if (index < mStrBuildBuffer.size && index > -1)
	{
		return *(mStrBuildBuffer.str + index);
	}
	return '\0';
}

char String_Builder_Digit_To_Char(uint32_t n)
{
	return (char)('0' + n);
}

void String_Builder_Int_To_String(int32_t n)
{
	mStrBuildBuffer.String_Builder_Clear_Res();
	uint8_t neg_flag = 0;
	if (n < 0)
	{
		neg_flag = 1;
		n = n * -1;
	}
	else if (n == 0)
	{
		mStrBuildBuffer.String_Builder_Prepend_Char(String_Builder_Digit_To_Char(n));
	}
	else
	{
		while (n != 0)
		{

			uint32_t num = n % 10;
			mStrBuildBuffer.String_Builder_Prepend_Char(String_Builder_Digit_To_Char(num));
			n /= 10;
		}
	}
	if (neg_flag)
		mStrBuildBuffer.String_Builder_Prepend_Char('-');
}

void String_Builder_Clear(void)
{
	for (int i = 0; i < mStrBuildBuffer.size; i++)
		*(mStrBuildBuffer.str + i) = '\0';
	mStrBuildBuffer.size = 0;
}
void String_Builder_Clear_Res(void)
{
	mStrBuildBuffer.res_size = 0;
	for (int i = 0; i < RES_DEFAUT_SIZE; i++)
		*(mStrBuildBuffer.res + i) = '\0';
}
