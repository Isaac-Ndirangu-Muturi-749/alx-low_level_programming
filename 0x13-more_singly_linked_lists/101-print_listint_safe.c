#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list (handles loops)
 * @head: Pointer to the head node of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	/* Declare two pointers: slow and fast */
	const listint_t *slow, *fast;
	size_t count = 0; /* keep track of the number of nodes */

	/* Initialize slow and fast to the head of the list */
	slow = head;
	fast = head;

	/* Iterate as long as slow, fast, and fast->next are not NULL */
	while (slow && fast && fast->next)
	{
		/* Move slow one step forward */
		slow = slow->next;

		/* Move fast two steps forward */
		fast = fast->next->next;

		/* Check if slow and fast have the same address */
		if (slow == fast)
		{
			/* If there's a loop, print the loop node information */
			printf("-> [%p] %d\n", (void *)slow, slow->n);

			/* Exit the program with status 98 */
			exit(98);
		}

		/* Print the current node information */
		printf("[%p] %d\n", (void *)slow, slow->n);

		/* Increment the count variable */
		count++;
	}

	/* Return the number of nodes */
	return (count);
}
