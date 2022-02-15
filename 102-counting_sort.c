#include "sort.h"
#include <stdlib.h>

/**
 * max_array - calculates the max integer of the array
 * @array: array
 * @size: size of the @array
 *
 * Return: the max of the array
 */
size_t max_array(int *array, size_t size)
{
	size_t i, max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if ((int)max < array[i])
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - sorts an array of integers in ascending order
 *		using the counting sort algorithm
 * @array: array
 * @size: size of the @array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, max;
	int *count, *output;

	if (!array)
		return;

	max = max_array(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	output = malloc(sizeof(int) * (max + 1));
	if (!output)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
