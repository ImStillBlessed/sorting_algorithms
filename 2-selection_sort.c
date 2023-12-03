#include "sort.h"

int *swap(int *array, size_t a, size_t b);

/**
 * selection_sort - sorts an array of integers using the select sort.
 * @array: the unordered array to sort
 * @size: the size of the array
 * Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, index;

	index = 0;
	for (index = 0 ; index < size ; index++)
	{
		i = index;
		j = (index + 1);
		while (j < size)
		{
			if (array[i] < array[j])
				j++;
			else
			{
				i = j;
				j++;
			}
		}
		if (i != index)
		{
			swap(array, i, index);
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps two integers in a list
 * @array: the array to swap the integers.
 * @a: the first index.
 * @b: the second index.
 * Return: a new array.
 */
int *swap(int *array, size_t a, size_t b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
	return (array);
}
