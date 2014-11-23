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

void err(void);
node_t *create_node();
node_t *insert_new(data_t val, type_t t);
int cmp(data_t *, data_t *, type_t t);
int num_cmp(void *, void *);

node_t *create_list(type_t t){
	node_t *head = create_node();
	switch(t){
		case T_INT: head->elem.i = -1; break;
		case T_STR: break;
		default: err();
	}
	head->next = NULL;
	return head;
}

/* insert after a node */
void insert_after(data_t val, node_t *node, type_t t){
	node_t *new = insert_new(val, t);
	new->next = node->next;
	node->next = new;
}

void insert_begin(data_t val, node_t *list, type_t t){
	node_t *new = insert_new(val, t);
	new->next = list->next;
	list->next = new;
}

void insert_tail(data_t val, node_t *list, type_t t){
	node_t *new, *tail;
	tail = list;
	while(tail->next != NULL)
		tail = tail->next;
	
	new = insert_new(val, t);
	new->next = NULL;
	tail->next = new;
}

node_t *find_node(data_t val, node_t *list, type_t t){
	node_t *curr = list;
//	while(curr != NULL && curr->elem != val)
	while(curr != NULL && cmp(&curr->elem, &val, t) != 0)
		curr = curr->next;
	return curr;
}

bool delete_node(data_t val, node_t *list, type_t t){
	node_t *prev = NULL;
	node_t *curr = list;
	while(curr != NULL && cmp(&curr->elem, &val, t) != 0){
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

void print_list(node_t *list, type_t t){
	node_t *curr = list;
	printf("Singly list: ");
	while(curr != NULL) {
		switch(t){
			case T_INT: printf("%d->", curr->elem.i);
			case T_STR: printf("%s->", curr->elem.ch_ary);
			default: err();
		}
		curr = curr->next;
	}
	printf("\n");
}

inline void err(){fprintf(stderr, "err type\n"); exit(1);}

inline node_t *create_node(){
	node_t *new;
	if((new = malloc(sizeof(node_t) ) ) == NULL)
		fprintf(stderr, "fail to create node\n");
	return new;
}

inline node_t *insert_new(data_t val, type_t t){
	node_t *new = create_node();
	switch(t){
		case T_INT: new->elem.i = val.i; break;
		case T_STR: 
			strncpy(new->elem.ch_ary, val.ch_ary, ARRAY_SZ - 1);
			new->elem.ch_ary[ARRAY_SZ-1] = '\0';
			break;
		default: err();
	}
	return new;
}

inline int cmp(data_t *v1, data_t *v2, type_t t){
	switch(t){
		case T_INT: return num_cmp(&v1->i, &v2->i);
		case T_STR: return strcmp(v1->ch_ary, v2->ch_ary);
		default: err();
	}
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
