#include <stdio.h>
#include "sort.h"

void swap(int *n1, int *n2);

/**
 * bubble_sort - Sorts an by placing the biggest numbers
 * at the end of the list, just like how "bubbles" rise.
 *
 * @array: list of integers to sort
 * @size: size of the list
 *
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t j;
	int swapped = 0;

	if (size < 2 || !array)
		return;

	while (swapped == 0)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped == 1;
			}
		}
		size--;
	}
}


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
