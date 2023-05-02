#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
 * _r - function that reallocates memory for
 * an array of pointers to the nodes in a linked list
 * @list: old list to append
 * @size: size of the new list
 * @new: new node
 *
 * Return: pointer to the new list
 */
const listint_t **_r(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **newlist;
	size_t listsize = 0;

	newlist = malloc(size * sizeof(listint_t *));
	if (newlist == NULL)
	{
		free(list);
		exit(98);
	}
	for (; listsize < size - 1; listsize++)
		newlist[listsize] = list[listsize];
	newlist[listsize] = new;
	free(list);
	return (newlist);
}

/**
 * print_listint_safe - function that prints
 * a listint_t linked list.
 * @head: head pointer
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t listsize = 0;
    size_t number = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (; listsize < number; listsize++)
		{
			if (head == list[listsize])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (number);
			}
		}
		number++;
		list = _r(list, number, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (number);
}
