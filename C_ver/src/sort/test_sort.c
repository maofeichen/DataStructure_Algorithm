/*
 * *****************************************************************************
 * File: test_sort.c
 * author: mchen
 *
 * test of implemented sort algorithm
 * *****************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../include/sort/sort.h"

#define TEST_ARRAY_SIZE 50000
#define RAND_RANGE 1000

int main(int argc, char *argv[])
{
	/* init test array */
	int test_ary[TEST_ARRAY_SIZE];
	for(int i = 0; i < TEST_ARRAY_SIZE; i++)
		test_ary[i] = rand() % RAND_RANGE;

#define SORT_INSERT

#ifdef SORT_INSERT
	sort_insert(test_ary, TEST_ARRAY_SIZE);
#endif

	/* print result after sorting */
	printf("the test array is: \n");
	for(int i = 0; i < TEST_ARRAY_SIZE; i++)
		printf("%d ", test_ary[i]);
	printf("\n");
}
