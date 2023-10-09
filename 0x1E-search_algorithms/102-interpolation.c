#include "search_algos.h"

/**
 * interpolation_search - searche value in a sorte arrays using \
 * an interpolation search.
 * @array: the array search in.
 * @size: the length of array.
 * @value: the value to look for.
 *
 * Return: first index of value in array, otherwise -1.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t lower = 0, higher = size - 1, posi = 0;
	double tmps;

	if (!array)
		return (-1);
	while (array[higher] != array[lower])
	{
		tmps = (double)(higher - lower) / (array[higher] - array[lower]);
		posi = lower + (tmps * (value - array[lower]));
		if (posi >= size)
		{
			printf("Value checked array[%d] is out of range\n", (int)posi);
			break;
		}
		printf("Value checked array[%d] = [%d]\n", (int)posi, array[posi]);
		if (array[posi] == value)
			return (posi);
		else if (array[posi] < value)
			lower = posi + 1;
		else
			higher = posi - 1;
	}
	return (value == array[lower] ? (int)lower : -1);
}
