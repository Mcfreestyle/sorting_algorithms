#include "sort.h"
#include <stdbool.h>

/**
 * shell_sort - sorts an array of integers in ascending order
 *			using the shell sort algorithm
 * @array: array
 * @size: size of @array
 */
void shell_sort(int *array, size_t size)
{
	int gaps[] = {121, 40, 13, 4, 1};
	int i, j, k, gap, sz_gaps, tmp;
	bool is_gap;

	if (!array)
		return;

	sz_gaps = sizeof(gaps) / sizeof(gaps[0]);

	for (i = 0; i < sz_gaps; i++)
	{
		gap = gaps[i];
		is_gap = false;
		for (j = 0; j < gap; j++)
		{
			k = gap + j;
			while (k < (int)size)
			{
				is_gap = true;
				if (k - gap >= 0 && array[k] < array[k - gap])
				{
					tmp = array[k - gap];
					array[k - gap] = array[k];
					array[k] = tmp;
					k -= gap;
				}
				else
					k += gap;
			}
		}
		if (is_gap)
			print_array(array, size);
	}
}
