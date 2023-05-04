#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned int size = sizeof(n) * 8;
	unsigned int i;
	int flag = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (i = size; i > 0; i--)
	{
		if ((n & (1 << (i - 1))) != 0)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag)
			_putchar('0');
	}

}
