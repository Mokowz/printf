#include "main.h"

/**
 * print_chr - print a character and return bytes
 * @args: List of arguments
 *
 * Return: count
 */
int print_chr(va_list args)
{
	return (putchr(va_arg(args, int)));
}
