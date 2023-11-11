#include "main.h"

/**
 * _printf - acts as the printf function and outputs to the stdout
 * @format: The format string to be printed
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	unsigned int i, str_count, count = 0;
	va_list args;


	if (((format[0] == '%') && (format[1] == '\0')) || !format)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchr(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			putchr(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == '%')
		{
			putchr('%');
			i++;
		}
		else if (format[i + 1] == 's')
		{
			str_count = _puts(va_arg(args, char *));
			i++;
			count += (str_count - 1);
		}
		count += 1;

	}

	va_end(args);

	return (count);
}
