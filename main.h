#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* For va_list */

/* putchar.c */
int _putchar(char c);

/* printf.c */
int print_format(const char *format, va_list args);
int _printf(const char *format, ...);

/* printf_helpers.c */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif /* MAIN_H */
