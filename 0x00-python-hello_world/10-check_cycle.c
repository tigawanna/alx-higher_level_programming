#include "lists.h"

/**
 * check_cycle - checks if a singly linked list
 * loops into itself
 * @list: pointer to the list
 * Return: 0 if there is no cycle,
 * 1 if there is a loop
 */
int check_cycle(listint_t *list)
{
	listint_t *nd1;
	listint_t *nd2;

	nd1 = list;
	nd2 = list;
	while (list && nd1 && nd1->next)
	{
		list = list->next;
		nd1 = nd1->next->next;

		if (list == nd1)
		{
			list = nd2;
			nd2 =  nd1;
			while (1)
			{
				nd1 = nd2;
				while (nd1->next != list && nd1->next != nd2)
				{
					nd1 = nd1->next;
				}
				if (nd1->next == list)
					break;

				list = list->next;
			}
			return (1);
		}
	}

	return (0);
}
