#include "sort.h"
/**
 * swap - swaps two elements in an array
 * @array: array containing the elements to swap
 * @ind1: index to first element in array
 * @ind2: index to secont element in array
 */
void swap(int *array, int ind1, int ind2)
{
	int temp;
	size_t n;

	n = 10;
	temp = array[ind1];
	array[ind1] = array[ind2];
	array[ind2] = temp;
	print_array(array, n);
}

/**
 * partition - partitions an array accoring to lomuto partition scheme
 * @array: array to be partitioned
 * @low: lower bound of the array
 * @high: upper bound of the array
 *
 * Return: partition index
 */
int partition(int *array, int low, int high)
{
	int i, j, pivot;

	i = low;
	pivot = array[high];
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (j != i)
				swap(array, i, j);
			i++;
		}
	}
	swap(array, i, high);
	return (i);
}
/**
 * qs - recursively does quicksort on an array
 * @array: array to be sorted
 * @low: lower bound of the array
 * @high: upper bound of the array
 */
void qs(int *array, int low, int high)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high);
		qs(array, low, p - 1);
		qs(array, p + 1, high);
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

	high = size - 1;
	qs(array, 0, high);
}
