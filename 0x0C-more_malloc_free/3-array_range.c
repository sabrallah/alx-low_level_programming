#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers
 * @min: minimum value
 * @max: maximum value
 *
 * Return: pointer to newly created array
 *         NULL if malloc fails or if min > max
 */
int *array_range(int min, int max)
{
	int *arr;
	int i;

	if (min > max)
	return (NULL);

	arr = malloc(sizeof(int) * (max - min + 1));
	if (arr == NULL)
	return (NULL);

	for (i = 0; i <= max - min; i++)
		arr[i] = min + i;

	return (arr);
}
