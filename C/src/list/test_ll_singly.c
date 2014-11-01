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
	node_t *list= create_list();

	// insert 0x1
	insert_begin(0x1, list);
	print_list(list);
	assert(find_node(0x1, list) == list->next);

	// insert 0x2
	insert_tail(0x2, list);
	print_list(list);
	assert(find_node(0x2, list) != NULL);

	// insert 0x3, 0x4, 0x5
	insert_tail(0x3, list);
	insert_tail(0x4, list);
	insert_tail(0x5, list);
	print_list(list);

	delete_node(0x3, list);
	print_list(list);
	assert(find_node(0x3, list) == NULL);

	delete_list(list);	
	return 0;
} 
