/*
 * *****************************************************************************
 * file: heap.h
 * author: mchen
 *
 * The head file of the heap data structure.
 * *****************************************************************************
 */

#ifndef _HEAP_H
#define _HEAP_h

void disp_heap(int data[], unsigned size);
void max_heapify(int data[], unsigned size, unsigned idx_root);

#endif
