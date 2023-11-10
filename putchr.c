#include "main.h"

/**
 * putchr - print a character
 * @c: Character to print
 *
 * Return: int
 */
int putchr(char c)
{
	return (write(1, &c, 1));
}
