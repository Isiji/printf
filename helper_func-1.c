#include "main.h"
#include <unistd.h>

int handle_minus_flag(char buffer[], int *buffer_idx,
		int *char_count, int field_width, int content_len, int flags)
{
	if (field_width > content_len && (flags & FLAG_MINUS))
	{
		char space_padding_char = ' ';
		int padding_len = field_width - content_len;

		handle_field_width(buffer, buffer_idx, char_count, padding_len, 1, flags);

		for (int i = 0; i < content_len; i++)
		{
			write_to_buffer_or_stdout(buffer, buffer_idx,
					char_count, &buffer[i], 1, flags);
		}

		return (padding_len + content_len);
	}

	return (content_len);
}

int print_reversed_str(va_list args, char buffer[], int buffer_size,
		int flags, int field_width, int precision)
{
	char *str = va_arg(args, char *);
	int s_len = 0;

	while (str[s_len] != '\0')
		s_len++;

	if (precision >= 0 && precision < s_len)
		s_len = precision;

	int printed_len = handle_minus_flag(buffer, &buffer_size,
			&s_len, field_width, s_len, flags);

	for (int i = s_len - 1; i >= 0; i--)
	{
		write_to_buffer_or_stdout(buffer, &buffer_size,
				&printed_len, &str[i], 1, flags);
	}

	return (printed_len);
}

int handle_zero_flag(char buffer[], int *buffer_idx,
	int *char_count, int field_width, int content_len, int flags)
{
	if (field_width > content_len && (flags & FLAG_ZERO))
	{
		char zero_padding_char = '0';
		int padding_len = field_width - content_len;

		for (int i = 0; i < padding_len; i++)
		{
			write_to_buffer_or_stdout(buffer, buffer_idx, char_count,
					&zero_padding_char, 1);
		}
	}

	/* Return the content length (no additional characters added)*/

	return (content_len);
}
