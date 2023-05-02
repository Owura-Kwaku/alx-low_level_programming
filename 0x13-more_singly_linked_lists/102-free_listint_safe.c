#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
 * _ra - function that reallocates memory for an
 * array of pointers to the nodes in a linked list
 * @list: the old list to append
 * @size: size of the new list
 * @new: new node
 *
 * Return: pointer to the new list
 */
listint_t **_ra(listint_t **list, size_t size, listint_t *new)
{
	listint_t **newlist;
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
 * free_listint_safe - function that frees a listint_t linked list.
 * @head: double head pointer
 *
 * Return: the number of nodes in the list
 */
size_t free_listint_safe(listint_t **head)
{
	size_t listsize = 0;
    size_t number = 0;
	listint_t **list = NULL;
	listint_t *next;

	if (*head == NULL || head == NULL)
		return (number);
	while (*head != NULL)
	{
		for (; listsize < number; listsize++)
		{
			if (*head == list[listsize])
			{
				*head = NULL;
				free(list);
				return (number);
			}
		}
		number++;
		list = _ra(list, number, *head);
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	free(list);
	return (number);
}
