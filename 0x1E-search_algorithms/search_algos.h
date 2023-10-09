#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * struct listint_s - Singly linked list.
 * @n: Integer stored at the node.
 * @index: Index of the node in the list.
 * @next: Pointer to the next node.
 *
 * Description: Singly linked list node structure.
 */
typedef struct listint_s
{
	/* Integer stored at the node. */
	int n;
	/* Index of the node in the list. */
	size_t index;
	/* Pointer to the next node. */
	struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - Singly linked list with an express lane.
 * @n: Integer stored at the node.
 * @index: Index of the node in the list.
 * @next: Pointer to the next node.
 * @express: Pointer to the next node in the express lane.
 *
 * Description: Singly linked list node structure with an express lane.
 */
typedef struct skiplist_s
{
	/* Integer stored at the node. */
	int n;
	/* Index of the node in the list. */
	size_t index;
	/* Pointer to the next node. */
	struct skiplist_s *next;
	/* Pointer to the next node in the express lane. */
	struct skiplist_s *express;
} skiplist_t;

int linear_search(int *array, size_t size, int value);

#endif /*SEARCH_ALGOS_H */
