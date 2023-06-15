#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char password[7], *codebook;
	int length = strlen(argv[1]), i, temp;

	codebook = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	temp = (length ^ 59) & 63;
	password[0] = codebook[temp];

	temp = 0;
	for (i = 0; i < length; i++)
		temp += argv[1][i];
	password[1] = codebook[(temp ^ 79) & 63];

	temp = 1;
	for (i = 0; i < length; i++)
		temp *= argv[1][i];
	password[2] = codebook[(temp ^ 85) & 63];

	temp = 0;
	for (i = 0; i < length; i++)
	{
		if (argv[1][i] > temp)
			temp = argv[1][i];
	}
	srand(temp ^ 14);
	password[3] = codebook[rand() & 63];

	temp = 0;
	for (i = 0; i < length; i++)
		temp += (argv[1][i] * argv[1][i]);
	password[4] = codebook[(temp ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		temp = rand();
	password[5] = codebook[(temp ^ 229) & 63];

	password[6] = '\0';
	printf("%s", password);
	return (0);
}
