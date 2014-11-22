/*
 * **********************************************************************
 * File:	ll_singly.h
 * Dest:	singly linked list head file
 * author:	mchen
 * **********************************************************************
 */
  
#ifndef LL_SINGLY_H 
#define LL_SINGLY_H  

#define ARY_SZ 20
typedef enum {FALSE = 0, TRUE = 1} bool;

typedef union data {
	int i;
	float f;
	char ch;
	double db;
	char ch_ary[20];
} data_t;

typedef struct node {
	int elem;
	struct node *next;
} node_t;

node_t *create_list();
void insert_after(int, node_t *);
void insert_begin(int, node_t *);
void insert_tail(int, node_t *);
node_t *find_node(int, node_t *, bool);
bool delete_node(int, node_t *, bool);
void delete_list(node_t *);
void print_list(node_t *);
#endif
