#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

#endif
