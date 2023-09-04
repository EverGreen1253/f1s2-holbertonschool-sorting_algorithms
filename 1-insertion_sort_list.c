#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - to do insertion sort
 * @list: the list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *key;

	if (list == NULL)
		exit(98);

	key = (*list);

	/* start from index 1 */
	while (key->next != NULL)
	{
		key = key->next;
		curr = key;

		while ((curr->prev != NULL) && (curr->prev->n > curr->n))
		{
			prev = curr->prev;

			/* printf("prev - %d, curr - %d\n", prev->n, curr->n); */

			curr->prev = prev->prev;
			prev->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = prev;

			if (prev->prev != NULL)
				prev->prev->next = curr;
			else
				*list = curr;

			curr->next = prev;
			prev->prev = curr;

			/* curr should have been shifted one slot back */

			print_list(*list);
		}
	}
}
