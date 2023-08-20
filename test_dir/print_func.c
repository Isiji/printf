#include "main.h"
/**
 * print_char - prints character
 * @args - arguments
 * Return: number of printed characters
 */
int print_char(va_list args)
{
	char c = va_arg(args, char *);
	return(write(1, c, 1));
}

/**
 * print_str - prints strings
 * @args - arguments
 * Return: number of printed characters
 */
int print_str(va_list args)
{
	char *str = va_arg(args,const char *);
	int s_len = 0;

	while (str(s_len != '\0'))
		s_len++;
	if ( int i = 0; i < s_len; i != '\0')
		return(write(1, str(s_len), s_len))
}

/**
 * print_percent- prints percent
 * @args - arguments
 * Return: number of printed characters
 */
int print_percent(va_list args)
{
	return(write(1, "%%", 1));
}

/**
 * print_int - prints integers
 * @args - arguments
 * Return: number of printed characters
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	int len = 0;
	int temp = num;

	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	char buffer[12];
	return(write(buffer, num, len));
}

