#include "main.h"

#define BUFFER_SIZE 1024

/**
 * write_buffer - Writes the contents of the buffer to stdout
 * @buffer: Array of characters to be printed
 * @buff_len: Length of the buffer
 */
void write_buffer(char buffer[], int *buff_len);

/**
 * _printf - Printf function
 * @format: Format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0, buff_len = 0;
	int flags, width, precision, size, printed = 0;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_len++] = format[i];
			if (buff_len == BUFFER_SIZE)
				write_buffer(buffer, &buff_len);
			printed_chars++;
		}
		else
		{
			write_buffer(buffer, &buff_len);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, args, buffer,
				flags, width, precision, size);
			if (printed == -1)
			{
				va_end(args);
				return (-1);
			}
			printed_chars += printed;
		}
	}

	write_buffer(buffer, &buff_len);

	va_end(args);

	return (printed_chars);
}

/**
 * write_buffer - Writes the contents of the buffer to stdout
 * @buffer: Array of characters to be printed
 * @buff_len: Length of the buffer
 */
void write_buffer(char buffer[], int *buff_len)
{
	if (*buff_len > 0)
	{
		write(1, &buffer[0], *buff_len);
		*buff_len = 0;
	}
}
