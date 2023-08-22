/**
 * write_to_buffer_or_stdout -
 * @buffer:
 * @buffer_idx:
 * @buffer_size:
 * Return: length of printed characters
 */
static int write_to_buffer_or_stdout(const char *str, char buffer[],
		int *buffer_idx, int buffer_size)
{
	int len = 0;
	while (str[len] != '\0' && (*buffer_idx < buffer_size - 1))
	{
		buffer[(*buffer_idx)++] = str[len++];
	}
	if (*buffer_idx >= buffer_size - 1)
	{
		write(1, buffer, *buffer_idx);
		*buffer_idx = 0;
		len = 0;
		while (str[len] != '\0')
		{
			buffer[(*buffer_idx)++] = str[len++];
		}
	}
	return (len);
}

int print_number_base(va_list args, char buffer[],
		int buffer_size, int base, int uppercase)
{
	   

