/*
 * stack implemented by circular double link list
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/cirDoubleLinkList.h"
#include "../include/stackListImplement.h"

typedef ptr_node Stack;

Stack createStack(){
   return createList();
}

int isStackEmpty(Stack S){
   return isEmpty(S);
}

int countStack(Stack S){
   return countList(S);
}

void push(int val, Stack S){
   if (isStackEmpty(S) == 1)
      insertNodeEmpty(val, S);
   else
      insertNodeHead(val, S);
}

void pop(Stack S){
   if(countStack(S) > 0) /* if not empty */
      deleteNodeAfterHead(S);
}

int top(Stack S){
   return S -> next -> data;
}
