#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_string - Prints a string to the standard output.
 * @str: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_string(const char *str)
{
	int count = 0;
	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		count++;
		str++;
	}

	return count;
}

/**
 * print_char - Prints a character to the standard output.
 * @c: The character to be printed.
 *
 * Return: The number of characters printed.
 */
int print_char(char c)
{
	_putchar(c);
	return 1;
}
