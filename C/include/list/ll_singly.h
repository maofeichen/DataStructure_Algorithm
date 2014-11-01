/*
 * **********************************************************************
 * File:	ll_singly.h
 * Dest:	singly linked list head file
 * author:	mchen
 * **********************************************************************
 */
  
#ifndef LL_SINGLY_H 
#define LL_SINGLY_H  

typedef enum {FALSE = 0, TRUE = 1} bool;

typedef union data {
	int i;
	float f;
	char ch;
	double db;
} data_t;

typedef struct node {
	int elem;
	struct node *next;
} node_t;

node_t *create_list();
void insert_after(int, node_t *);
void insert_begin(int, node_t *);
void insert_tail(int, node_t *);
node_t *find_node(int, node_t *);
bool delete_node(int, node_t *);
void delete_list(node_t *);
void print_list(node_t *);

/*
typedef struct node *ptr_node;
typedef ptr_node LIST;
typedef ptr_node position;

int isEmpty(LIST L);
int isLast(position p, LIST L);
LIST createList(void);
position find(int val, LIST L);
position findPrevNode(int val, LIST L);
void delete(int val, LIST L);
void insertAfter(int val, LIST L, position p);
void InsertAtTail(int item, LIST L); // not implement 
void deleteList(LIST L);
*/
#endif
