#ifndef SIMPLELINKLIST_H
#define SIMPLELINKLIST_H 

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
void InsertAtTail(int item, LIST L); /* not implement */
void deleteList(LIST L);

#endif
