#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * getMax - Get the maximum value in an array
 * @array: The array
 * @size: Size of the array
 * Return: Maximum value in the array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countSort - Sort the array based on significant places
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The significant place to be considered (1, 10, 100, ...)
 */
void countSort(int *array, size_t size, int exp)
{
	int *output = NULL;
	int count[10] = {0};
	size_t i;

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - LSD Radix Sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}

