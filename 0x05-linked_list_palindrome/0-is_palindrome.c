#include "lists.h"

/*
 * @is_palindrome: function that checks if a singly linked list is a palindrome.
 * @head: pointer to the first node of the linked list.
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int buffer[4096], i = 0;

	if (*head == NULL)
		return (1);

	while (current != NULL)
	{
		buffer[i] = current->n;
		current = current->next;
		i++;
	}

	i--;
	current = *head;

	while (current != NULL)
	{
		if (current->n != buffer[i])
			return (0);
		current = current->next;
		i--;
	}

	return (1);
}