#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - function that removes the node
 * at a given index
 * @head: double head pointer
 * @index: index node
 *
 * Return: index node pointer
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *temp, *next;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
		return (1);
	}
	temp = *head;
	while (count < index - 1)
	{
		if (temp->next == NULL)
			return (-1);
		temp = temp->next;
		count++;
	}
	next = temp->next;
	temp->next = next->next;
	free(next);
	return (1);
}
