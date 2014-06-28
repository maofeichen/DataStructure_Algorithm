/*
 * *****************************************************************************
 * File: sort_insert.c
 * author: mchen
 *
 * An implementation of insertion sort. The idea of insertion sort is as follow:
 * given an input array A[], conceptly divide the array in two parts, the left
 * part is already ordered, the right part isn't. Always pick the first element
 * in the right part, compared all the elements in the left part from the
 * begin, if found is smaller, insert it by swapping the two compared elements.
 *
 * At the begin, consider the first element is ordered, so start from the second
 * element; continue until all element have been compared.
 *
 * Example:
 * Input	Output
 * [4,3,2,1]
 *
 * Input	Output
 * 		[3,4,2,1]
 *
 * Input	Output
 * 		[2,3,4,1]
 *
 * Input	Output
 * 		[1,2,3,4]
 * *****************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../include/sort/sort.h"

inline void swap(int *, int *);

/* insert sort */
void sort_insert(int data[], size_t len){

	for(int i_outloop = 1; i_outloop <= len - 1; i_outloop++){	
		for(int i_inloop = i_outloop; i_inloop > 0; i_inloop--) {
		/* for(int i_inloop = 0; i_inloop < i_outloop; i_inloop++){ 
			// wrong, should be reverse order */
			if(data[i_inloop] < data[i_inloop-1])
				swap(data+i_inloop, data+i_inloop-1);
				/* break; // can't add this, otherwise inner loop 
					only exec once */
		}
	}
}

inline void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
