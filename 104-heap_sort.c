#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index 'start'
 * @array: The array to sort
 * @start: The root of the heap to repair
 * @end: The limit of the heap to repair
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child += 1;

		if (array[root] < array[child])
		{
			int tmp = array[root];
			array[root] = array[child];
			array[child] = tmp;
			print_array(array, size);
			root = child;
		}
		else
			return;
	}
}

/**
 * heapify - Build a max heap from the array
 * @array: The array to sort
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
	size_t start;

	for (start = (size - 2) / 2; (ssize_t)start >= 0; start--)
		sift_down(array, start, size - 1, size);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * algorithm.
 * @array: The array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;

	heapify(array, size);

	for (end = size - 1; end > 0; end--)
	{
		int tmp = array[end];
		array[end] = array[0];
		array[0] = tmp;
		print_array(array, size);
		sift_down(array, 0, end - 1, size);
	}
}

