#include "main.h"
/**
 * print_Hex - prints a hexadecimal number
 * @num: argument
 * Return: count
 */
int print_Hex(unsigned long int num)
{
	long int i;
	long int *array;
	long int count = 0;
	unsigned long int tem = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	array = malloc(sizeof(long int) * count);

	for (i = 0; i < count; i++)
	{
		array[i] = tem % 16;
		tem = tem / 16;
	}
	for (i = count - 1; 1 >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		putchr(array[i] + '0');
	}
	free(array);
	return (count);
}
