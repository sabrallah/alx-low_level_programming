#include "main.h"

/**
 * flip_bits - return the numbers of bits you would needs to flip to get a from one number to another.
 * @n: unsigned long int value 1
 * @m: unsigned long int value 2
 *
 * Return: the number of bit you would needs to flips to gets from one number to another.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bits_to_flip = n ^ m; /* XOR operation to get the bits that differ */
	unsigned int count = 0;

	while (bits_to_flip)
	{
		count += bits_to_flip & 1; /* count the number of bits that are set to 1 */
		bits_to_flip >>= 1; /* shift right by 1 to check the next bit */
	}

	return (count);
}
