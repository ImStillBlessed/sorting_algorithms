#include "sort.h"


void merge(int *array, size_t size, int *left, size_t left_size, int *right, size_t right_size);
void merge_sort_recursive(int *array, size_t size);

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, size);
}

/**
 * merge_sort_recursive - Recursively splits and merges the array
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort_recursive(int *array, size_t size)
{
	size_t mid;
	int *left;
	size_t left_size;
	int *right;
	size_t right_size;

	if (size < 2)
		return;

	mid = (size / 2);
	left = array;
	left_size = mid;
	right = array + mid;
	right_size = size - mid;

	merge_sort_recursive(left, left_size);
	merge_sort_recursive(right, right_size);

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	merge(array, size, left, left_size, right, right_size);

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge - Merges two subarrays into a single sorted array
 * @array: The array to be sorted
 * @size: The size of the array
 * @left: The left subarray
 * @left_size: The size of the left subarray
 * @right: The right subarray
 * @right_size: The size of the right subarray
 */
void merge(int *array, size_t size, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc(size * sizeof(int));

	if (temp == NULL)
		return;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}

	while (i < left_size)
		temp[k++] = left[i++];

	while (j < right_size)
		temp[k++] = right[j++];

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	free(temp);
}
