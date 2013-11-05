/*
 */

#include "../include/SimpleLinkList.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
  /* head node */
  struct node *root;
  root = malloc(sizeof(struct node));

  root -> element = 0;
  root -> next = NULL;

  // First node
  position firstNode;
  firstNode = malloc(sizeof(struct node));
  firstNode -> element = 1;
  firstNode -> next = NULL;
  root -> next = firstNode;

  // Second node
  position secNode;
  secNode = malloc(sizeof(struct node));
  secNode -> element = 2;
  secNode -> next = NULL;
  firstNode -> next = secNode;

  // Travel list
  travel_List(root);
}


