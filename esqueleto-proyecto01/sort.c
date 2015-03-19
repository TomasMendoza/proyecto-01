#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "array_helpers.h"
#include "sort.h"

bool array_is_sorted(int *a, unsigned int length) {
    /* Needs implementation */
    bool cre = true;
    bool dec = true;
    unsigned int i = 0;

    while ( cre && (i < length-1)){
    	if (a[i]<=a[i+1]) {
    		i=i+1;
    	}
    	else {
    		cre = false;
    	}
    }

    i=0;

    while (dec && (i < length-1)){
    	if (a[i]>=a[i+1]){
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

unsigned int min_pos_from(int *a, unsigned int length, unsigned int i) {
/*
    Return the position of the minimum value in the array 'a' starting
    at position 'i'. The array 'a' must have exactly 'length' elements,
    and 'i' must be a valid position in the array.

*/
    unsigned int j;
    unsigned int minp = i;
    j=i+1;
    while  (j < length){
    	if (a[j]<a[minp]){
    		minp=j;
    	}
    	j=j+1;
    }
    return minp;
}

void selection_sort(int *a, unsigned int length) {
    assert(array_is_valid(a, length));

    /* Needs implementation */
    unsigned int i = 0;
    unsigned int minp = 0;
    while (i < length){
    	minp = min_pos_from(a,length,i);
    	swap (a,i,minp);
    	i=i+1;
    }
    /* Check postconditions */
    assert(array_is_sorted(a, length));
}

void insertion_sort(int *a, unsigned int length) {
    assert(array_is_valid(a, length));

    /* Needs implementation */

   for (unsigned int i = 1; i < length; i++) {
   		int j = i;
   		while (j>0 && a[j]<a[j-1]){
   			swap(a,j-1,j);
   			j=j-1;
   		}
    }
    /* Check postconditions */
    assert(array_is_sorted(a, length));
}


unsigned int pivot (int *a, unsigned int izq, unsigned int der){
	unsigned int i,j;
	unsigned int piv=izq;
    printf("pivot pivote: %d\n", piv);
	i=izq+1;
	j=der;
	while(i<=j){
		if (a[i]<=a[(piv)]){
			i=i+1;
		}
		else if (a[j]>a[(piv)]){
			j=j-1;
		}
		else if (a[i]>a[(piv)] && a[j]<=a[(piv)]){
			swap(a,i,j);
			i=i+1;
			j=j-1;}

	}
	swap(a,(piv),j);
	(piv)=j;
	return piv;
}
void quick_sort_rec (int *a, unsigned int length, unsigned int izq, unsigned int der){
	unsigned int piv;

	if (der > izq) { 
        printf("entro en rec\n");
		piv=pivot(a,izq,der);
		printf("qs rec pivote: %d\n", piv);
		quick_sort_rec(a,length,izq,piv-1);
        printf("hola\n");
		quick_sort_rec(a,length,piv+1,der);

	}

}

void quick_sort(int *a, unsigned int length) {
    assert(array_is_valid(a, length));

    /* Needs implementation */
    quick_sort_rec(a,length, 0,length-1);
    /* Check postconditions */
    assert(array_is_sorted(a, length));
}
