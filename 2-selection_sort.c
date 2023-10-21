#include <stdio.h>
#include "sort.h"

/**
 * swap - swaps n1 and n2
 *
 * @n1: 1st number
 * @n2: 2nd number
*/
void swap(int *n1, int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/**
 * selection_sort - places the smallest non-sorted int to the left
 *
 * @array: list of integers
 * @size: size of the list
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
