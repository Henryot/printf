#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_pointer - Prints a pointer address to the standard output.
 * @ptr: The pointer address to be printed.
 *
 * Return: The number of characters printed.
 */
int print_pointer(void *ptr)
{
	unsigned long int address = (unsigned long int)ptr;
	int count = 0;

	_putchar('0');
	_putchar('x');
	count += 2;

	if (address == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		count += print_hex((unsigned int)(address), 0);
	}

	return count;
}
