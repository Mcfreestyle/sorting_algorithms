#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *			in ascending order using the insertion sort algorithm
 * @list: address of the first node
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *minor_node, *major_node, *tmp;

	if (!list || !(*list))
		return;

	node = (*list)->next;/* second node */
	while (node)
	{
		if (node->prev && node->n < (node->prev)->n)
		{
			minor_node = node;
			major_node = node->prev;
			tmp = node->next;

			minor_node->prev = (node->prev)->prev;
			minor_node->next = major_node;
			if (minor_node->prev)
				(minor_node->prev)->next = minor_node;

			major_node->prev = minor_node;
			major_node->next = tmp;
			if (major_node->next)
				(major_node->next)->prev = major_node;

			while ((*list)->prev)
				*list = (*list)->prev;
			print_list(*list);
		}
		else
			node = (node->next);
	}

}
