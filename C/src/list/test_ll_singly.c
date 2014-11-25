/* 
 * **********************************************************************
 * File:	test_ll_singly.c
 * Dest:	test singly linked list
 * author:	mchen
 * **********************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include "../../include/list/ll_singly.h"

int main(int argc, char *argv[]) {
	int i = 0x1;
	node_t *list= create_list(T_INT);
	// insert 0x1
	insert_begin(&i, list, T_INT);
	print_list(list, T_INT);
	assert(find_node(&i, list, T_INT) == list->next);

	// insert 0x2
	i = 0x2;
	insert_tail(&i, list, T_INT);
	print_list(list, T_INT);
	assert(find_node(&i, list, T_INT) != NULL);

	// insert 0x3, 0x4, 0x5
	i = 0x3;
	insert_tail(&i, list, T_INT);
	i = 0x4;
	insert_tail(&i, list, T_INT);
	i = 0x5;
	insert_tail(&i, list, T_INT);
	print_list(list, T_INT);

	i = 0x3;
	delete_node(&i, list, T_INT);
	print_list(list, T_INT);
	assert(find_node(&i, list, T_INT) == NULL);

	delete_list(list);	
	return 0;
} 
