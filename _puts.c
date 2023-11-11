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
		for (total_count = 0; s[total_count] != '\0'; total_count++)
		{
			putchr(s[total_count]);
		}
	}

	return (total_count);
}
