#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 *               using the Jump search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located,
 *         or -1 if value is not present in array or if array is NULL.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t steps, h = 0, y = 0;

	if (!array)
		return (-1);
	steps = (size_t)sqrt(size);
	while ((y < size) && (*(array + y) < value))
	{
		printf("Value checked array[%d] = [%d]\n", (int)y, *(array + y));
		h = y;
		y += steps;
		if (h >= size)
			return (-1);
	}
	printf("Value found between indexes [%d] and [%d]\n", (int)h, (int)y);
	y = y >= size ? size - 1 : y;
	for (; (h <= y) && (*(array + h) <= value); h++)
	{
		printf("Value checked array[%d] = [%d]\n", (int)h, *(array + h));
		if (*(array + h) == value)
			return ((int)h);
	}
	return (-1);
}
