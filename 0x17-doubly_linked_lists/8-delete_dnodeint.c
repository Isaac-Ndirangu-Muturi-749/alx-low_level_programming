#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index in a dlistint_t linked list.
 *
 * @head: A pointer to a pointer to the head of the list.
 * @index: The index of the node to be deleted. Index starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	current = *head;
	if (index == 0)
	{
		/* If the first node needs to be deleted */
		*head = current->next; /* Update head to the next node */
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	if (current->next != NULL)
		current->next->prev = current->prev;

	current->prev->next = current->next;

	free(current);
	return (1);
}
