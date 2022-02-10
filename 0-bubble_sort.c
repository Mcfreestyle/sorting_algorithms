#include "sort.h"
#include <stddef.h>
#include <stdbool.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the bubble sort algorithm
 * @array: unsorted array
 * @size: size fo the @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	bool swap;

	for (i = 0; i < size - 1; i++)
	{
		swap = false;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				swap = true;
			}
		}
		if (!swap)
			break;
	}
}
