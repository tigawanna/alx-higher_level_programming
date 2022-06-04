#include "lists.h"

listint_t *reverse_listint(listint_t **head);
int ispali(listint_t **head);

/**
 * reverse_listint - Reverses a singly-linked listint_t list.
 * @head: A pointer to the starting node of the list to reverse.
 *
 * Return: A pointer to the head of the reversed list.
 */
listint_t *rev_list(listint_t **head)
{
	listint_t *node = *head, *next, *prev = NULL;

	while (node)
	{
		next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}

	*head = prev;
	return (*head);
}

/**
 * ispali - Checks if a singly linked list is a palindrome.
 * @head: A pointer to the head of the linked list.
 *
 * Return: If the linked list is not a palindrome - 0.
 *         If the linked list is a palindrome - 1.
 */
int ispali(listint_t **head)
{
	listint_t *temporary, *reversed, *mid;
	size_t size = 0, i;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	temporary = *head;
	while (temporary)
	{
		size++;
		temporary = temporary->next;
	}

	temporary = *head;
	for (i = 0; i < (size / 2) - 1; i++)
		temporary = temporary->next;

	if ((size % 2) == 0 && temporary->n != temporary->next->n)
		return (0);

	temporary = temporary->next->next;
	reversed = rev_list(&temporary);
	mid = reversed;

	temporary = *head;
	while (reversed)
	{
		if (temporary->n != reversed->n)
			return (0);
		temporary = temporary->next;
		reversed = reversed->next;
	}
	rev_list(&mid);

	return (1);
}
