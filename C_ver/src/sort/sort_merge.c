/*
 * *****************************************************************************
 * File: sort_merge.c
 * author: mchen
 * ref:
 *	CLRS 3rd
 *	http://www.keithschwarz.com/interesting/code/?dir=mergesort
 *
 * An implementation of merge sort. The idea of merge sort is as follow:
 * 1) divide
 * divide the input array into half, and half, etc., until only one element in
 * each such arrays. In this case, the element in these subarrays can be 
 * considered already sorted
 *
 * 2) conquer
 * merge the two sorted one element subarray into an sorted array of two 
 * elements, then combine into an four elements sorted array; on and on, 
 * util merge into a sortted array with original size
 * 
 * Example:
 * Input: [4,3,2,1]
 *
 * 1 divide
 * [4,3]	[2,1]
 *
 * 2 divide
 * [4] [3] [2] [1]
 *
 * 1 merge
 * [3,4]	[1,2]
 *
 * 2 merge
 * [1,2,3,4]
 * *****************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../include/sort/sort.h"

void merge(int data[], int i_start, int i_middle, int i_end);
void sort_merge(int data[], int i_start, int i_end);

/* merge two sorted subarrays: [i_start, i_middle] and [i_middle, i_end] */
void merge(int data[], int i_start, int i_middle, int i_end)
{
	int L_SUBARY_SIZE = i_middle - i_start + 1;
	int R_SUBARY_SIZE = i_end - i_middle;

	int l_subary[L_SUBARY_SIZE];
	int r_subary[R_SUBARY_SIZE];

	for(int i = 0; i < L_SUBARY_SIZE; i++)
		l_subary[i] = data[i_start + i];

	for(int i = 0; i < R_SUBARY_SIZE; i++)
		r_subary[i] = data[i + i_middle + 1];

	/* merge */
	int i_l = 0;
	int i_r = 0;
	for(int i_data = i_start; i_data <= i_end; i_data++) {
		/* both index are valid */
		if(i_l < L_SUBARY_SIZE && i_r < R_SUBARY_SIZE) { 
			if(l_subary[i_l] <= r_subary[i_r]) {
				data[i_data] = l_subary[i_l];
				i_l++;
			}else {
				data[i_data] = r_subary[i_r];
				i_r++;
			}
		} else if(i_l >= L_SUBARY_SIZE) { /* only i_r is valid */
			data[i_data] = r_subary[i_r];
			i_r++;
		} else { /* only i_l is valid */
			data[i_data] = l_subary[i_l];
			i_l++;
		}
	}
}

void sort_merge(int data[], int i_start, int i_end)
{
	if(i_start < i_end) {
		int i_middle = (i_start + i_end) / 2;
// #define DEBUG
#ifdef DEBUG
		printf("the i_middle is: %d\n", i_middle);
#endif
		sort_merge(data, i_start, i_middle);	/* divide left */
		sort_merge(data, i_middle + 1, i_end);	/* divide right */
		merge(data, i_start, i_middle, i_end);
	}
}
