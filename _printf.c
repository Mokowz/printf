#include "main.h"

/**
 * print_operations - check whether the specifier exist
 * @format: String beign passed in the funct
 * @print_ops: List of operations tocheck
 * @args: List of arguments to print
 *
 * Return: int
 */
int print_operations(const char *format, formats_t *print_ops, va_list args)
{
	int i = 0, count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			while (print_ops[i].type != NULL && *format != *(print_ops[i].type))
				i++;

			if (print_ops[i].type != NULL)
			{
				count += print_ops[i].func(args);
			}
			else
			{
				if (*format == '\0')
					return (-1);
				if (*format != '%')
					count += putchr('%');
				count += putchr(*format);
			}
		}
		else
		{
			count += putchr(*format);
		}
		format++;
	}
	return (count);
}

/**
 * _printf - acts as the printf function and outputs to the stdout
 * @format: The format string to be printed
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	formats_t operations[] = {
		{"c", print_chr},
		{"s", _puts},
		{"d", print_d},
		{"i", print_i},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count  = print_operations(format, operations, args);
	va_end(args);

	return (count);
}
