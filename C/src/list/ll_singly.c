/*
 * **********************************************************************
 * File:	ll_singly.c
 * Dest:	singly linked list 
 * author:	mchen
 * **********************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../include/list/ll_singly.h"

node_t *create_list(){
	node_t *head;
	if((head = malloc(sizeof(node_t) ) ) == NULL)
		fprintf(stderr, "fail to create list\n");
	head->elem = -1;
	head->next = NULL;
	return head;
}

/* insert after a node */
void insert_after(int val, node_t *node){
	node_t *new;
	if((new = malloc(sizeof(node_t) ) ) == NULL)
		fprintf(stderr, "fail to create node\n");
	new->elem = val;
	new->next = node->next;
	node->next = new;
}

void insert_begin(int val, node_t *list){
	node_t *new;
	if((new = malloc(sizeof(node_t) ) ) == NULL)
		fprintf(stderr, "fail to create node\n");
	new->elem = val;
	new->next = list->next;
	list->next = new;
}

void insert_tail(int val, node_t *list){
	node_t *new, *tail;
	tail = list;
	while(tail->next != NULL)
		tail = tail->next;

	if((new = malloc(sizeof(node_t) ) ) == NULL)
		fprintf(stderr, "fail to create node\n");
	new->elem = val;
	new->next = NULL;
	tail->next = new;
}

node_t *find_node(int val, node_t *list){
	node_t *curr = list;
	while(curr != NULL && curr->elem != val)
		curr = curr->next;
	return curr;
}

bool delete_node(int val, node_t *list){
	node_t *prev = NULL;
	node_t *curr = list;
	while(curr->elem != val && curr != NULL) {
		prev = curr;
		curr = curr->next;
	}
	if(curr == NULL)
		return FALSE;
	else {
		prev->next = curr->next;
		free(curr);
		return TRUE;
	}
}

void delete_list(node_t *list){
	node_t *prev = NULL;
	node_t *curr = list;
	while(curr != NULL){
		prev = curr;
		curr = curr->next;
		free(prev);
	}
}

void print_list(node_t *list){
	node_t *curr = list;
	printf("Singly list: ");
	while(curr != NULL) {
		printf("%d->", curr->elem);
		curr = curr->next;
	}
	printf("\n");
}

#if 0
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
#endif
