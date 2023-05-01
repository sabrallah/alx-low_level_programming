#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - delete a nodes at a given indx in a linked list
 * @head: double pointer to the head of the linked list
 * @index: index of the nods to delete, starting at 0
 * Return: 1 if successful, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *previous;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;
	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	for (i = 0; current != NULL && i < index; i++)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
		return (-1);

	previous->next = current->next;
	free(current);
	return (1);
}
