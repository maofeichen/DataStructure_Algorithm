/*
 * mainBiSearchTree.
 * main for Binary Search Tree
 */

#include <stdio.h>
#include "../include/biSearchTree.h"

int main(){
   /* binary search tree test*/
   BiSrchTree aBiSrchTree = createTree(10);
   insertNode(5, aBiSrchTree);
   insertNode(18, aBiSrchTree);

   char tab[1024];
   traversePreOrder(aBiSrchTree, tab);

	deleteNode(5, aBiSrchTree);
	traversePreOrder(aBiSrchTree, tab);
}
