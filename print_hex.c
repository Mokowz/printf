#include "main.h"

/**
 * hex_to_str - convert number to str
 * @num: Number to convert
 * @hex: Base 16
 * @chr: Characters
 *
 * Return: NUmber of characters tha have been printed
 */
int hex_to_str(unsigned int num, unsigned int hex, char chr)
{
	char hexadec;
	unsigned int rem = num % hex;
	unsigned int sub = num / hex;

	if (rem > 10)
		hexadec = (rem - 10) + chr;
	else
		hexadec = rem + '0';

	if (sub == 0)
		return (putchr(hexadec));

	if (sub < hex)
	{
		if (sub > 10)
			return (putchr(sub - 10 + chr) + putchr(hexadec));
		return (putchr(sub + '0') + putchr(hexadec));
	}

	return (hex_to_str(sub, hex, chr) + putchr(hexadec));
}

/**
 * print_hex_u - print int uppercase
 * @args: List of arguments
 *
 * Return: Characters printed
 */
int print_hex_u(va_list args)
{
	return (hex_to_str(va_arg(args, unsigned int), 16, 'A'));
}

/**
 * print_hex_l - print in lower case
 * @args: List of arguments
 * Return: Characters printed
 */
int print_hex_l(va_list args)
{
	return (hex_to_str(va_arg(args, unsigned int), 16, 'a'));
}
