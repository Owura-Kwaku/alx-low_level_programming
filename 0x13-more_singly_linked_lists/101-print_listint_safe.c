#include "lists.h"

/**
 * print_listint_safe - function that returns all
 * the values of a listint_t list.
 * @head: pointer to first node of a listint_t list.
 *
 * Return: a size_t number representing the amount of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t counter = 0;

	if (head == NULL)
		return (0);

	do
	{
		count++;
		printf("[%p] %d\n", (void *)head, head->n);
		if (head->next >= head)
		{
			printf("-> [%p] %d\n", (void *)head->next, (head->next)->n);
			break;
		}
		head = head->next;
	} while (head != NULL);

	return (counter);
}
