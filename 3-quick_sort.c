#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps the values of two items
 * @array: array
 * @index1: index of the first item
 * @index2: index of the second item
 * @size: size of the @array
 */
void swap(int *array, int index1, int index2, size_t size)
{
	int tmp;

	if (index1 != index2)
	{
		tmp = array[index1];
		array[index1] = array[index2];
		array[index2] = tmp;
		print_array(array, size);
	}
}

/**
 * partition - partition the array in two parts
 * @array: array
 * @lo: start index
 * @hi: end index
 * @size: size of the @array
 *
 * Return: the pivot index of the array
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int piv, i, j;

	piv = array[hi];
	j = lo - 1;
	for (i = lo; i <= hi; i++)
	{
		if (array[i] <= piv)
		{
			j++;
			swap(array, i, j, size);
		}
	}
	return (j);
}

/**
 * algorithm - quick sort algorithm
 * @array: array
 * @lo: start index
 * @hi: end index
 * @size: size of the @array
 */
void algorithm(int *array, int lo, int hi, size_t size)
{
	int piv_index;

	if (lo >= hi || lo < 0)
		return;

	piv_index = partition(array, lo, hi, size);

	algorithm(array, lo, piv_index - 1, size);
	algorithm(array, piv_index + 1, hi, size);
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *		using the quick sort algorithm
 * @array: array
 * @size: size of the @array
 */
void quick_sort(int *array, size_t size)
{
	int lo, hi;

	if (!array)
		return;

	lo = 0;
	hi = size - 1;

	algorithm(array, lo, hi, size);
}
