#include "main.h"

/**
 * _printf - acts as the printf function and outputs to the stdout
 * @format: The format string to be printed
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	int count = 0;
	char *str;
	va_list args;

	if (((format[0] == '%') && (format[1] == '\0')) || !format || format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
			else if (*format == 'c')
			{
				putchr(va_arg(args, int));
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				write(1, str, strlen(str));
				count += strlen(str);
			}
		} format++;
	}
	va_end(args);
	return (count);
}
