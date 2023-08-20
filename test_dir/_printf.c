#include "main.h"

/*
 * _printf - produces output according to a format.
 * @format - string is composed of zero or more directives.
 * Return - the number of characters printed.
 */

int _printf(const char *format, ...)
{
	int j = 0, len = 0, i;
	int char_printd = 0;
	va_list args;

	fmt_t fx = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int}
		{'\0', NULL}
	};

	va_start(args, format);

	while (*format != NULL & *format[j] != '\0')
	{
		i = 0;
		while = (fx[i].fmt != '\0')
		{
			if (fx[i].fmt == format[j])
			{
				fx[i].fxn(args);
			}
			i++;
		}
		j++;
	}
	write("\n");
	va_end;
}
