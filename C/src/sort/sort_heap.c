/*
 * *****************************************************************************
 * File: sort_heap.c
 * author: mchen
 * ref:
 *	CLRS 3rd
 *
 * An implementation of heap sort. The idea of heap sort is as follow:
 * a max/min heap partially ordered, i.e. max heap, the largest element
 * is alway the root. So the idea is straightforward, switch the elem
 * of the root and the last elem, decrease the heap size by 1, max 
 * heapify, then we have the second largest elem. So on and on, until the 
 * heap size is 2, one more round, then we have all elements are sorted.
 *
 *				16
 *		14				10
 *	8		7
 * 
 * first round:
 *				7
 *		14				10
 *	8		16
 * max heapify:
 *				14
 *		8				10
 *	7		16
 *
 * second round...
 * *****************************************************************************
 */

#include "../../include/sort/sort.h"
#include "../../include/queue/heap.h"
#include <stdio.h>
#include <stdlib.h>

#define idx_root 0

void sort_heap(int data[], size_t size);
extern void swap(int *a, int *b);

/*
 * @param data
 *	the input integer array
 * @param size
 *	the size the input array
 */
void sort_heap(int data[], size_t size)
{
	unsigned temp_size = size;

	build_max_heap(data, size);
	while(temp_size >= 2 ) {
		swap(data + idx_root, data + temp_size - 1);
		temp_size--;
		max_heapify(data, temp_size, idx_root);
	}
}
