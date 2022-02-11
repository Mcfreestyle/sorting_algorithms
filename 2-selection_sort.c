#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * selection_sort - sorts an array of integers in ascending order
 *			using the selection sort algorithm
 * @array: array
 * @size: size of the @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int minor, tmp;
	bool swap;

	if (!array)
		return;

	for (i = 0; i < size; i++)
	{
		swap = false;
		minor = array[i];
		tmp = minor;
		for (j = i + 1; j < size; j++)
		{
			if (minor > array[j])
			{
				k = j;
				minor = array[j];
				swap = true;
			}
		}
		if (swap)
		{
			array[i] = minor;
			array[k] = tmp;
			print_array(array, size);
		}
	}
}
