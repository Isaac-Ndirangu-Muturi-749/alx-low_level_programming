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

	/* Iterate through the linked list until NULL is reached*/
	while (h)
	{
		/* Print the value of the current node */
		printf("%d\n", h->n);

		/* Increment the count of nodes */
		count++;

		/* Move to the next node */
		h = h->next;
	}

	/* Return the number of nodes */
	return (count);
}
