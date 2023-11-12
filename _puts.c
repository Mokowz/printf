#include "main.h"

/**
 * _puts - print a string
 * @s: String
 *
 * Return: size
 */
int _puts(char *s)
{
	int total_count = 0;

	if (s)
	{
		write(1, s, strlen(s));
		total_count += strlen(s);
	}

	return (total_count);
}
