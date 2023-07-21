#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_integer - Prints an integer to the standard output.
 * @n: The integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_integer(int n)
{
	int divisor = 1;
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
	}

	/* Get the divisor for the first digit */
	while (n / divisor > 9)
		divisor *= 10;

	/* Print each digit */
	while (divisor != 0)
	{
		_putchar('0' + (n / divisor) % 10);
		count++;
		divisor /= 10;
	}

	return count;
}

#include <stdarg.h>
#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to the standard output.
 * @c: The character to be written.
 *
 * Return: On success, the number of characters written is returned.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					printed_chars += _putchar(va_arg(args, int));
					break;
				case 's':
					printed_chars += print_string(va_arg(args, char *));
					break;
				case '%':
					printed_chars += _putchar('%');
					break;
				case 'd':
				case 'i':
					printed_chars += print_integer(va_arg(args, int));
					break;
				case 'u':
					printed_chars += print_unsigned(va_arg(args, unsigned int));
					break;
				case 'o':
					printed_chars += print_octal(va_arg(args, unsigned int));
					break;
				case 'x':
					printed_chars += print_hex(va_arg(args, unsigned int), 0);
					break;
				case 'X':
					printed_chars += print_hex(va_arg(args, unsigned int), 1);
					break;
				case 'p':
					printed_chars += print_pointer(va_arg(args, void *));
					break;
				default:
					printed_chars += _putchar('%');
					printed_chars += _putchar(*format);
					break;
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return printed_chars;
}
