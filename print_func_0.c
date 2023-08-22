#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int print_char(va_list args, char buffer[], int buffer_size)
{
    char c = va_arg(args, int);
    return (write_to_buffer_or_stdout(buffer, &buffer_size, NULL, &c, 1);
}

int print_str(va_list args, char buffer[], int buffer_size)
{
    char *str = va_arg(args, char *);
    int s_len = 0;

    while (str[s_len] != '\0')
        s_len++;

    return (write_to_buffer_or_stdout(buffer, &buffer_size, NULL, str, s_len);
}

int print_int(va_list args, char buffer[], int buffer_size, int flags, int field_width, int precision)
{
    int num = va_arg(args, int);
    int is_unsigned = 0;

    /* Handle the 'u' flag for unsigned integers */
    if (flags & FLAG_UNSIGNED)
        is_unsigned = 1;

    // Generate the number string
    char num_str[12];  // Temporary buffer to hold the number string
    int num_str_index = sizeof(num_str) - 1;

    num_str[num_str_index] = '\0';

    generate_number_string(num_str, num, 10, is_unsigned, flags, precision);

    int printed_len = sizeof(num_str) - num_str_index - 1;

    // Write the number string to buffer or stdout
    return (write_to_buffer_or_stdout(buffer, &buffer_idx, &char_count, num_str + num_str_index, printed_len, flags));
}

int print_percent(va_list args, char buffer[], int buffer_size, int flags, int field_width, int precision)
{
    // Handle the '0' flag for zero-padding
    if (flags & FLAG_ZERO)
    {
        field_width = field_width > 0 ? field_width : 1; // Minimum width is 1
        generate_number_string(num_str, 0, 10, 0, flags, field_width);
        int printed_len = field_width;

        // Write the zero-padded string to buffer or stdout
        return (write_to_buffer_or_stdout(buffer, &buffer_idx, &char_count, num_str, printed_len, flags));
    }
    else
    {
        // Write the percent character to buffer or stdout
        write_to_buffer_or_stdout(buffer, &buffer_idx, &char_count, "%", 1, flags);

        return (1);
    }
}

int print_reversed_str(va_list args, char buffer[], int buffer_size, int flags, int field_width, int precision)
{
    char *str = va_arg(args, char *);
    int s_len = 0;

    while (str[s_len] != '\0')
        s_len++;

    // Handle the field width and precision
    if (field_width > 0 && field_width > s_len)
        field_width = s_len;

    // Calculate the actual printed length
    int printed_len = field_width > s_len ? field_width : s_len;

    // Write the reversed string to buffer or stdout
    for (int i = printed_len - 1; i >= 0; i--)
    {
        write_to_buffer_or_stdout(buffer, &buffer_idx, &char_count, &str[i], 1, flags);
    }

    return (printed_len);
}

int print_unsign(va_list args, char buffer[], int buffer_size, int flags, int field_width, int precision)
{
    unsigned int num = va_arg(args, unsigned int);

    // Generate the number string
    char num_str[NUM_BUFFER_SIZE];  // Temporary buffer to hold the number string
    int num_str_index = sizeof(num_str) - 1;

    num_str[num_str_index] = '\0';

    generate_number_string(num_str, num, 10, 0, num_str);

    int printed_len = sizeof(num_str) - num_str_index - 1;

    // Handle the '0' flag for zero-padding
    if (flags & FLAG_ZERO)
    {
        field_width = field_width > printed_len ? field_width : printed_len; // Minimum width is the printed length
        handle_zero_flag(buffer, &buffer_idx, &char_count, field_width, printed_len, flags);
    }
    else if (field_width > printed_len)
    {
        handle_field_width(buffer, &buffer_idx, &char_count, field_width, printed_len, flags);
    }

    // Write the unsigned number string to buffer or stdout
    return (write_to_buffer_or_stdout(buffer, &buffer_idx, &char_count, num_str + num_str_index, printed_len));
}
