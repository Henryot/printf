#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer to the standard output.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(unsigned int n)
{
	unsigned int divisor = 1;
	int count = 0;

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

/**
 * print_octal - Prints an unsigned integer in octal format to the standard output.
 * @n: The unsigned integer to be printed in octal format.
 *
 * Return: The number of characters printed.
 */
int print_octal(unsigned int n)
{
	unsigned int octalNum[100];
	unsigned int i = 0;
	int count = 0;

	/* Convert the integer to octal */
	while (n != 0)
	{
		octalNum[i] = n % 8;
		n /= 8;
		i++;
	}

	if (i == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		for (i = i - 1; i > 0; i--)
		{
			_putchar('0' + octalNum[i]);
			count++;
		}
		_putchar('0' + octalNum[0]);
		count++;
	}

	return count;
}

/**
 * print_hex - Prints an unsigned integer in hexadecimal format to the standard output.
 * @n: The unsigned integer to be printed in hexadecimal format.
 * @uppercase: A flag to indicate whether to print the letters in uppercase (1) or lowercase (0).
 *
 * Return: The number of characters printed.
 */
int print_hex(unsigned int n, int uppercase)
{
	char hex[100];
	int temp, i = 0, j;
	int count = 0;

	/* Convert the integer to hexadecimal */
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			hex[i] = temp + '0';
		else
			hex[i] = (uppercase ? 'A' : 'a') + temp - 10;
		n /= 16;
		i++;
	}

	if (i == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		for (j = i - 1; j >= 0; j--)
		{
			_putchar(hex[j]);
			count++;
		}
	}

	return count;
}
