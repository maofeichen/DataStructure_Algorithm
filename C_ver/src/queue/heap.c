/*
 * *****************************************************************************
 * file: heap.c
 * author: mchen
 *
 * ref:
 *	CLRS 3rd
 *
 * desc: An implementation of the heap data structure. There are max and min
 * heaps, implement max-heap first, assume the input is a integer array.
 * *****************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void disp_heap(int data[], unsigned size);
void max_heapify(int data[], unsigned size, unsigned idx_root);
extern void swap(int *a, int *b);

/*
 * @param data
 *	the input integer array
 * @param size
 *	the size the input array
 *
 * display the input array as binary tree format
 */
void disp_heap(int data[], unsigned size)
{
	int idx_p = 0;	/* print index */
	unsigned high = ceil( log(size) / log(2) ) + 1;
#ifdef DEBUG
	printf("the high of the binary heap is: %d\n", high);
#endif

	int idx_data = 0;
	int idx_high = 1;
	for(; idx_data <= size - 1; idx_data++) {
		// int idx_fir_at_lev = log(idx_data + 1) / log(2 ); 
		if( idx_data + 1 == pow(2, idx_high) ){
			printf("\n");
			idx_high++;
		}
		printf("%d\t", data[idx_data]);
	}
	printf("\n");
}

/*
 * @param data
 *	the input integer array
 * @param size
 *	the size the input array
 * @param idx_root
 *	the index of the root node, start from 0
 *
 * To maintaint the max heap property: the value of parents always larger than
 * the values of childrens. Assume that only the root of the "binary tree"
 * might not follow the property, the left and right subtrees of root follow
 * the property.
 *
 * The idea is comparing the root and its two childrens recursively, if one of
 * child is larger than the root, swap them. So on and on until the smaller 
 * value being "pushed" to the buttom of the tree.
 */
void max_heapify(int data[], unsigned size, unsigned idx_root)
{
	unsigned idx_lchild = 2 * idx_root + 1;
	unsigned idx_rchild = 2 * idx_root + 2;
	/* index of the largest val of the three, init to index root becus
 	 * otherwise the last test condition always true, the program won't 
	 * stop */
	unsigned idx_largest = idx_root;	

	if (idx_lchild < size - 1)
		if (data[idx_root] < data[idx_lchild])
			idx_largest = idx_lchild;
		else
			idx_largest = idx_root;

	if(idx_rchild < size - 1)
		if(data[idx_largest] < data[idx_rchild])
			idx_largest = idx_rchild;

	if(idx_largest != idx_root ) {
		swap(&data[idx_largest], &data[idx_root]);
		max_heapify(data, size, idx_largest);
	}
}
