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
	size_t i, jump;

	if (array == NULL)
		return (-1);

	jump = sqrt(size);
	for (i = 0; i < size; i += jump)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n", i - jump, i);
			for (i -= jump; i < size && array[i] <= value; ++i)
			{
				printf("Value checked array[%lu] = [%d]\n", i, array[i]);
				if (array[i] == value)
					return (i);
			}
			break;
		}
	}
	printf("Value found between indexes [%lu] and [%lu]\n", i - jump, i);
	return (-1);
}
