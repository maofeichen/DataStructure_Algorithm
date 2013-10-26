/*
 * main.c for cirDoubleLinkList.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/cirDoubleLinkList.h"

int main(){
   NODE List;
   List = createList();
   insertNodeEmpty(1, List);
   insertNodeHead(2, List);
   insertNodeHead(3, List);
   traversList(List);

   NODE findTest;
   findTest = findNode(2, List);
   printf("%d\n", findTest -> data);
   printf("the prev node is: %d\n", findTest -> prev -> data);
   printf("the next node is: %d\n", findTest -> next -> data);

   printf("delete after head test\n");
   printf("Test count\n");
   printf("The number of node is: %d\n", countList(List));
   deleteNodeAfterHead(List);
   // deleteNode(2, List);
   printf("The number of node is: %d\n", countList(List));
   traversList(List);
}
