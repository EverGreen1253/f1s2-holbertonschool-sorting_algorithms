#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - does the sorting
 * @array: the array
 * @size: the size
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < size - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		if(min_idx != i)
		{
			swap(&array[min_idx], &array[i]);
			print_array(array, size);
		}
	}
}

/**
 * swap - the swap function
 * @a: first one
 * @b: second one
 *
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

