#include <math.h>
#include "search_algos.h"

/**
 * nget_n_next - get the nth node next to given node.
 * @node: the start node.
 * @n: the number positions next to node.
 *
 * Return: the node n places next to given node, \
 * otherwise last node or NULL.
 */
listint_t *nget_n_next(listint_t *node, size_t n)
{
	size_t k = 0;
	listint_t *res = NULL;

	res = node;
	for (k = 0; (k < n) && (res) && (res->next); k++)
		res = res->next;
	return (res);
}

/**
 * jump_list - searche value in sorted linked list using jump search.
 * @list: the linked list search in.
 * @size: the length of linked list.
 * @value: the value look for.
 *
 * Return: the node with value in linked list, otherwise NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, z = 0, o = 0;
	listint_t *node, *next;

	if (!list)
		return (NULL);
	step = (size_t)sqrt(size);
	node = list;
	next = nget_n_next(node, step);
	while (node)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)next->index, next->n);
		if ((next->n >= value) || (!next->next))
			break;
		node = next;
		next = nget_n_next(node, step);
	}
	z = node->index;
	o = next->index;
	printf("Value found between indexes [%d] and [%d]\n", (int)z, (int)o);
	while (node)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)node->index, node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}
