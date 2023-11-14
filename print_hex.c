#include "main.h"
/**
 * print_hex - prints a hexadecimal number
 * @va: argument
 * Return: count
 */
int print_hex(va_list va)
{
	int i;
	int count = 0;
	int *array;
	unsigned int num = va_arg(va, unsigned int);
	unsigned int tem = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	array = malloc(sizeof(int) * count);

	for (i = 0; i < count; i++)
	{
		array[i] = tem % 16;
		tem /= 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		putchr(array[i] + '0');
	}
	free(array);
	return (count);
}
