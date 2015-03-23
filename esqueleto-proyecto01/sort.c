#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "array_helpers.h"
#include "sort.h"

struct aux_mpf {
    unsigned long int comps;
    unsigned long int minp;
};

struct aux_pivot{
    unsigned long int comps;
    unsigned long int swaps;
    unsigned int piv;
};

bool array_is_sorted(int *a, unsigned int length) {
    /* Needs implementation */
    bool cre = true;
    bool dec = true;
    unsigned int i = 1;

    while ( cre && (i < length)){
    	if (a[i-1]<=a[i]) {
    		i=i+1;
    	}
    	else {
    		cre = false;
    	}
    }

    i=1;

    while (dec && (i < length)){
    	if (a[i-1]>=a[i]){
    		i++;
    	} else {
    		dec = false;
    	}
    }
    dec=(dec||cre);

    return dec;

}

void swap(int *a, unsigned int i, unsigned int j) {
/*
    Swap the value at position 'i' with the value at position 'j' in the
    array 'a'. The values 'i' and 'j' must be valid positions in the array.

*/
    int temp = 0;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;

}

struct aux_mpf min_pos_from(int *a, unsigned int length, unsigned int i) {
/*
    Return the position of the minimum value in the array 'a' starting
    at position 'i'. The array 'a' must have exactly 'length' elements,
    and 'i' must be a valid position in the array.

*/
    struct aux_mpf mpf;
    mpf.comps = 0;
    mpf.minp = 0;

    unsigned int j;
    mpf.minp = i;
    j=i+1;
    while  (j < length){
        mpf.comps = mpf.comps + 1;
    	if (a[j]<a[mpf.minp]){
    		mpf.minp=j;
    	}
    	j=j+1;
    }
    return mpf;
}

struct sorting_stats selection_sort(int *a, unsigned int length) {
    assert(array_is_valid(a, length));

    /* Needs implementation */

    struct sorting_stats result;
    result.comps = 0;
    result.swaps = 0;

    struct aux_mpf mpf;
    mpf.comps = 0;
    mpf.minp = 0;

    unsigned int i = 0;
    while (i < length){
    	mpf = min_pos_from(a,length,i);
        result.comps = result.comps + mpf.comps;
    	swap (a,i,(mpf.minp));
        result.swaps = result.swaps + 1;
    	i=i+1;
    }
    /* Check postconditions */
    assert(array_is_sorted(a, length));
    return (result);
}

struct sorting_stats insertion_sort(int *a, unsigned int length) {
    assert(array_is_valid(a, length));

    /* Needs implementation */
    struct sorting_stats result;
    result.comps = 0;
    result.swaps = 0;

   for (unsigned int i = 1; i < length; i++) {
   		int j = i;
        result.comps = result.comps + 1;
   		while (j>0 && a[j]<a[j-1]){
   			swap(a,j-1,j);
            result.swaps = result.swaps + 1;
   			j=j-1;
   		}
    }
    /* Check postconditions */
    assert(array_is_sorted(a, length));
    return (result);
}


struct aux_pivot pivot (int *a, int left, int right){
    /* implementation */

    struct aux_pivot result_pivot;
    result_pivot.comps = 0;
    result_pivot.swaps = 0;
    result_pivot.piv = left;

    unsigned int l = left+1;
    unsigned int r = right;
    while (l<=r){
        if (a[l]<=a[result_pivot.piv]){
            result_pivot.comps = result_pivot.comps + 1;
            l++;
        }
        else if (a[r]>a[result_pivot.piv]){
            result_pivot.comps = result_pivot.comps + 2;
            r--;
        }
        else /*if (a[l] > a[result_pivot.piv] && a[r] <= a[result_pivot.piv])*/{
            result_pivot.comps = result_pivot.comps + 2;
            swap(a,l,r);
            result_pivot.swaps = result_pivot.swaps + 1;
            l++;
            r--;
        } 
    }
    swap(a,(result_pivot.piv),r);
    result_pivot.swaps = result_pivot.swaps + 1;
    result_pivot.piv=r;
    return (result_pivot);
}

struct sorting_stats quick_sort_rec (int *a, unsigned int length, int left, int right){
    /* implementation */
    struct aux_pivot result_pivot;
    struct sorting_stats result;
    struct sorting_stats aux;
    aux.comps = 0;
    aux.swaps = 0;
    result.comps = 0;
    result.swaps = 0;

    if (left < right){
        result_pivot=pivot(a,left,right);
        result.comps=result.comps + result_pivot.comps;
        result.swaps=result.swaps + result_pivot.swaps;
        aux = quick_sort_rec(a,length,left,(result_pivot.piv)-1);
        result.comps = result.comps + aux.comps;
        result.swaps = result.swaps + aux.swaps;
        aux = quick_sort_rec(a,length,(result_pivot.piv)+1,right);
        result.comps = result.comps + aux.comps;
        result.swaps = result.swaps + aux.swaps;
    }
    return(result);
}

struct sorting_stats quick_sort(int *a, unsigned int length) {
    assert(array_is_valid(a, length));

    struct sorting_stats result;
    /* Needs implementation */
    result = quick_sort_rec(a,length, 0,length-1);
    /* Check postconditions */
    assert(array_is_sorted(a, length));

    return(result);
}
struct sorting_stats bubble_sort(int *a, unsigned length){
    /*Check preconditions*/
    assert(array_is_valid(a, length));
    /*Implementation*/
    struct sorting_stats result;
    /*Check postconditions*/
    assert(array_is_sorted(a, length));
    
    return(result);
}