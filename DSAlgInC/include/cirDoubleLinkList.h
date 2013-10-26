#ifndef CIRDOUBLELINLIST_H
#define CIRDOUBLELINLIST_H 
/* cirDoubleLinkList.h 
 * circular double link list
 * reference by the data structure and analysis in c and other online material
 */

/* The basic node */
typedef struct node *ptr_node;

struct node /* no () */{
   int data;
   struct node *next;
   struct node *prev;
}; /* remember ; */

typedef ptr_node LIST;
typedef ptr_node NODE;
typedef ptr_node POSITION;

int isEmpty(LIST L);
// LIST createList(int data);
int countList(LIST L);
LIST createList(void);
NODE findNode(int data, LIST L);
void insertNodeEmpty(int data, LIST L);
void insertNodeAfter(int data, POSITION p, LIST L);
void insertNodeHead(int data, LIST L);
void insertNodeTail(int data, LIST L);
void deleteNodeAfterHead(LIST L);
void deleteNode(int data, LIST L);
void deleteList(LIST L);
void traversList(LIST L);

#endif

