#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to the standard output (file descriptor 1)
 * @c: The character to be written
 *
 * Return: On success, the number of characters written. On error, -1.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printf - Prints output according to a format.
 * @format: The format string containing the directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' character */
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					_putchar(c);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						_putchar(*str);
						count++;
						str++;
					}
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);

	return count;
}
