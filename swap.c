#include "sort.h"

/**
 * swap - swaps positions of two numbers in an array
 * @array: the array
 * @position: the positikn of the number
 * Return: a new swaped array
 */
int *swap_array(int *array, size_t position)
{
	int temp = array[position];

	array[position] = array[position + 1];
	array[position + 1] = temp;
	return (array);
}
