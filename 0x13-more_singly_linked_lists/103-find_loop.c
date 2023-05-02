#include "lists.h"

/**
 * find_listint_loop - func that finds the loop in a linked list.
 * @head: head pointer
 *
 * Return: address of the node
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *object1, *object2;

	object1 = object2 = head;
	while (object1 && object2 && object2->next)
	{
		object1 = object1->next;
		object2 = object2->next->next;
		if (object2 == object1)
		{
			object1 = head;
			break;
		}
	}
	if (!object2 || !object1 || !object2->next)
		return (NULL);
	while (object1 != object2)
	{
		object1 = object1->next;
		object2 = object2->next;
	}
	return (object2);
}
