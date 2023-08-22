#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * struct format - struct op
 * @fmt: the format string
 * @func: associated function
 */
struct format
{
	char fmt;
	int (*func)(va_list, char [], int);
};

/**
 * typedef struct format fmt_t - struct op
 * @format: is the format.
 * @fmt_t: pointer to the associated function.
 */
typedef struct format fmt_t;

int _printf(const char *format, ...);
/*static int write_to_buffer_or_stdout(const char *str, char buffer[],
		int *buffer_idx, int buffer_size);*/
int print_char(va_list args, char buffer[], int buffer_size);
int print_str(va_list args, char buffer[], int buffer_size);
int print_percent(va_list args, char buffer[], int buffer_size);
int print_int(va_list args, char buffer[], int buffer_size);
/*int print_unsign(va_list args, char buffer[], int buffer_size);
int print_octal(va_list args, char buffer[], int buffer_size);
int print_hex(va_list args, char buffer[], int buffer_size);
int print_hex_upp(va_list args, char buffer[], int buffer_size);*/

#endif /* MAIN_H */
