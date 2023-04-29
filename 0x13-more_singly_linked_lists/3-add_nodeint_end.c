#include "lists.h"

/**
 * add_nodeint_end - add a new nodes at the end of a listint_t list.
 * @head: pointer to a pointers to the head of the list
 * @n: integer to be added to the new node
 *
 * Return: the address of the new elemenst, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *current;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	current = *head;
	while (current->next != NULL)
		current = current->next;

	current->next = new_node;

	return (new_node);
}
