/*
 * sort.c
 * sort algorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/sort.h"

/* insert sort */
void sortInsert(int data[], int SIZE){
	for(int i = 1; i <= SIZE - 1; i++){
		for(int j = 0; j < i; j++){
			if(data[i] < data[j]){
				/* switch item i and j */
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
				break;
			}
		}
	}
}
