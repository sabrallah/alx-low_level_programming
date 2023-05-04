#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip to get from
 * number to another.
 * @n: unsigned long int value 1
 * @m: unsigned long int value 2
 *
 * Return: the number of bits you would need to flip to get from one number to
 * another.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bits_to_flip = n ^ m; /* XOR to get bits that differ */
	unsigned int count = 0;

	while (bits_to_flip)
	{
		count += bits_to_flip & 1; /* count bits set to 1 */
		bits_to_flip >>= 1; /* shift right to check the next bit */
	}

	return (count);
}
