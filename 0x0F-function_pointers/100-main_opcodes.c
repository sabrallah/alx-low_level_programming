#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: 0 if successful, 1 if incorrect number of arguments,
 * 2 if negative bytes
 */
int main(int argc, char *argv[])
{
	int i;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	int num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	unsigned char *main_func_ptr = (unsigned char *)main;

	for (i = 0; i < num_bytes; ++i)
	{
		printf("%02x", main_func_ptr[i]);
		if (i != num_bytes - 1)
		{
			putchar(' ');
		}
	}

	putchar('\n');
	return (0);
}
