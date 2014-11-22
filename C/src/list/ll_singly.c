/*
 * **********************************************************************
 * File:	ll_singly.c
 * Dest:	singly linked list 
 * author:	mchen
 * **********************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/list/ll_singly.h"

node_t *create_node();
// int *(comp)(void *, void *);
int num_cmp(void *, void *);
int str_cmp(char *, char *);

node_t *create_list(){
	node_t *head = create_node();
	head->elem = -1;
	head->next = NULL;
	return head;
}

/* insert after a node */
void insert_after(int val, node_t *node){
	node_t *new = create_node();
	new->elem = val;
	new->next = node->next;
	node->next = new;
}

void insert_begin(int val, node_t *list){
	node_t *new = create_node();
	new->elem = val;
	new->next = list->next;
	list->next = new;
}

void insert_tail(int val, node_t *list){
	node_t *new, *tail;
	tail = list;
	while(tail->next != NULL)
		tail = tail->next;
	
	new = create_node();
	new->elem = val;
	new->next = NULL;
	tail->next = new;
}

node_t *find_node(int val, node_t *list, bool is_numr){
	node_t *curr = list;
//	while(curr != NULL && ( (int (*)(&curr->elem, &val))(is_numr ? num_cmp : str_cmp) != 0) )
	while(curr != NULL && curr->elem != val)
		curr = curr->next;
	return curr;
}

bool delete_node(int val, node_t *list, bool is_numr){
	node_t *prev = NULL;
	node_t *curr = list;
	while(curr->elem != val && curr != NULL) {
		prev = curr;
		curr = curr->next;
	}
	if(curr == NULL)
		return FALSE;
	else {
		prev->next = curr->next;
		free(curr);
		return TRUE;
	}
}

void delete_list(node_t *list){
	node_t *prev = NULL;
	node_t *curr = list;
	while(curr != NULL){
		prev = curr;
		curr = curr->next;
		free(prev);
	}
}

void print_list(node_t *list){
	node_t *curr = list;
	printf("Singly list: ");
	while(curr != NULL) {
		printf("%d->", curr->elem);
		curr = curr->next;
	}
	printf("\n");
}

inline node_t *create_node(){
	node_t *new;
	if((new = malloc(sizeof(node_t) ) ) == NULL)
		fprintf(stderr, "fail to create node\n");
	return new;
}

int num_cmp(void *a, void *b){
	double v1, v2;
	v1 = *(double *)a;
	v2 = *(double *)b;

	if(v1 < v2)
		return -1;
	else if(v1 > v2)
		return 1;
	else return 0;
}
