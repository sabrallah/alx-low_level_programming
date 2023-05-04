#include "main.h"
#include <stdio.h>

/**
 * print_binary - Print the binary representation of a number.
 * @n: The unsigned long integer to be converted and printed.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(n) * 8 - 1);

	while (mask)
	{
		if (n & mask)
		{
			_putchar('1');
		}
		else
		{
			_putchar('0');
		}
	mask >>= 1;
	}
}
