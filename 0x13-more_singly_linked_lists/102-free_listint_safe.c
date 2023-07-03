#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current, *temp;

	/* Check if the list or head pointer is NULL */
	if (h == NULL || *h == NULL)
		return (size);

	/* Start with the head of the list */
	current = *h;

	/* Traverse the list */
	while (current != NULL)
	{
		size++; /* Increment the size of the list */

		/* Check if a loop is encountered */
		if (current->next >= current)
		{
			/* Break the loop */
			temp = current;
			current = current->next;
			temp->next = NULL;
			free(temp);
			*h = NULL; /* Set the head pointer to NULL */
			break;
		}
		else
		{
			/* Move to the next node and free the current node */
			temp = current;
			current = current->next;
			free(temp);
		}
	}

	return (size);
}
