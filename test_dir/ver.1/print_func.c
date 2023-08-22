#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - prints character
 * @args: arguments
 * Return: number of printed characters
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_str - prints strings
 * @args: arguments
 * Return: number of printed characters
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	int s_len = 0;

	while (str[s_len] != '\0')
		s_len++;
	return (write(1, str, s_len));
}

/**
 * print_percent- prints percent
 * @args: arguments
 * Return: number of printed characters
 */
int print_percent(va_list args)
{
	return (write(1, "%%", 1));
}

/**
 * print_int - prints integers
 * @args: arguments
 * Return: number of printed characters
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	int len = 0;
	int temp = num;

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		len++;
	}

	while (temp != 0)
	{
		temp /= 10;
		len++;
	}

	char buffer[12];
	char *str = buffer + sizeof(buffer) - 1;
	*str = '\0';

	do {
		str--;
		*str = '0' + (num % 10);
		num /= 10;
	} while (num != 0);

	return (write(1, str, len));
}

