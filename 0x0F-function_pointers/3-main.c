#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

int (*get_op_func(char *s))(int, int);

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments vector
 *
 * Return: 0 (Success), 98 (argc error), 99 (invalid operator), 100 (div/mod by 0)
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*operation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	operation = get_op_func(argv[2]);

	if (operation == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((operation == op_div || operation == op_mod) && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = operation(num1, num2);
	printf("%d\n", result);

	return (0);
}
