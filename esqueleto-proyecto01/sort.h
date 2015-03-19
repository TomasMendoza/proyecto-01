#ifndef _SORT_H
#define _SORT_H

#include <stdbool.h>

bool array_is_sorted(int *a, unsigned int length);
/*
    Returns true if the array is ascending sorted, and false if not.
    The array 'a' must have exactly 'length' elements.

*/


void selection_sort(int *a, unsigned int length);
/*
    Sort the array 'a' using the Selection sort algorithm. The resulting sort
    will be ascending.

    The array 'a' must have exactly 'length' elements.

*/

void insertion_sort(int *a, unsigned int length);
/*
    Sort the array 'a' using the Insertion sort algorithm. The resulting sort
    will be ascending.

    The array 'a' must have exactly 'length' elements.

*/

void quick_sort(int *a, unsigned int length);
/*
    Sort the array 'a' using the Quick sort algorithm. The resulting sort
    will be ascending.

    The array 'a' must have exactly 'length' elements.

*/

#endif
