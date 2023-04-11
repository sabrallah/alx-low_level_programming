#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - allocates memory for a 2D array of integers
 * @width: the width of the array
 * @height: the height of the array
 *
 * Description: This function takes two arguments, width and height,
 * representing the dimensions of a 2D array. It allocates memory for
 * the array and initializes all elements to 0. If the allocation fails,
 * the function returns NULL.
 *
 * Return: a pointer to the allocated memory or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **ptr;
	int i, j;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	ptr = malloc(height * sizeof(int *));
	if (ptr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
	ptr[i] = malloc(width * sizeof(int));
	if (ptr[i] == NULL)
	{
	for (j = 0; j < i; j++)
	{
		free(ptr[j]);
	}
		free(ptr);
		return (NULL);
	}
	for (j = 0; j < width; j++)
	{
		ptr[i][j] = 0;
	}
	}

	return (ptr);
}
