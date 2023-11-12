#include "main.h"

/**
 * _puts - print a string
 * @args: List of arguments
 *
 * Return: size
 */
int _puts(va_list args)
{
	int len = 0;
	char *s;

	s = va_arg(args, char *);
	
	if (s == NULL)
	{
		s = "(null)";
	}

	while (s[len] != '\0')
		len += putchr(s[len]);

	return (len);
}
