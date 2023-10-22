#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using insertion sort algorithm
 * @list: doubly linked list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted_head;
	listint_t *unsorted_head;
	listint_t *current, *temp;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;
	unsorted_head = (*list)->next;

	while (unsorted_head)
	{
		current = unsorted_head;
		sorted_head = unsorted_head->prev;
		unsorted_head = unsorted_head->next;
		while (sorted_head && sorted_head->n > current->n)
		{
			temp = sorted_head;
			sorted_head = sorted_head->prev;
			if (current->next != NULL)
				current->next->prev = temp;
			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;
			temp->next = current->next;
			current->prev = temp->prev;
			temp->prev = current;
			current->next = temp;
			print_list(*list);
		}
	}
}
