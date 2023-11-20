#include "sort.h"

/**
 * bubble_sort - Sorts an unordered list usimg bubble sort
 * @array: array of integers
 * @size: size of the array
 * Return: nothing.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;

	i = 0;
	while (1)
	{
		for (i = 0 ; i < size - 1 ; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_array(array, i);
				print_array(array, size);
			}
		}
		if (sorted_array(array, size))
			break;
	}
}

/**
 * swap - swaps positions of two numbers in an array
 * @array: the array
 * @position: the position of the number
 * Return: a new swaped array
 */
int *swap_array(int *array, size_t position)
{
	int temp = array[position];

	array[position] = array[position + 1];
	array[position + 1] = temp;
	return (array);
}

/**
 * sorted_array - Checks if the array is sorted
 * @array: the array to check
 * @size: the size of the array
 * Return: 0 if False, 1 if True
 */

int sorted_array(int *array, size_t size)
{
	size_t i;

	for (i = 0 ; i < (size - 1) ; i++)
	{
		if (array[i] > array[i + 1])
			return (0);
	}
	return (1);
}
