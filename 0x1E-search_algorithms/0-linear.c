#include "search_algos.h"

/**
 * linear_search - searches for value in array of
 * integers using Linear to search algorithm
 *
 * @array: input array
 * @size: size the array
 * @value: value search in
 * Return: always EXIT_SUCCESS
 */
int linear_search(int *array, size_t size, int value)
{
	int i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < (int)size; i++)
	{
		printf("Value checked array[%u] = [%d]\n", i, array[i]);
		if (value == array[i])
			return (i);
	}
	return (-1);
}
