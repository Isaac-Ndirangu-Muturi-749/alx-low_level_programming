#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: double pointer to the head of the list
 *
 * Return: pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;  /* Pointer to the previous node */
	listint_t *current = *head;  /* Pointer to the current node */
	listint_t *next;  /* Pointer to the next node */

	while (current != NULL)
	{
		next = current->next;  /* Store the next node */
		/* Reverse the pointer of the current node to previous node */
		current->next = prev;
		prev = current;  /* Move prev to the current node */
		current = next;  /* Move current to the next node */
	}

	*head = prev;  /* Update the head pointer to point to new first node */
	return (*head);  /* Return the new head of the reversed list */
}
