/* printf.h */
#ifndef PRINTF_H
#define PRINTF_H

int _putchar(char c);
int print_normal_char(char ch);
int print_string(char *str);
int print_positive_int(unsigned int num);
int print_int(va_list args);
int print_format(const char *format, va_list args);
int _printf(const char *format, ...);

#endif /* PRINTF_H */
