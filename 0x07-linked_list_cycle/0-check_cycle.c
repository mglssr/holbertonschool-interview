#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - function in C that checks if a singly linked
 * list has a cycle in it.
 * @list: singly linked list.
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = list, *fast = list;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow)
		{
			return (1);
		}
	}
	return (0);
}
