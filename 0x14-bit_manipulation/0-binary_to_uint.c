#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary numbers to a unsigned int.
 * @b: A string containin a binarys number.
 *
 * Return: The converted number, or 0 if there is one or more chars
 * in the string b that is not 0 or 1, or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (!b)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		result <<= 1;
		result += (*b - '0');
		b++;
	}

	return (result);
}
