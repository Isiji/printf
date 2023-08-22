#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/* @flush_buffer: allocates buffer memory*/

void flush_buffer(char buffer[], int *buffer_idx, int *char_count)
{
	write_to_buffer_or_stdout(buffer, buffer_idx, char_count, NULL, 0, 0);
}

int handle_fmt_spe(char fmt_specifier, va_list args,
		char buffer[], int *buffer_idx, int flags, int field_width, int precision)
{
	fmt_t fx[] = {
		{'c', print_char}, {'s', print_str},
		{'%', print_percent}, {'d', print_int},
		{'i', print_int}, {'p', print_pointer},
		{'o', print_oct}, {'u', print_unsign},
		{'x', print_hex}, {'X', print_hex_upp},
		{'r', print_reversed_str}, {'R', print_rot13_str},
		{'\0', NULL}
	};

	int i = 0;

	while (fx[i].fmt != '\0')
	{
		if (fx[i].fmt == fmt_specifier)
		{
			intOC printed = fx[i].func(args, buffer, BUFFER_SIZE - *buffer_idx,
					flags, field_width, precision);
			*buffer_idx += printed;
			return (printed);
		}
		i++;
	}

	/* Handle Invalid format specifier */
	if (buffer_size >= 2)
	{
		buffer[0] = '%';
		buffer[1] = fmt_specifier;
		*buffer_idx += 2;
		return (2);
	}
	else
	{
		write_to_buffer_or_stdout(buffer, &buffer_size, buffer_idx, "%", 1, flags);
		write_to_buffer_or_stdout(buffer, &buffer_size,
				buffer_idx, &fmt_specifier, 1, flags);
		return (2);
	}
}
/* @_printf: prints characters to the standard output*/

int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int buffer_idx = 0, char_count = 0;
	va_list args;

	if (!format)
		return (-1);
	va_start(args, format);

	for (int i = 0; format[i]; ++i)
	{
		if (format[i] == '%')
		{
			++i;
			int flags = 0, field_width = 0, precision = -1;

			i = handle_flags(format, i, &flags);
			i = handle_field_width(format, i, &field_width);
			i = handle_precision(format, i, &precision);
			int printed = handle_fmt_spe(format[i], args, buffer,
					&buffer_idx, flags, field_width, precision);
			char_count += printed;
		}
		else
		{
			buffer[buffer_idx++] = format[i];
			if (buffer_idx == BUFFER_SIZE)
				flush_buffer(buffer, &buffer_idx, &char_count);
		}
	}

	flush_buffer(buffer, &buffer_idx, &char_count);
	va_end(args);
	return (char_count);
}
