#include "main.h"

/**
 * set_bit - set the values of a bit at a given index
 * @n: the numbers to modify
 * @index: the index of a the bit to set
 *
 * Return: 1 if successful, or -1 otherwise
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	*n |= (1UL << index);
	return (1);
}
