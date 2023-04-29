#include "lists.h"

/**
 * listint_len - return the number of element in an linked listint_t list.
 * @h: pointer to the head of the list
 *
 * Return: number of elements in the lists
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;
	const listint_t *current = h;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
