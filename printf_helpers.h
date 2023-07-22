#ifndef PRINTF_HELPERS_H
#define PRINTF_HELPERS_H

#include <stdarg.h>

typedef struct print_func {
    char specifier;
    int (*func)(va_list);
} print_func_t;

print_func_t *get_print_function(char specifier);

int print_char(va_list args);
int print_string(va_list args);
int print_int_helper(unsigned int num, unsigned int base);
int print_int(va_list args);
int print_unsigned_int(va_list args);
int print_octal(va_list args);
int print_hexadecimal(va_list args);
int print_hexadecimal_upper(va_list args);
int print_binary(va_list args);

#endif /* PRINTF_HELPERS_H */
