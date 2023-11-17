#include "sort.h"

/**
 * insertion_sort_list - does an inserrion sort on rhe doubly linked list.
 * @list: doubly linked list.
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while(current != NULL)
	{
		node = current->prev;
		while (node != NULL && node->n > current->n)
		{
			if (node->prev != NULL)
				node->prev->next = current;
			if (current->next != NULL)
				current->next->prev = node;
			node->next = current->next;
			current->prev = node->prev;
			current->next = node;
			node->prev = current;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
			node = current->prev;
		}
		current = current->next;
	}
}
