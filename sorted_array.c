#include "sort.h"

/**
 * sorted_array - Checks if the array is sorted
 * @array: the array to check
 * @size: the size of the array
 * Return: NULL if False, 1 if True
 */

int sorted_array(int *array, size_t size)
{
	size_t i;

	for(i = 0 ; i < (size - 1) ; i++)
	{
		if(array[i] > array[i + 1])
			return (NULL);
	}
	return (1);
}
