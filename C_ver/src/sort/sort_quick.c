/*
 * *****************************************************************************
 * File: sort_quick.c
 * author: mchen
 * ref:
 *	CLRS 3rd
 *
 * An implementation of quick sort. The idea of quick sort is as follow:
 * it uses a divide & conquer strategy similar as merge sort, so we can
 * also divide the procedure into two stages
 * stage 1:
 * divide the input array to two sub arrays, not necessarily half. The
 * key idea, which is also different from merge sort, is picking one elem
 * as "pivot", and make one sub array is smaller than the pivot, and the
 * other sub array is larger than the pivot. The procesure is called partition.
 *
 * After first partition, the input array is partially orderred. And partition
 * recursively to each of the subarray. 
 * 
 * The base case is only one element in the subarray, which is considered already
 * sortted. 
 *
 * stage 2:
 * there is nothing to do, the array is already sorted at this time.
 *
 * Example (always pick the last ele as pivot):
 * Input: [2,8,7,1,3,5,6,4]
 *
 * 1 partition 
 * [2,1,3]	[4]	[7,5,6,8]
 *
 * next solve the each subarray separately using the same procedure
 *
 * *****************************************************************************
 */


#include "../../include/sort/sort.h"

unsigned partition(int data[], int i_start, int i_end);
void sort_quick(int data[], int i_start, int i_end);
extern void swap(int *a, int *b);

unsigned partition(int data[], int i_start, int i_end)
{
	unsigned pivot = i_end;	// alway pick the last elem as pivot
	// the index of last element of smaller subarray, init -1
	int i_small = i_start - 1;	
	int i = i_start;

	for(; i < i_end; i++) { // loop from start until right before pivot
		if(data[i] < data[pivot]) {
			i_small++;
			swap(data + i_small, data + i);
		}
	}
	swap(data + i_small + 1, data + pivot);
	return i_small + 1;
}

void sort_quick(int data[], int i_start, int i_end)
{
	if(i_start < i_end) {
		unsigned pivot = partition(data, i_start, i_end);
		sort_quick(data, i_start, pivot - 1);
		sort_quick(data, pivot + 1, i_end);
	}
}
