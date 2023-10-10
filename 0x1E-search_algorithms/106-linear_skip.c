#include "search_algos.h"

/**
 * linear_skip - searches for a value in a skip list
 *
 * @list: input a list
 * @value: a value search in
 * Return: an index of number
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *h;

	if (list == NULL)
		return (NULL);

	h = list;

	do {
		list = h;
		h = h->express;
		printf("Value checked at index ");
		printf("[%d] = [%d]\n", (int)h->index, h->n);
	} while (h->express && h->n < value);

	if (h->express == NULL)
	{
		list = h;
		while (h->next)
			h = h->next;
	}

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)list->index, (int)h->index);

	while (list != h->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
