#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int index, counter = 0;
	unsigned long int current_value;
	unsigned long int exclusive_value = n ^ m;


	for (index = 63; index >= 0; index--)
	{
		current_value = exclusive_value >> index;
		if (current_value & 1)
			counter++;
	}


	return (counter);
}
