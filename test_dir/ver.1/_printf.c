#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/*
 * _printf - produces output according to a format.
 * @format - string is composed of zero or more directives.
 * Return - the number of characters printed.
 */

int _printf(const char *format, ...)
{
	int i, j = 0;
	int printed;
	va_list args;

	fmt_t fx[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (int j = 0; format[j] != '\0'; j++)
	{
		if (format[j] != '%')  /* Copy non-format specifier characters to buffer */
		{
			if (buffer_index < BUFFER_SIZE - 1)
					{
						buffer[buffer_index++] = format[i];
							char_count++;
					}

	va_end(args);
}
