#include <stdio.h>
#include "sort.h"


/**
 * shell_sort - sorts integers in ascending order
 *
 * Description: sorts by comparing elements at a specified
 * interval and gradually reducing the interval until the array is sorted.
 *
 * @array: array of integers
 * @size: size of the array
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (!array || size < 2)
		return;

	/* Knuth Sequence Formula */
	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			for (; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
