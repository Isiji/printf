#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char rot13(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        if (c >= 'a' && c <= 'z')
        {
            return (c - 'a' + 13) % 26 + 'a';
        }
        else
        {
            return (c - 'A' + 13) % 26 + 'A';
        }
    }
    return (c);
}

int print_rot13_str(va_list args, char buffer[], int buffer_size, int flags, int field_width, int precision)
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

    // Write the ROT13'ed string to buffer or stdout
    for (int i = 0; i < s_len; i++)
    {
        char c = rot13(str[i]);
        write_to_buffer_or_stdout(buffer, &buffer_idx, &char_count, &c, 1, flags);
    }

    return (printed_len);
}

int print_pointer(va_list args, char buffer[], int buffer_size, int flags, int field_width, int precision)
{
    void *ptr = va_arg(args, void *);

    // Convert the pointer to a number for printing
    uintptr_t ptr_num = (uintptr_t)ptr;

    // Generate the hexadecimal number string
    char num_str[18]; // For holding the pointer value in hexadecimal
    int num_str_index = sizeof(num_str) - 1;

    num_str[num_str_index] = '\0';

    generate_number_string(num_str, ptr_num, 16, 1, flags, precision);

    int printed_len = sizeof(num_str) - num_str_index - 1;

    // Write the pointer value string to buffer or stdout
    return (write_to_buffer_or_stdout(buffer, &buffer_idx, &char_count, num_str + num_str_index, printed_len, flags));
}

int print_oct(va_list args, char buffer[], int buffer_size, int flags, int field_width, int precision)
{
    int num = va_arg(args, int);
    int is_unsigned = 0;

    // Handle the 'u' flag for unsigned integers
    if (flags & FLAG_UNSIGNED)
        is_unsigned = 1;

    // Generate the octal number string
    char num_str[12];  // Temporary buffer to hold the number string
    int num_str_index = sizeof(num_str) - 1;

    num_str[num_str_index] = '\0';

    generate_number_string(num_str, num, 8, is_unsigned, flags, precision);

    int printed_len = sizeof(num_str) - num_str_index - 1;

    // Write the octal number string to buffer or stdout
    return (write_to_buffer_or_stdout(buffer, &buffer_idx, &char_count, num_str + num_str_index, printed_len, flags));
}
