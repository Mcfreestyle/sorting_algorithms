#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_merge - prints the process of the merge
 * @cpy_ar: copy of the array
 * @array: array
 * @iBegin: first index of the array
 * @iMiddle: index that divides the array
 * @iEnd: size of the array
 */
void print_merge(int *cpy_ar, int *array, int iBegin, int iMiddle, int iEnd)
{
	int i;

	printf("Merging...\n[left]: ");
	for (i = iBegin; i < iMiddle - 1; i++)
		printf("%d, ", cpy_ar[i]);
	printf("%d\n[right]: ", cpy_ar[i]);
	for (i = iMiddle; i < iEnd - 1; i++)
		printf("%d, ", cpy_ar[i]);

	printf("%d\n[Done]: ", cpy_ar[i]);
	for (i = iBegin; i < iEnd - 1; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}

/**
 * merge - merges the subarrays in order
 * @cpy_ar: copy of the array
 * @array: array
 * @iBegin: first index of the array
 * @iMiddle: index that divides the subarrays
 * @iEnd: size of the array
 */
void merge(int *cpy_ar, int *array, int iBegin, int iMiddle, int iEnd)
{
	int i, j, k;

	i = iBegin;
	j = iMiddle;

	for (k = iBegin; k < iEnd; k++)
	{
		if (i < iMiddle && (j >= iEnd || cpy_ar[i] <= cpy_ar[j]))
		{
			array[k] = cpy_ar[i];
			i++;
		}
		else
		{
			array[k] = cpy_ar[j];
			j++;
		}
	}
	print_merge(cpy_ar, array, iBegin, iMiddle, iEnd);

	for (k = iBegin; k < iEnd; k++)
		cpy_ar[k] = array[k];
}

/**
 * split - splits the array in two subarrays
 * @cpy_ar: copy of the array
 * @array: array
 * @iBegin: first index of the array
 * @iEnd: size of the array
 */
void split(int *cpy_ar, int *array, int iBegin, int iEnd)
{
	int iMiddle;

	if (iEnd - iBegin <= 1)
		return;

	iMiddle = (iEnd + iBegin) / 2;
	split(cpy_ar, array, iBegin, iMiddle);
	split(cpy_ar, array, iMiddle, iEnd);

	merge(cpy_ar, array, iBegin, iMiddle, iEnd);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 *		using the Merge sort algorithm
 * @array: array
 * @size: size of the @array
 */
void merge_sort(int *array, size_t size)
{
	int *cpy_ar;
	size_t i;

	if (!array)
		return;

	cpy_ar = malloc(sizeof(int) * size);
	if (!cpy_ar)
		return;

	for (i = 0; i < size; i++)
		cpy_ar[i] = array[i];

	split(cpy_ar, array, 0, size);
	free(cpy_ar);
}
