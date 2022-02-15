#include "sort.h"
#include <stdbool.h>

/**
 * swap_nodes - swaps the node with the previous node
 * @node: address of the node
 */
void swap_nodes(listint_t *node)
{
	listint_t *minor_node, *major_node, *tmp;

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
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 *		in ascending order using the cocktail shaker sort algorithm
 * @list: address of the first node
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	bool swap, to_right;
	int i;

	if (!list || !(*list))
		return;

	node = *list;
	for (i = 0; i < 20; i++)
	{
		while (node)
		{
			if (node->prev && node->n < (node->prev)->n)
			{
				swap_nodes(node);
				swap = true;
				while ((*list)->prev)
					*list = (*list)->prev;
				print_list(*list);
			}
			if (!(node->next))
				to_right = false;

			if (to_right)
				node = node->next;
			else
			{
				if (!swap)
					node = node->prev;
			}
			swap = false;
		}
		to_right = true;
		node = *list;
	}
}
