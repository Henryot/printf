#include "main.h"
#include <stddef.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 *
 * Return: On success, the character written is returned.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * print_char - Prints a character from the arguments list.
 * @args: The arguments list containing the character to print.
 *
 * Return: The number of characters printed (always 1).
 */
int print_char(va_list args)
{
    char ch = va_arg(args, int);
    return _putchar(ch);
}

/**
 * print_string - Prints a string from the arguments list.
 * @args: The arguments list containing the string to print.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int printed_chars = 0;

    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        printed_chars += _putchar(*str);
        str++;
    }

    return printed_chars;
}

/**
 * print_percent - Prints the percentage character (%).
 * @args: The arguments list (unused).
 *
 * Return: The number of characters printed (always 1).
 */
int print_percent(va_list args)
{
    (void)args; /* Unused parameter */
    return _putchar('%');
}
