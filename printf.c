/* printf.c */
#include "main.h"
#include <stddef.h>

/**
 * print_format - Prints a formatted string to stdout.
 * @format: The format string containing the format specifiers.
 * @args: The arguments list containing the values for the format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int print_format(const char *format, va_list args)
{
    int printed_chars = 0;
    int (*print_fn)(va_list);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            print_fn = NULL;

            if (*format == 'c')
                print_fn = print_char;
            else if (*format == 's')
                print_fn = print_string;
            else if (*format == '%')
                print_fn = print_percent;

            if (print_fn)
                printed_chars += print_fn(args);
            else
                printed_chars += _putchar('%');
        }
        else
        {
            printed_chars += _putchar(*format);
        }

        format++;
    }

    return printed_chars;
}

/**
 * _printf - Prints a formatted string to stdout.
 * @format: The format string containing the format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars;

    va_start(args, format);
    printed_chars = print_format(format, args);
    va_end(args);

    return printed_chars;
}
