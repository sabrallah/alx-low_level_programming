#include "search_algos.h"

/**
 * print_array - print contents of array.
 * @array: source of array to print.
 * @k: left index of array.
 * @s: right index of array.
 */
void print_array(int *array, size_t k, size_t s)
{
	size_t h;

	if (array)
	{
		printf("Searching in array: ");
		for (h = k; h < k + (s - k + 1); h++)
			printf("%d%s", *(array + h), h < k + (s - k) ? ", " : "\n");
	}
}

/**
 * binary_search_index - searche value sorted array using \
 * a binary search.
 * @array: array search in.
 * @k: left index of array.
 * @s: right index of array.
 * @value: value to look for.
 *
 * Return: first index of the value in the array, otherwise -1.
 */
int binary_search_index(int *array, size_t k, size_t s, int value)
{
	size_t n;

	if (!array)
		return (-1);
	print_array(array, k, s);
	n = k + ((s - k) / 2);
	if (k == s)
		return (*(array + n) == value ? (int)n : -1);
	if (value < *(array + n))
	{
		return (binary_search_index(array, k, n, value));
	}
	else if (value == *(array + n))
	{
		if ((n > 0) && (*(array + n - 1) == value))
		{
			return (binary_search_index(array, k, n, value));
		}
		return ((int)n);
	}
	else
	{
		return (binary_search_index(array, n + 1, s, value));
	}
}

/**
 * advanced_binary - searche value a sorted array using binary search.
 * @array: array to search.
 * @size: length of array.
 * @value: value look for.
 *
 * Return: first index of the value in the array, otherwise -1.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || !size)
		return (-1);
	else if ((size == 1) && (*array == value))
		return (0);
	return (binary_search_index(array, 0, size - 1, value));
}
