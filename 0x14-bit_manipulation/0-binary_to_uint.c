#include "main.h"

/**
 * binary_to_uint -converts a binary number to an unsigned int.
 * @b: pointing to a string of 0 and 1 chars
 *
 * Return:converted number, or 0
 */

unsigned int binary_to_uint(const char *b)
{
	int index;
	unsigned int decimal_value = 0;


	if (!b)
		return (0);


	for (index = 0; b[index]; index++)
	{
		if (b[index] < '0' || b[index] > '1')
			return (0);
		decimal_value = 2 * decimal_value + (b[index] - '0');
	}


	return (decimal_value);
}
