#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - func that frees a listint_t list
 * @head: double head pointer
 *
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *next;

	if (head == NULL)
		return;
	do {
		next = (*head)->next;
		free(*head);
		*head = next;
	} while (*head != NULL);
}
