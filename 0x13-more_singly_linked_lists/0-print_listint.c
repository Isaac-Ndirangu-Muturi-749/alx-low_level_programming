#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to the listint_t list to print
 *
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
    size_t count = 0;

    /* Traverse the list */
    while (h)
    {
        /* Print the current node's value */
        printf("%d\n", h->n);

        /* Move to the next node */
        h = h->next;

        /* Increment the count of nodes */
        count++;
    }

    /* Return the number of nodes */
    return (count);
}
