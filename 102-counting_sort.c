#include "sort.h"

/**
 * counting_sort - Sorts an array of integers  using Counting sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, *output_array;
	int max = 0;
	size_t i;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;

	for (i = 0; i <= (size_t)max; i++)
		counting_array[i] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	print_array(counting_array, max + 1);

	for (i = 1; i <= (size_t)max; i++)
		counting_array[i] += counting_array[i - 1];

	output_array = malloc(size * sizeof(int));
	if (output_array == NULL)
	{
		free(counting_array);
		return;
	}

	for (i = size - 1; i < size; i--)
	{
		output_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	print_array(array, size);

	free(counting_array);
	free(output_array);
}
