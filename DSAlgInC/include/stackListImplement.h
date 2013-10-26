/*
 * stack implemented by circular double link list
 */

#ifdef STACKLISTIMPLEMENT_H
#define STACKLISTIMPLEMENT_H

#include "cirDoubleLinkList.h"

// struct node;
// typedef struct node *ptr_node;
typedef ptr_node Stack;

int isStackEmpty(Stack S);
Stack createStack(void);
void disposeStack(Stack S); /* not implement */
void makeStackEmpty(Stack S); /* not implement */
void push(Stack S);
void pop(Stack S);
int top(Stack S);
int countStack(Stack S);

#endif
