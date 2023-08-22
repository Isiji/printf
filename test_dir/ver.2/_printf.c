#include "main.h"
/**
 * flush_buffer - Writing the buffered content and
 * updating buffer_index and char_count
 * @buffer: pointer buffer
 * @buffer_idx: pionter to buffer_index.
 * @char_count: pionter to char_count.
 */
void flush_buffer(char buffer[], int *buffer_idx, int *char_count)
{
	write(1, buffer, *buffer_idx);
	*char_count += *buffer_idx;
	*buffer_idx = 0;
}
/**
 * handle_fmt_spe - processing a format specifier.
 * @fmt_specifier: the format specifier
 * @args: arguments
 * @buffer: pionter to buffer_index.
 * @buffer_idx: pionter to buffer_index.
 * Return: number of char written to the buffer.
 */
int handle_fmt_spe(char fmt_specifier, va_list args,
		char buffer[], int *buffer_idx)
{
	fmt_t fx[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'u', print_unsign}, 
		{'o', print_octal}, {'x', print_hex}, {'X', print_hex_upp},
		{'\0', NULL}
	};

	int i = 0;

	while (fx[i].fmt != '\0')
	{
		if (fx[i].fmt == fmt_specifier)
		{
			int printed = fx[i].func(args, buffer + *buffer_idx,
					BUFFER_SIZE - *buffer_idx);
			*buffer_idx += printed;
			return (printed);
		}
		i++;
	}
	return (0); /* Invalid format specifier, not handled */
}

/**
 * _printf - Produces output according to a format.
 * @format: string is composed of zero or more directives.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];/* accumulate char before printing them */
	int buffer_idx = 0;/* Index to track position in the buffer */
	int char_count = 0;/* Count of printed characters */
	int j, printed;

	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	for (j = 0; format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			if (buffer_idx < BUFFER_SIZE - 1)
			{
				buffer[buffer_idx++] = format[j];
				char_count++;
			}
			else
			{
				flush_buffer(buffer, &buffer_idx, &char_count);
				buffer[buffer_idx++] = format[j];
				char_count++;
			}
		}
		else
		{
			j++;
			printed = handle_fmt_spe(format[j], args,
					buffer, &buffer_idx);
			char_count += printed;
		}
	}
	if (buffer_idx > 0)
	{
		flush_buffer(buffer, &buffer_idx, &char_count);
	}
	va_end(args);
	return (char_count);
}
