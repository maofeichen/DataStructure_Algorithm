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
	int test_ary[] = {1, 10, 9, 8, 7};
	unsigned size = sizeof(test_ary) / sizeof(test_ary[0]);
	max_heapify(test_ary, size, IDX_ROOT);
	disp_heap(test_ary, size);

	return 0;
}
