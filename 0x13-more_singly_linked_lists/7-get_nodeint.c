#include "lists.h"

/**
 * get_nodeint_at_index - function to get the last node
 * of a listint_t linked list.
 * @head: head pointer
 * @index: index node
 *
 * Return: index pointer
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int node = 0;

	if (head == NULL)
		return (NULL);
	while (node < index)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
		node++;
	}
	return (head);
}
