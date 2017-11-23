/*
 * **********************************************************************
 * File:	ll_singly.h
 * Dest:	singly linked list head file
 * author:	mchen
 * **********************************************************************
 */
  
#ifndef LL_SINGLY_H 
#define LL_SINGLY_H  

#define ARRAY_SZ 20

typedef enum {FALSE = 0, TRUE = 1} bool;
typedef enum {T_INT, T_STR} type_t;

typedef union data {
	int i;
	float f;
	char ch;
	double db;
	char ch_ary[ARRAY_SZ];
} data_t;

typedef struct node {
	data_t elem;
	struct node *next;
} node_t;

data_t create_elem(void *, type_t);
node_t *create_list(type_t);
void insert_after(void *, node_t *, type_t);
void insert_begin(void *, node_t *, type_t);
void insert_tail(void *, node_t *, type_t);
node_t *find_node(void *, node_t *, type_t);
bool delete_node(void *, node_t *, type_t);
void delete_list(node_t *);
void print_list(node_t *, type_t);
#endif
