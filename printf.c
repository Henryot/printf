#include "main.h"
#include "printf_helpers.h"
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _printf - Custom printf function that formats and prints output.
 *           Supports %c, %s, %d, %i, %u, %o, %x, %X, and %b conversions.
 *
 * @format: The format string containing the conversion specifiers.
 * @...: The variadic arguments used for the conversion specifiers.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	int printed_chars = 0;

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;

			print_func_t *func = get_print_function(format[i]);
			if (func != NULL)
			{
				int count = func->func(args, buffer + buffer_index, BUFFER_SIZE - buffer_index);
				buffer_index += count;
				printed_chars += count;
			}
			else
			{
				if (buffer_index < BUFFER_SIZE - 1)
				{
					buffer[buffer_index++] = format[i];
					printed_chars++;
				}
			}
		}
		else
		{
			if (buffer_index < BUFFER_SIZE - 1)
			{
				buffer[buffer_index++] = format[i];
				printed_chars++;
			}
		}

		if (buffer_index >= BUFFER_SIZE - 1)
		{
			write(1, buffer, buffer_index);
			buffer_index = 0;
		}
	}

	if (buffer_index > 0)
		write(1, buffer, buffer_index);

	va_end(args);
	return printed_chars;
}
