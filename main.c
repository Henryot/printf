#include "main.h"
#include "printf_helpers.h"


/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int n = 98;
    _printf("Decimal: %d\n", n);
    _printf("Unsigned Decimal: %u\n", n);
    _printf("Octal: %o\n", n);
    _printf("Lowercase Hexadecimal: %x\n", n);
    _printf("Uppercase Hexadecimal: %X\n", n);
    return (0);
}
