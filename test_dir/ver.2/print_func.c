#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_char - prints character
 * @args: arguments
 * @buffer:  store the formatted output temporarily before printing
 * @buffer_size: array which defines the maximum capacity of the buffer.
 * Return: number of printed characters
 */
int print_char(va_list args, char buffer[], int buffer_size)
{
	char c = va_arg(args, int);

	if (buffer_size > 0)
	{
		buffer[0] = c;
		return (1);
	}
	else
	{
		write(1, &c, 1);
		return (1);
	}
}

/**
 * print_str - prints strings
 * @args: arguments
 * @buffer:  store the formatted output temporarily before printing
 * @buffer_size: array which defines the maximum capacity of the buffer.
 * Return: number of printed characters
 */
int print_str(va_list args, char buffer[], int buffer_size)
{
	char *str = va_arg(args, char *);
	int s_len = 0, i;

	while (str[s_len] != '\0')
		s_len++;

	if (buffer_size >= s_len)
	{
		for (i = 0; i < s_len; i++)
			buffer[i] = str[i];
		return (s_len);
	}
	else
	{
		write(1, str, s_len);
		return (s_len);
	}
}

/**
 * print_int - prints integers
 * @args: arguments
 * @buffer:  store the formatted output temporarily before printing
 * @buffer_size: array which defines the maximum capacity of the buffer.
 * Return: number of printed characters
 */
int print_int(va_list args, char buffer[], int buffer_size)
{
	int num = va_arg(args, int);
	int len = 0;
	int temp = num;
	int printed_len, num_str_index, i;

	char num_str[12];

	if (num < 0)
	{
		if (buffer_size > 0)
		{
			buffer[0] = '-';
			len++;
		}
		else
		{
			write(1, "-", 1);
			len++;
		}

		num = -num;
	}
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}

	num_str_index = sizeof(num_str) - 1;

	num_str[num_str_index] = '\0';

	do {
		num_str[--num_str_index] = '0' + (num % 10);
		num /= 10;
	} while (num != 0);
	printed_len = sizeof(num_str) - num_str_index - 1;

	if (buffer_size >= printed_len)
	{
		for (i = 0; i < printed_len; i++)
			buffer[i] = num_str[num_str_index + i];
	}
	else
	{
		write(1, num_str + num_str_index, printed_len);
	}
	return (printed_len);
}

/**
 * print_percent- prints percent
 * @args: arguments
 * Return: number of printed characters
 * @buffer:  store the formatted output temporarily before printing
 * @buffer_size: array which defines the maximum capacity of the buffer.
 */
int print_percent(va_list args, char buffer[], int buffer_size)
{
	(void) args;

	if (buffer_size > 0)
	{
		buffer[0] = '%';
		return (1);
	}
	else
	{
		write(1, "%", 1);
		return (1);
	}
}
