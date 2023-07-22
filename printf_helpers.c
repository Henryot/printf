#include "printf_helpers.h"
#include <stdio.h>
#include "main.h"
/* Declaration of the print_functions array */
static print_func_t print_functions[] = {
    {'c', print_char},
    {'s', print_string},
    {'d', print_int},
    {'i', print_int},
    {'b', print_binary},
    {'u', print_unsigned_int},
    {'o', print_octal},
    {'x', print_hexadecimal},
    {'X', print_hexadecimal_upper},
    {0, NULL}
};

/**
 * print_char - Print a single character.
 * @args: The list of arguments containing the character to print.
 *
 * Return: The number of characters printed (always 1).
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	putchar(c);
	return (1);
}

/**
 * print_string - Print a string.
 * @args: The list of arguments containing the string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
	const char *str = va_arg(args, const char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		putchar(*str++);
		count++;
	}

	return (count);
}

/**
 * print_int_helper - Helper function to print an unsigned integer
 * in a specified base.
 * @num: The unsigned integer to print.
 * @base: The base to use for printing (e.g., 10 for decimal).
 *
 * Return: The number of characters printed.
 */
int print_int_helper(unsigned int num, unsigned int base)
{
	int count = 0;
	char buffer[32];
	int i = 0;
	int j;

	if (num == 0)
	{
		putchar('0');
		return (1);
	}

	while (num > 0)
	{
		int rem = num % base;

		buffer[i++] = (rem < 10) ? (rem + '0') : (rem - 10 + 'a');
		num /= base;
	}

	for (j = i - 1; j >= 0; j--)
	{
		putchar(buffer[j]);
		count++;
	}

	return (count);
}

/**
 * print_int - Print a signed integer.
 * @args: The list of arguments containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	unsigned int positive_num;

	if (num < 0)
	{
		putchar('-');
		positive_num = -num;
	}
	else
	{
		positive_num = num;
	}

	if (positive_num == 0)
	{
		putchar('0');
		return (1);
	}

	return (print_int_helper(positive_num, 10));
}

/**
 * print_unsigned_int - Print an unsigned integer.
 * @args: The list of arguments containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned_int(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	if (num == 0)
	{
		putchar('0');
		return (1);
	}

	return (print_int_helper(num, 10));
}

/**
 * print_octal - Print an unsigned integer as an octal number.
 * @args: The list of arguments containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_int_helper(num, 8));
}

/**
 * print_hexadecimal - Print an unsigned integer
 * @args: The list of arguments containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_hexadecimal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_int_helper(num, 16));
}

/**
 * print_hexadecimal_upper - Print an unsigned integer 
 * @args: The list of arguments containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_hexadecimal_upper(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_int_helper(num, 16));
}

/**
 * print_binary - Print an unsigned integer as a binary number.
 * @args: The list of arguments containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_int_helper(num, 2));
}

/**
 * get_print_function - Get the appropriate print function for a specifier.
 * @specifier: The format specifier to look for.
 *
 * Return: A pointer to the corresponding print function, or NULL if not found.
 */
print_func_t *get_print_function(char specifier)
{
	print_func_t *func = print_functions;

	while (func->specifier != 0)
	{
		if (func->specifier == specifier)
			return (func);
		func++;
	}
	return (NULL);
}
