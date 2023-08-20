#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int char_printed = 0;

	va_list file;

	if (format == NULL)
		return (-1);

	va_start(file, format);
	
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_printed++;
		}
		else
		{
			format++;

		if (*format == '\0')
			break;

		if (*format == '%')
		{
			write(1, format, 1);
			char_printed++;
		}
		else if (*format == 'c')
		{
			char c = va_arg(file, int);
			write(1, &c, 1);
			char_printed++;
		}
		else if (*format == 's')
		{
			char *string = va_arg(file, char*);
			
			int str_len = 0;

			while (string[str_len] != '\0')
				str_len++;

			write(1, string, str_len);
			char_printed += str_len;
		}
		}
		format++;
	}
	va_end(file);

	return (char_printed);

}
