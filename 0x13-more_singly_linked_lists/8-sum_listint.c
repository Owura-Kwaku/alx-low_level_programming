#include "lists.h"

/**
 * sum_listint - gets the sum value of all the (n) values
 * of a listint_t linked list.
 * @head: pointer to the first node
 *
 * Return: sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	do {
		sum += head->n;
		head = head->next;
	} while (head != NULL);

	return (sum);
}
