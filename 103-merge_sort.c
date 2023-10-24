#include "sort.h"
#include <stdio.h>
/**
 * merge - merges two sorted subarray into another copy of array
 * @array: array constaining the subarrays
 * @w_array: copy of array to merge the subarrays to
 * @ibeg: start of the array/ subarray
 * @imid: midpoint of the array
 * @iend: size of the array(last index exclusive)
 */
void merge(int *array, int *w_array, int ibeg, int imid, int iend)
{
	int i, j, k;

	i = ibeg;
	j = imid;
	for (k = ibeg; k < iend; k++)
	{
		if (i < imid && (j >= iend || array[i] <= array[j]))
		{
			w_array[k] = array[i];
			i++;
		}
		else
		{
			w_array[k] = array[j];
			j++;
		}
	}
}
/**
 * print_sub_array - prints a subarray with status to stdout
 * @array: array containing the subarray
 * @start: starting index
 * @end: last index(excluded)
 * @msg: status message
 */
void print_sub_array(int *array, int start, int end, char *msg)
{
	int i;

	printf("[%s]: ", msg);
	for (i = start; i < end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
/**
 * topdown_split_merge - splits the array into subarrays and merges them
 * once sorted
 * @array: array of items to be sorted
 * @w_array: equal size array as the array to be sorted
 * @ibeg: beginning index of the array/ subarray
 * @iend: size of array. (last index)
 */
void topdown_split_merge(int *array, int *w_array, int ibeg, int iend)
{
	int imid, i;

	if ((iend - ibeg) <= 1)
		return;
	imid = (ibeg + iend) / 2;
	topdown_split_merge(array, w_array, ibeg, imid);
	topdown_split_merge(array, w_array, imid, iend);
	for (i = ibeg; i < iend; i++)
		array[i] = w_array[i];
	printf("Merging...\n");
	print_sub_array(array, ibeg, imid, "left");
	print_sub_array(array, imid, iend, "right");
	merge(array, w_array, ibeg, imid, iend);
	print_sub_array(w_array, ibeg, iend, "Done");
}
/**
 * merge_sort - sorts an array of integers in ascending order
 * using top down merge sort algorithm
 * @array: an integer array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *w_array;
	size_t i;

	if (array == NULL || size <= 1)
		return;
	w_array = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		w_array[i] = array[i];
	topdown_split_merge(array, w_array, 0, size);
	for (i = 0; i < size; i++)
		array[i] = w_array[i];
	free(w_array);
}
