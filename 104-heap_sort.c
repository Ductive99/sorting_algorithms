#include <stdio.h>
#include "sort.h"


void swap(int *n1, int *n2);
void heapify(int *array, size_t size, size_t base, size_t i);


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
 * heapify - maintains the max-heap property of a binary tree
 *
 * @array: array of integers representing a binary tree
 * @size: size of the array/tree
 * @base: the index of the base row of the tree
 * @i: the index of the root node to be heapified
*/
void heapify(int *array, size_t size, size_t base, size_t i)
{
	size_t left, right, max;

	left = 2 * i + 1;
	right = 2 * i + 2;
	max = i;

	if (left < base && array[left] > array[max])
		max = left;
	if (right < base && array[right] > array[max])
		max = right;

	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, size);
		heapify(array, size, base, max);
	}
}

/**
 * heap_sort - implements the sift-down heap sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
*/
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
