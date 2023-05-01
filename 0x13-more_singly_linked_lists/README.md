-task0/ function that prints all the elements of a listintt list.
-Task1/ Write a function that returns the number of elements in a linked listintt list
-TASK2 / Write a function that adds a new node at the beginning of a listintt list
-TASK3 /  Write a function that adds a new node at the end of a listintt list.

Prototype: listintt *add_nodeint_end(listint_t **head, const int n);
Return: the address of the new element, or NULL if it failed

-TASK4 : / Write a function that frees a listint_t list.

Prototype: void free_listint(listint_t *head);

-task 5 : Write a function that frees a listintt list.

	  Prototype: void freelistint2(listintt **head);
	  The function sets the head to NULL


-task6 : Write a function that deletes the head node of a listint-t linked list, and returns the head node’s data (n).

	Prototype: int poplistint(listintt **head);
	if the linked list is empty return 0


-task7 : Write a function that returns the nth node of a listint_t linked list.

Prototype: listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);
where index is the index of the node, starting at 0
if the node does not exist, return NULL


-TASK 8 : Write a function that inserts a new node at a given position.

Prototype: listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);
where idx is the index of the list where the new node should be added. Index starts at 0
Returns: the address of the new node, or NULL if it failed
if it is not possible to add the new node at index idx, do not add the new node and return NULL



task 10 : Write a function that deletes the node at index index of a listint_t linked list.

Prototype: int delete_nodeint_at_index(listint_t **head, unsigned int index);
where index is the index of the node that should be deleted. Index starts at 0
Returns: 1 if it succeeded, -1 if it failed



-TASK 100 ADVANCED : Write a function that reverses a listint_t linked list.

Prototype: listint_t *reverse_listint(listint_t **head);
Returns: a pointer to the first node of the reversed list
You are not allowed to use more than 1 loop.
You are not allowed to use malloc, free or arrays
You can only declare a maximum of two variables in your function



-TASK 101 : Write a function that prints a listint_t linked list.

Prototype: size_t print_listint_safe(const listint_t *head);
Returns: the number of nodes in the list
This function can print lists with a loop
You should go through the list only once
If the function fails, exit the program with status 98


TASK 102 : Write a function that frees a listint_t list.

Prototype: size_t free_listint_safe(listint_t **h);
This function can free lists with a loop
You should go though the list only once
Returns: the size of the list that was free’d
The function sets the head to NULL
