#include "sort.h"
/**
* insertion_sort_list - sorts a doubly-linked list
* @list: pointer to doubly linked list
*
* Return: none
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *tmp2, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tmp = (*list)->next;

	while (tmp != NULL && tmp->prev != NULL)
	{
		while (tmp->prev && tmp && tmp->n < tmp->prev->n)
		{
			tmp2 = tmp->prev;
			prev = tmp2->prev;
			next = tmp->next;

			if (prev != NULL)
				prev->next = tmp;
			else
				*list = tmp;
			tmp2->prev = tmp;
			tmp2->next = next;
			tmp->prev = prev;
			tmp->next = tmp2;
			if (next != NULL)
				next->prev = tmp2;
			print_list(*list);
			tmp = tmp->next;
			tmp = tmp->prev;
		}
		tmp = tmp->next;
	}
}
