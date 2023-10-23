#include "sort.h"

/**
 * swap_forw - swaps two nodes in a doubly linked list left to right
 * @list: head node of the linked list
 * @current: current node
 * @next_node: node next to current node
 */
void swap_forw(listint_t **list, listint_t *current, listint_t *next_node)
{
	listint_t *temp;

	temp = current->prev;
	current->next = next_node->next;
	if (next_node->next)
		next_node->next->prev = current;
	current->prev = next_node;
	next_node->next = current;
	next_node->prev = temp;
	if (temp)
		temp->next = next_node;
	else
		*list = next_node;
	print_list(*list);
}
/**
 * swap_back - swaps two nodes in a doubly linked list left to right
 * @list: head node of the linked list
 * @current: current node
 * @next_node: node previous to current node
 */
void swap_back(listint_t **list, listint_t *current, listint_t *next_node)
{
	listint_t *temp;

	temp = next_node->prev;
	next_node->next = current->next;
	if (current->next)
		current->next->prev = next_node;
	next_node->prev = current;
	current->next = next_node;
	current->prev = temp;
	if (temp)
		temp->next = current;
	else
		*list = current;
	print_list(*list);
}


/**
 * cocktail_sort_list - sorts a doubly linked list using Cocktail shaker
 * sort algorithm.
 * @list: head node of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *next_node, *current;
	int swap = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (swap)
	{
		swap = 0;
		current = *list;
		while (current->next)
		{
			next_node = current->next;
			if (current->n > next_node->n)
			{
				swap_forw(list, current, next_node);
				swap = 1;
			}
			else
				current = current->next;
		}
		if (!swap)
			break;
		swap = 0;
		while (current->prev)
		{
			next_node = current->prev;
			if (current->n < next_node->n)
			{
				swap_back(list, current, next_node);
				swap = 1;
			}
			else
				current = current->prev;
		}
		if (!swap)
			break;
	}
}
