#include <stdio.h>

/**
 * main - prints the number of arguments passed into it
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	printf("%d\n", argc - 1); /* subtract 1 to exclude the program name */
	return (argv != NULL); /* return 0 if argv is not NULL */
}
