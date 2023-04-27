#include <stdio.h>

/**
 * pre_main - Prints the required text before the main function
 *
 * This function uses the constructor attribute to execute before the main
 * function and prints the required text.
 */
void __attribute__((constructor)) pre_main()
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
