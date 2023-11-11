#include "main.h"

/**
 * _printf - acts as the printf function and outputs to the stdout
 * @format: The format string to be printed
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	unsigned int count = 0;
	va_list args;


	if (((format[0] == '%') && (format[1] == '\0')) || !format)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					count += putchr(va_arg(args, int));
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					break;
				case '%':
					count += putchr(*format);
					break;
				default:
					count += putchr('%');
					count += putchr(*format);
					break;
			}
		

		}
		else
		{
			count += putchr(*format);
		}

		format++;
	}

	va_end(args);

	return (count);
}
