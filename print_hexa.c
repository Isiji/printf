#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int print_hex(va_list args, char buffer[], int buffer_size, int flags, int field_width, int precision)
{
int num = va_arg(args, int);
int is_unsigned = 1;

// Generate the hexadecimal number string
char num_str[12];  // Temporary buffer to hold the number string
int num_str_index = sizeof(num_str) - 1;

num_str[num_str_index] = '\0';

generate_number_string(num_str, num, 16, is_unsigned, flags, precision);

int printed_len = sizeof(num_str) - num_str_index - 1;

// Write the hexadecimal number string to buffer or stdout
return (write_to_buffer_or_stdout(buffer, &buffer_idx, &char_count, num_str + num_str_index, printed_len, flags));
}

int print_hex_upp(va_list args, char buffer[], int buffer_size, int flags, int field_width, int precision)
{
int num = va_arg(args, int);
int is_unsigned = 1;

// Generate the uppercase hexadecimal number string
char num_str[12];  // Temporary buffer to hold the number string
int num_str_index = sizeof(num_str) - 1;

num_str[num_str_index] = '\0';

generate_number_string(num_str, num, 16, is_unsigned, flags | FLAG_UPPERCASE, precision);

int printed_len = sizeof(num_str) - num_str_index - 1;

// Write the uppercase hexadecimal number string to buffer or stdout
return (write_to_buffer_or_stdout(buffer, &buffer_idx, &char_count, num_str + num_str_index, printed_len, flags));
}
