#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - The sort function
 * @array: the array
 * @size: the size
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped = 0;

	if (array == NULL || size  == 0)
	{
		exit(98);
	}

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;

				print_array(array, size);
			}
		}

		/* If no two elements were swapped by inner loop, */
		/* then break */
		if (swapped == 0)
			break;
	}
}

/**
 * swap - swap the values
 * @a: first value
 * @b: second value
 *
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
