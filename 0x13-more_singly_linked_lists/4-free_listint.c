#include "lists.h"

/**
 * free_listint - frees a listint_t list.
 * @head: pointer to the heads of the list
 *
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
