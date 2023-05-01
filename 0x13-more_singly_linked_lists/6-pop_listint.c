#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - function to remove head node
 * @head: double head pointer
 *
 *Return: Empty
 */
int pop_listint(listint_t **head)
{
	listint_t *start;
	int n;

	if (*head == NULL || head == NULL)
		return (0);
	start = *head;
	*head = start->next;
	n = start->n;
	free(start);
	return (n);
}
