#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: A pointer to a pointer to the head of the list.
 * @idx: The index at which the new node should be inserted.
 * @n: The value to be stored in the new node.
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp = *h;
	unsigned int i = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	while (temp != NULL)
	{
		if (i == idx)
		{
			new_node->prev = temp->prev;
			new_node->next = temp;
			if (temp->prev != NULL)
				temp->prev->next = new_node;
			temp->prev = new_node;
			if (i == 1) /* Update the head if the new node is inserted at index 1 */
				*h = new_node;
			return (new_node);
		}

		i++;
		temp = temp->next;
	}

	free(new_node);
	return (NULL);
}
