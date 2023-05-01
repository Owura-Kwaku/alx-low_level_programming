#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - function that inserts a new node
 * at a given postion
 * @head: double head pointer
 * @idx: index node
 * @n: new node value
 *
 * Return: new node adddress
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int count = 0;
	listint_t *temporarynode, *newnode;

	if (head == NULL)
		return (NULL);
	if (idx != 0)
	{
		temporarynode = *head;
		while (count < idx - 1 && temporarynode != NULL)
		{
			temporarynode = temporarynode->next;
			count++;
		}
		if (temporarynode == NULL)
			return (NULL);
	}
	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	if (idx == 0)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}
	newnode->next = temporarynode->next;
	temporarynode->next = newnode;
	return (newnode);
}
