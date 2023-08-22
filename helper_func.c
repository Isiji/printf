#include "main.h"
#include <unistd.h>

int write_to_buffer_or_stdout(char buffer[], int *buffer_idx,
		int *char_count, const char *content, int content_len)
{
	if (*buffer_idx + content_len <= BUFFER_SIZE - 1)
	{
	for (int i = 0; i < content_len; i++)
		buffer[(*buffer_idx)++] = content[i];
	return (content_len);
	}
	else
	{
	write(1, buffer, *buffer_idx);
	*char_count += *buffer_idx;
	*buffer_idx = 0;
	write(1, content, content_len);
	*char_count += content_len;
	return (content_len);
	}
}

int generate_number_string(char num_str[], unsigned long num,
		int base, int is_unsigned, int flags, int precision);
{
	int len = 0;
	unsigned long temp = num;

	num_str[NUM_BUFFER_SIZE - 1] = '\0';

	do

	{

		int remainder = temp % base;

		if (remainder < 10)
			num_str[--NUM_BUFFER_SIZE] = '0' + remainder;
		else
			num_str[--NUM_BUFFER_SIZE] = (uppercase ? 'A' : 'a') + (remainder - 10);
		temp /= base;
		len++;
	}
while (temp != 0);

	return (NUM_BUFFER_SIZE - NUM_BUFFER_SIZE);
}

int handle_flags(char buffer[], int *buffer_idx, int *char_count, int flags)
{
	if (flags & FLAG_PLUS)
	{
	char plus_sign = '+';

	write_to_buffer_or_stdout(buffer, buffer_idx, char_count, &plus_sign, 1);
	}
	else if (flags & FLAG_SPACE)
	{
	char space = ' ';
		write_to_buffer_or_stdout(buffer, buffer_idx, char_count, &space, 1);
	}

	return (0);
}

int handle_field_width(char buffer[], int *buffer_idx,
		int *char_count, int field_width, int content_len, int flags)
{
	if (field_width > content_len)
	{
	char padding_char = (flags & FLAG_ZERO) ? '0' : ' ';
	int padding_len = field_width - content_len;

	for (int i = 0; i < padding_len; i++)
	{
		write_to_buffer_or_stdout(buffer, buffer_idx, char_count, &padding_char, 1);
	}

	return (padding_len);
	}
	return (0);
}

int handle_precision(char buffer[], int *buffer_idx, int *char_count,
		int precision, char content[], int content_len, int flags)
{
	if (precision >= 0 && precision < content_len)
	{
	content_len = precision;
	}
	return (write_to_buffer_or_stdout(buffer, buffer_idx,
				char_count, content, content_len, flags));
}


