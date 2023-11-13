#include "main.h"

/**
 * print_bin - convert an unsigned int into binary
 * @args: List of argument
 *
 * Return: count
 */
int print_bin(va_list args)
{
	unsigned int numb;
	int i = 0, j;
	int numbs[100];

	numb = va_arg(args, int);

	if (numb == 0)
	{
		putchr('0');
		return (1);
	}

	while (numb > 0)
	{
		numbs[i] = numb % 2;
		numb /= 2;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
		putchr(numbs[j] + '0');

	return (i);
}
