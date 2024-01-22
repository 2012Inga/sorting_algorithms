#include <stdio.h>
#include "sort.h"

/**
 * bitonic_merge - merges two subarrays in a bitonic manner
 * @array: array to be sorted
 * @size: size of the array
 * @start: starting index of the subarray
 * @step: step size for comparisons
 * @order: sorting order (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t start, size_t step, int order)
{
	size_t i, j, half = step / 2;
	int temp;

	for (i = start; i < start + half; i++)
	{
		j = i + half;
		if (!(order ^ (array[i] > array[j])))
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
}

/**
 * bitonic_sort_recursive - recursively sorts a bitonic sequence
 * @array: array to be sorted
 * @size: size of the array
 * @start: starting index of the subarray
 * @step: step size for comparisons
 * @order: sorting order (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t size, size_t start, size_t step, int order)
{
	size_t half = step / 2;

	if (step > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", step, size, order ? "UP" : "DOWN");
		print_array(array + start, step);

		bitonic_sort_recursive(array, size, start, half, 1);
		bitonic_sort_recursive(array, size, start + half, half, 0);

		bitonic_merge(array, start, step, order);

		printf("Result [%lu/%lu] (%s):\n", step, size, order ? "UP" : "DOWN");
		print_array(array + start, step);
	}
}

/**
 * bitonic_sort - sorts an array using the Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	size_t step;

	if (!array || size < 2)
		return;

	step = size;
	while (step > 1)
	{
		printf("Merging [%lu/%lu] (UP):\n", step, size);
		print_array(array, step);

		bitonic_sort_recursive(array, size, 0, step, 1);

		printf("Result [%lu/%lu] (UP):\n", step, size);
		print_array(array, step);

		step /= 2;
	}

	printf("\n");
}

