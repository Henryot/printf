#include "main.h"
#include "printf_helpers.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int i;
	print_func_t *func;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;

			func = get_print_function(format[i]);
			if (func != NULL)
				printed_chars += func->func(args);
			else
			{
				putchar(format[i]);
				printed_chars++;
			}
		}
		else
		{
			putchar(format[i]);
			printed_chars++;
		}
	}

	va_end(args);
	return printed_chars;
}
