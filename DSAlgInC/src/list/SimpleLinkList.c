/* 
 * This is a link list implementation, reference by the Data Structure and Algorithm Analysis in C 
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/SimpleLinkList.h"

typedef struct node *ptr_node;
typedef ptr_node LIST;
typedef ptr_node NODE;

struct node{
   int element;
   ptr_node next;
 };

/*Test empty list*/
int isEmpty(LIST L){
   return (L->next == NULL);
}

/* Test last node */
int isLast(NODE p, LIST L){ /* L no use */
   return (p->next == NULL);
}

LIST createList(){
  NODE root = malloc(sizeof(struct node));
  root->element = NULL;
  root->next = NULL;
  
  return root;
}

/* Count the number of valid nodes */
int list_length(LIST L){
   int length = 0;
   NODE node = L -> next;

   while(node != NULL){
      length += 1;

      if (node -> next != NULL)
         node = node -> next;
      else
         break;
   }
   return length;
}


/* Create a link list*/
LIST create_list(int val){
  NODE head;
  head = malloc(sizeof (struct node));

  head -> element = val;
  head -> next = NULL;
  return head;
}

// Find node
NODE find(int val, LIST L){
   NODE p;
   p = L->next;
   while ((p->element != val) && (p != NULL)){
      p = p->next;
   }
   return p;
}

// Find previous node
NODE findPrevNode(int val, LIST L){
   NODE p;
   p = L;
   while ((p != NULL) && (p->next->element != val)){
      p = p -> next;
   }
   return p;
}

// Delete Node
void delete(int val, LIST L){
   // find previous node, and delete the previous next node, which is current
   NODE prevNode;
   NODE tempNode;

   prevNode = findPrevNode(val, L);
   tempNode = prevNode -> next;
   prevNode -> next = tempNode -> next;
   free(tempNode);


//   NODE currNode;
//   NODE prevNode;

//   currNode = L->next;
//   while(currNode->element != val) && (currNode != NULL){
//      prevNode = currNode;
//      currNode = currNode->next;
//   }

   // delete node
//   prevNode->next = currNode->next; // bypass p

//   free(currNode);
}

// Insert Node
void insertAfter(int val, LIST L, NODE p){
   NODE tempNode;

   tempNode = (NODE) malloc ( sizeof (struct node));
   if(tempNode == NULL){
      printf("Out of space.");
   }
   else{
      tempNode -> element = val;
      tempNode -> next = p -> next;
      p -> next = tempNode;
   }
}

// Delete List
void deleteList(LIST L){
   NODE node, tempNode;

   node = L -> next;
   L -> next = NULL;

   while(node -> next != NULL){
      tempNode = node -> next;
      free(node);
      node = tempNode;
   }
}

/* Travel the link list*/
void travel_List(LIST L){
   NODE node = L -> next;

   printf("The link list is: ");
   while(node -> next != NULL){
      printf("%d", node -> element);
      printf("->");

      node = node -> next;
   }
   // print the last node
   printf("%d", node -> element);
   printf("\n");
}
