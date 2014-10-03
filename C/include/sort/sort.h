/* *****************************************************************************
 * File: sort.h
 * author: mchen
 *
 * header file of sort
 * *****************************************************************************/

#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

void sort_insert(int data[], size_t len);
void sort_merge(int data[], int i_start, int i_end);
void sort_heap(int data[], size_t size);

#endif
