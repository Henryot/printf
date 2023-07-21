#include "main.h"
#include <unistd.h> /* For write */

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: On success, 1. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Prints a single character.
 * @args: The argument list.
 *
 * Return: The number of characters printed.
 */
int print_char(va_list args)
{
	char ch = va_arg(args, int);

	return (_putchar(ch));
}

/**
 * print_string - Prints a string.
 * @args: The argument list.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
	int printed_chars;
	char *str_arg = va_arg(args, char *);

	if (!str_arg)
		str_arg = "(null)";

	for (printed_chars = 0; *str_arg; printed_chars++)
	{
		_putchar(*str_arg);
		str_arg++;
	}
	return (printed_chars);
}

/**
 * print_percent - Prints a percentage sign.
 * @args: The argument list.
 *
 * Return: The number of characters printed.
 */
int print_percent(va_list args __attribute__((unused)))
{
	return (_putchar('%'));
}

/**
 * _printf - Custom implementation of printf.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	int (*print_fn)(va_list);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			printed_chars += _putchar(*format);
		}
		else
		{
			format++;
			print_fn = NULL;

			switch (*format)
			{
				case 'c':
					print_fn = print_char;
					break;
				case 's':
					print_fn = print_string;
					break;
				case '%':
					print_fn = print_percent;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					printed_chars += 2;
			}
			if (print_fn)
				printed_chars += print_fn(args);
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
