#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort - does the sorting
 * @array: the array
 * @size: the size
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	int start, stop;

	if (array == NULL || size == 0)
	{
		exit(98);
	}

	start = 0;
	stop = (int)(size - 1);

	solve(array, start, stop, size);
}


/**
 * solve - the recursive method used to sort
 * @array: the array
 * @start: the start
 * @stop: the stop
 * @size: the size
 *
 * Return: nothing
 */
void solve(int *array, int start, int stop, size_t size)
{
	if (start < stop)
	{
		int pi = partition(array, start, stop, size);

		solve(array, start, pi - 1, size);
		solve(array, pi + 1, stop, size);
	}
}

/**
 * partition - find the partition value
 * @array: the array
 * @start: the start
 * @stop: the stop
 * @size: the size
 *
 * Return: nothing
 */
int partition(int *array, int start, int stop, size_t size)
{
	int pivot = array[stop];
	int i = (start - 1);

	for (int j = start; j <= stop - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);

			if (array[i] != array[j])
			{
				print_array(array, size);
			}
		}
	}
	swap(&array[i + 1], &array[stop]);

	if (array[i + 1] != array[stop])
	{
		print_array(array, size);
	}

	return (i + 1);
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
