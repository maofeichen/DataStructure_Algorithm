/*
 * *****************************************************************************
 * file: test_heap.c
 * author: mchen
 *
 * A test of the heap data structure.
 * *****************************************************************************
 */

#include <stdio.h>
#include "../../include/queue/heap.h"

#define IDX_ROOT 0

int main(int argc, char *argv[])
{
	int test_ary[] = {4,1,3,2,16,9,10,14,8,7};
	unsigned size = sizeof(test_ary) / sizeof(test_ary[0]);
	// max_heapify(test_ary, size, IDX_ROOT);
	printf("before build max heap\n");
	disp_heap(test_ary, size);
	build_max_heap(test_ary, size);
	printf("after build max heap\n");
	disp_heap(test_ary, size);
	return 0;
}
