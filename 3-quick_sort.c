#include "sort.h"
/**
 * swap - swaps two elements in an array
 * @array: array containing the elements to swap
 * @ind1: index to first element in array
 * @ind2: index to secont element in array
 * @size: size of array to be swapped
 */
void swap(int *array, int ind1, int ind2, size_t size)
{
	int temp;

	temp = array[ind1];
	array[ind1] = array[ind2];
	array[ind2] = temp;
	print_array(array, size);
}

/**
 * partition - partitions an array accoring to lomuto partition scheme
 * @array: array to be partitioned
 * @low: lower bound of the array
 * @high: upper bound of the array
 * @size: the size of array to be partitioned
 *
 * Return: partition index
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	i = low;
	pivot = array[high];
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (j != i)
				swap(array, i, j, size);
			i++;
		}
	}
	if (array[i] > pivot)
		swap(array, i, high, size);
	return (i);
}
/**
 * qs - recursively does quicksort on an array
 * @array: array to be sorted
 * @low: lower bound of the array
 * @high: upper bound of the array
 * @size: the size of array to be sorted
 */
void qs(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		qs(array, low, p - 1, size);
		qs(array, p + 1, high, size);
	}
}
/**
 * quick_sort - perfoms a quick sort on an array using lomuto partition
 * scheme.
 * @array: represents an array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	int high;

	if (size < 2 || array == NULL)
		return;
	high = size - 1;
	qs(array, 0, high, size);
}
