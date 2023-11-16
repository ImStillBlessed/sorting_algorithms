#include "sort.h"

/**
 * insertion_sort_list - does an inserrion sort on rhe doubly linked list.
 * @list: doubly linked list.
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *next;
	listint_t *sorted = NULL;
	listint_t *temp;

	while(current != NULL)
	{
		next = current->next;
		if(sorted == NULL || sorted->n >= current->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			temp = sorted;
			while (temp->next != NULL && temp->next->n < current->n)
			{
				temp = temp->next;
			}
			current->next = temp->next;
			if (temp->next != NULL)
			{
				temp->next->prev = current;
			}
			temp->next = current;
			current->prev = temp;
			print_list(sorted);
		}
		current = next;
	}
	*list = sorted;
}
