#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - The sort function
 * @array: the array
 * @size: the size
 *
 * for (i = 0; i < size - 1; i++)
 * {
 *  swapped = 0;
 *  for (j = 0; j < size - i - 1; j++)
 *  {
 *   if (array[j] > array[j + 1])
 *   {
 *    swap(&array[j], &array[j + 1]);
 *    swapped = 1;
 *    print_array(array, size);
 *   }
 *  }
 *
 *  if (swapped == 0)
 *   break;
 * }
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	/* size_t j; */
	int swapped = 0;
	int continue_sorting = 1;

	if (array == NULL || size  == 0)
		exit(98);

	while (continue_sorting)
	{
		swapped = 0;
		i = 0;
		while ((i + 1) < size)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				swapped = 1;
				print_array(array, size);
			}
			i++;
		}

		if (swapped == 0) /* nothing left to sort! */
			continue_sorting = 0;
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
