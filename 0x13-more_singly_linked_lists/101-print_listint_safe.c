#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - print a listint_t linkeds list.
 * @head: pointer to the heads of the list
 *
 * Return: the numbers of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head, *temp;

	while (current != NULL)
	{
		count++;
		printf("[%p] %d\n", (void *)current, current->n);
		temp = current;
		current = current->next;
		if (temp <= current)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			exit(98);
		}
	}
	return (count);
}

