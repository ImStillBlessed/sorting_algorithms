#include "sort.h"

void heapify(int *array, size_t size, size_t i);
void heap_sort(int *array, size_t size);

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		heapify(array, i, 0);
	}
}

/**
 * heapify - Creates a max heap from an array
 * @array: The array to be transformed into a heap
 * @size: The size of the array
 * @i: The index of the root of the heap
 */
void heapify(int *array, size_t size, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		int temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;

		print_array(array, size);
		heapify(array, size, largest);
	}
}
