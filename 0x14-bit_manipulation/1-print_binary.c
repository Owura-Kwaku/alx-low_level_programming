#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */

void print_binary(unsigned long int n)
{
	int index, counter = 0;
	unsigned long int current_value;


	for (index = 63; index >= 0; index--)
	{
		current_value = n >> index;


		if (current_value & 1)
		{
			_putchar('1');
			counter++;
		}
		else if (counter)
			_putchar('0');
	}

	if (!counter)
		_putchar('0');
}
