#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc
 * @b: size of memory to allocate
 *
 * Return: pointer to allocated memory
 *         if malloc fails, exit with status value of 98
 */
void *malloc_checked(unsigned int b)
{
	void *new_ptr;

	new_ptr = malloc(b);
	if (new_ptr == NULL)
	exit(98);

	return (new_ptr);
}
