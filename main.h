#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct formatter - check for formats
 * @type: Fomrat to print
 * @func: Print function to use there
 */
typedef struct formatter
{
	char *type;
	int (*func)();
} formats_t;

int print_chr(va_list args);
int print_operations(const char *format, formats_t *print_ops, va_list args);
int _printf(const char *format, ...);
int putchr(char c);
int _puts(va_list args);
int print_d(va_list args);
int print_bin(va_list args);
int print_i(va_list args);
int print_unsigned(va_list args);

#endif
