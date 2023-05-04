#include "main.h"

/**
 * clear_bit - sets the values of an bit to 0 at a given index
 * @n: pointer to the numbers
 * @index: index, starting from 0 of the bits you want to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8) /* check if index is valid */
	return (-1);

	*n &= ~(1 << index); /* set bit at index to 0 */

	return (1);
}
