/*
 * **********************************************************************
 * File:	ll_singly.h
 * Dest:	singly linked list head file
 * author:	mchen
 * **********************************************************************
 */
  
#ifndef LL_SINGLY_H 
#define LL_SINGLY_H  i

typedef enum {FALSE = 0, TRUE = 1} bool;

typedef Union data {
	int i;
	float f;
	char ch;
	double db;
} data_t;

typedef struct node {
	data_t val;
	struct *node next;
} node_t;

node_t *create_list();
node_t *insert_node();
bool search_node();
void delete_node();
void delete_list(node_t *root);
void print_list(node_t *root);

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
