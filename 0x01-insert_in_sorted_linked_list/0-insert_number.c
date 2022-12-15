#include "lists.h"
#include <stdlib.h>

/**
* insert_node - function that inserts a number into a
* sorted singly linked list
* @head: first node
* @number: number to be inserted
* Return: a pointer with the addres of the new node or NULL if it failed
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current;
	listint_t *new;

	if (!head)
		return (NULL);

	if (!number)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	current = *head;

	(*new).n = number;

	if ((*current).next->n > number)
	{
		(*new).next = *head;
		*head = new;
	}

	while (current != NULL)
	{
		if ((*current).next->n > number)
		{
			(*new).next = current->next;
			current->next = new;
			break;
		}
		current = (*current).next;

		if ((*current).next == NULL)
		{
		(*current).next = new;
		(*new).next = NULL;
		break;
		}
	}
	return (new);
}
