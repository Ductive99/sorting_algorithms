#include <stdio.h>
#include "sort.h"

/**
 * find_k - finds k (the max key value) of an array of integers
 *
 * @array: array to look in
 * @size: size of the array
 *
 * Return: max key value
*/
int find_k(int *array, size_t size)
{
	size_t i;
	int max;

	if (!array)
		return (0);

	for (max = array[0], i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - sorts integers in ascending order
 *
 * Description: non-comparision sorting algorithm that counts
 * the frequency of elements and places them accordingly.
 *
 * @array: array of positive integers
 * @size: size of the array
*/
void counting_sort(int *array, size_t size)
{
	size_t i, k;
	int *countingArray, *output, max, index;

	if (!array || size < 2)
		return;

	max = find_k(array, size);

	countingArray = malloc((max + 1) * sizeof(int));
	output = malloc(size * sizeof(int));
	if (!countingArray || !output)
		return;

	k = max + 1;

	for (i = 0; i < k; i++)
		countingArray[i] = 0;

	for (i = 0; i < size; i++)
		countingArray[array[i]] += 1;
	for (i = 0; i < k; i++)
		countingArray[i + 1] += countingArray[i];
	for (i = k; i > 0; i--)
		countingArray[i] = countingArray[i - 1];

	print_array(countingArray, k);

	for (i = 0; i < size; i++)
	{
		output[countingArray[array[i]]] = array[i];
		countingArray[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(countingArray);
	free(output);
}
