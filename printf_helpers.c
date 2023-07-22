#include "printf_helpers.h"
#include <stdio.h>

/**
 * print_char - Print a character.
 *
 * @args: The va_list containing the character to be printed.
 * @buffer: The buffer to store the output.
 * @buffer_size: The size of the buffer.
 *
 * Return: The number of characters printed.
 */
int print_char(va_list args, char *buffer, int buffer_size)
{
	char c = va_arg(args, int);

	if (buffer_size > 0)
	{
		buffer[0] = c;
		return 1;
	}

	return 0;
}

/**
 * print_string - Print a string.
 *
 * @args: The va_list containing the string to be printed.
 * @buffer: The buffer to store the output.
 * @buffer_size: The size of the buffer.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args, char *buffer, int buffer_size)
{
	const char *str = va_arg(args, const char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	for (int i = 0; str[i] != '\0' && i < buffer_size - 1; i++)
	{
		buffer[i] = str[i];
		count++;
	}

	return count;
}

/**
 * print_int_helper - Print an integer in the given base.
 *
 * @num: The integer to be printed.
 * @base: The base for conversion (e.g., 10 for decimal).
 *
 * Return: The number of characters printed.
 */
int print_int_helper(unsigned int num, unsigned int base)
{
	/* For demonstration, we will print the integer in decimal (base 10).
	   You can replace this implementation with other bases (e.g., octal, hexadecimal). */
	int count = 0;
	char buffer[32]; // Buffer to hold the converted number
	int i = 0;

	if (num == 0)
	{
		buffer[i++] = '0';
		return 1;
	}

	while (num > 0 && i < sizeof(buffer))
	{
		int rem = num % base;
		buffer[i++] = (rem < 10) ? (rem + '0') : (rem - 10 + 'a');
		num /= base;
	}

	// Print the number in reverse order
	for (int j = i - 1; j >= 0; j--)
	{
		buffer[i++] = buffer[j];
		count++;
	}

	return count;
}

/**
 * print_int - Print a signed integer.
 *
 * @args: The va_list containing the integer to be printed.
 * @buffer: The buffer to store the output.
 * @buffer_size: The size of the buffer.
 *
 * Return: The number of characters printed.
 */
int print_int(va_list args, char *buffer, int buffer_size)
{
	int num = va_arg(args, int);
	unsigned int positive_num;

	if (num < 0)
	{
		if (buffer_size > 0)
			buffer[0] = '-';
		return 1 + print_int_helper(-num, 10);
	}
	else
	{
		positive_num = num;
		return print_int_helper(positive_num, 10);
	}
}

/**
 * print_binary - Print an unsigned integer in binary.
 *
 * @args: The va_list containing the integer to be printed in binary.
 * @buffer: The buffer to store the output.
 * @buffer_size: The size of the buffer.
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list args, char *buffer, int buffer_size)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	if (buffer_size <= 0)
		return 0;

	for (int i = 31; i >= 0 && count < buffer_size - 1; i--)
	{
		buffer[count++] = (num & (1 << i)) ? '1' : '0';
	}

	return count;
}
