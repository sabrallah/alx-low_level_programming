#include "search_algos.h"

/**
 * print_array - print the content of an array.
 * @array: the source of array to print.
 * @s: the left index of array.
 * @b: the right index of array.
 */
void print_array(int *array, size_t s, size_t b)
{
	size_t o;

	if (array)
	{
		printf("Searching in array: ");
		for (o = s; o < s + (b - s + 1); o++)
			printf("%d%s", *(array + o), o < s + (b - s) ? ", " : "\n");
	}
}

/**
 * binary_search_index1 - Searche a value in a sorte array using \
 * a binary search.
 * @array: array to search in.
 * @s: left index of the array.
 * @b: right index of the array.
 * @value: value to look for.
 *
 * Return: first index of the value in the array, otherwise -1.
 */
int binary_search_index1(int *array, size_t s, size_t b, int value)
{
	size_t n;

	if (!array)
		return (-1);
	print_array(array, s, b);
	n = s + ((b - s) / 2);
	if (s == b)
		return (*(array + n) == value ? (int)n : -1);
	if (value < *(array + n))
	{
		return (binary_search_index1(array, s, n - 1, value));
	}
	else if (value == *(array + n))
	{
		return ((int)n);
	}
	else
	{
		return (binary_search_index1(array, n + 1, b, value));
	}
}

/**
 * exponential_search - searches value sorted array using \
 * an exponential search.
 * @array: array to search in.
 * @size: length of the array.
 * @value: value to look for.
 *
 * Return: index of the value in the array, otherwise -1.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t lower = 1, higher = 2;

	if (!array || !size)
		return (-1);
	if (size < 2)
	{
		lower = 0;
		higher = 1;
	}
	else
	{
		while (lower < size)
		{
			printf("Value checked array[%lu] = [%d]\n", lower, array[lower]);
			if (
				((array[lower] <= value) && (array[higher] >= value))
				|| ((lower * 2) >= size)
				)
				break;
			lower *= 2;
			higher = higher * 2 < size ? higher * 2 : size - 1;
		}
	}
	printf("Value found between indexes [%lu] and [%lu]\n", lower, higher);
	return (binary_search_index1(array, lower, higher, value));
}
