#ifndef SORT_H
#define SORT_H



/* Header files */

#include <stdlib.h>
#include <string.h>


/* structs */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;



/* prototypes */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
int sorted_array(int *array, size_t size);
int *swap_array(int *array, size_t position);
void bubble_sort(int *array, size_t size);


#endif /* SORT_H */
