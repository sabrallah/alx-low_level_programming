#include "main.h"

/**
 * get_bit - get the values of an bits at a given index
 * @n: the numbers to a check
 * @index: the index of the bits to get
 *
 * Return: the value of the bit at the given index, or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	return ((n >> index) & 1);
}
