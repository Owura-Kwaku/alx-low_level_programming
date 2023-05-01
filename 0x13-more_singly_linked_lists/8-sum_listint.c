#include "lists.h"

/**
 * sum_listint - gets the sum value of all the (n) values
 * of a listint_t linked list.
 * @head: pointer to the first node
 *
 * Return: add
 */
int sum_listint(listint_t *head)
{
	int add = 0;

	do {
		add += head->n;
		head = head->next;
	} while (head != NULL);

	return (add);
}
