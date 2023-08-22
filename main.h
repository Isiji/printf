#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define NUM_BUFFER_SIZE 12
/* struct format - is a structure that will contain all the other files*/
struct format
{
	char fmt;
	int (*func)(va_list, char[], int, int, int);
};

typedef struct format fmt_t;

int _printf(const char *format, ...);
int print_char(va_list args, char buffer[], int buffer_size,
		int flags, int field_width, int precision);
int print_str(va_list args, char buffer[], int buffer_size,
		int flags, int field_width, int precision);
int print_percent(va_list args, char buffer[], int buffer_size,
		int flags, int field_width, int precision);
int print_int(va_list args, char buffer[], int buffer_size,
		int flags, int field_width, int precision);
int print_pointer(va_list args, char buffer[], int buffer_size,
		int flags, int field_width, int precision);
int print_oct(va_list args, char buffer[], int buffer_size,
		int flags, int field_width, int precision);
int print_unsign(va_list args, char buffer[], int buffer_size,
		int flags, int field_width, int precision);
int print_hex(va_list args, char buffer[], int buffer_size,
		int flags, int field_width, int precision);
int print_hex_upp(va_list args, char buffer[], int buffer_size,
		int flags, int field_width, int precision);
int print_reversed_str(va_list args, char buffer[], int buffer_size,
		int flags, int field_width, int precision);
int print_rot13_str(va_list args, char buffer[], int buffer_size,
		int flags, int field_width, int precision);

int write_to_buffer_or_stdout(char buffer[], int *buffer_idx,
		int *char_count, const char *content, int content_len);
int generate_number_string(unsigned long num, int base,
		int uppercase, char num_str[]);
int handle_flags(char buffer[], int *buffer_idx,
		int *char_count, int flags);
int handle_field_width(char buffer[], int *buffer_idx,
		int *char_count, int field_width, int content_len, int flags);
int handle_precision(char buffer[], int *buffer_idx,
		int *char_count, int precision, char content[], int content_len, int flags);
int handle_flags(char buffer[], int *buffer_idx,
		int *char_count, int flags);
int handle_minus_flag(char buffer[], int *buffer_idx,
		int *char_count, int field_width, int content_len, int flags);
int print_reversed_str(va_list args, char buffer[],
		int buffer_size, int flags, int field_width, int precision);
int handle_minus_flag(char buffer[], int *buffer_idx,
		int *char_count, int field_width, int content_len, int flags);
int handle_zero_flag(char buffer[], int *buffer_idx,
		int *char_count, int field_width, int content_len, int flags);

#endif

