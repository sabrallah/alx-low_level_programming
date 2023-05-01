#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list, even with a loop
 * @h: pointer to the head of the list
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *slow, *fast, *prev;
    int loop_size, i;

    if (h == NULL || *h == NULL)
        return (0);

    slow = *h;
    fast = *h;
    prev = NULL;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (slow == NULL || fast == NULL || fast->next == NULL)
    {
        slow = *h;
        while (slow != NULL)
        {
            prev = slow;
            slow = slow->next;
            free(prev);
            count++;
        }
    }
    else
    {
        slow = *h;
        while (slow != fast)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            free(prev);
            count++;
        }

        loop_size = 1;
        fast = slow->next;
        while (slow != fast)
        {
            fast = fast->next;
            loop_size++;
        }

        for (i = 0; i < loop_size; i++)
        {
            prev = slow;
            slow = slow->next;
            free(prev);
            count++;
        }
    }

    *h = NULL;
    return (count);
}
