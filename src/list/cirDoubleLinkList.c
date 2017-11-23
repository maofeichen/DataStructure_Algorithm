/*
 * cirDoubleLinkList.c
 * circular double link list
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/cirDoubleLinkList.h"

int isEmpty(LIST L){
   return (L -> next == NULL);
}

int countList(LIST L){
   int int_count = 0;
   NODE ptr_current = L -> next;
   if (ptr_current != NULL){
      int_count++;
      while(ptr_current -> next != L){
         int_count += 1;
         ptr_current = ptr_current -> next;
      }
   }
   return int_count;
}

LIST createList(){
   NODE head = malloc(sizeof(struct node));
   head -> data = NULL;
   head -> next = NULL;
   head -> prev = NULL;

   return head;
}

// LIST createList(int data){
//    NODE head, firstNode;
//    head = malloc(sizeof(struct node));
//    firstNode = malloc(sizeof(struct node));
// 
//    head -> data = NULL;
//    head -> next = firstNode;
//    head -> prev = firstNode;
// 
//    firstNode -> data = data;
//    firstNode -> prev = head;
//    firstNode -> next = head;
// 
//    return head;
// }

/* return NULL if not found */
NODE findNode(int data, LIST L){
   NODE currNode = L -> next;

   /* Test condition is if equal head, not equal to NULL */
   while(currNode -> next != L){
      if (currNode -> data == data)
         return currNode;
      currNode = currNode -> next;
   }
   return NULL; 
}

/*Insert node to empty list*/
void insertNodeEmpty(int data, LIST L){
   NODE newNode = malloc(sizeof(struct node));
   newNode -> data = data;

   newNode -> prev = L;
   newNode -> next = L;

   L -> next = newNode;
   L -> prev = newNode;
}

/* Always insert node after head */
void insertNodeHead(int data, LIST L){
   NODE newNode = malloc(sizeof(struct node));
   newNode -> data = data;

   newNode -> next = L -> next;
   newNode -> prev = L;

   L -> next = newNode;
   (newNode -> next) -> prev = newNode; /* it is newNode -> next instead of L -> next, because later has been changed*/
}

/* Always insert node after tail*/
void insertNodeTail(int data, LIST L){
   NODE newNode, tail;
   newNode = malloc(sizeof(struct node));
   newNode -> data = data;

   tail = L -> next;
   while(tail -> next != L)
      tail = tail -> next;

   newNode -> next = tail -> next;
   newNode -> prev = tail;

   tail -> next = newNode;
}

/* Insert node after given position and assume the position is neither head nor tail*
 * What about LIST L?
 */
void insertNodeAfter(int data, POSITION p, LIST L){
   NODE newNode = malloc(sizeof(struct node));
   newNode -> data = data;

   newNode -> next = p -> next;
   newNode -> prev = p;

   p -> next = newNode;
}

/* Delete node after head */
void deleteNodeAfterHead(LIST L){
   if (isEmpty(L) != 1){
      NODE firstNode = L -> next;
      
      /* Assume more than two nodes*/
      L -> next = firstNode -> next;
      (firstNode -> next) -> prev = L;
      free(firstNode);
   }
}

/* Delete node with the same data value */
void deleteNode(int data, LIST L){
   NODE nodeDel;
   nodeDel = findNode(data, L);

   if (nodeDel != NULL){
      (nodeDel -> prev) -> next = nodeDel -> next;
      (nodeDel -> next) -> prev = nodeDel -> prev;

      free(nodeDel);
   }
}

void deleteList(LIST L){
   NODE currNode = L -> next;
   while(currNode -> next != L){ /* leave head and tail, delete others */ 
      currNode = currNode -> next;
      free(currNode -> prev);
   }

   free(L);
   free(currNode);
}

void traversList(LIST L){
   NODE currNode = L -> next;

   while(currNode -> next != L){
      printf("%d", currNode -> data);
      printf("->");
      currNode = currNode -> next;
   }

   printf("%d\n", currNode -> data);
}
