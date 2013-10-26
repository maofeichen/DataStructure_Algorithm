
/*
 * biSearchTree.c
 * Binary Search Tree
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/biSearchTree.h"

struct struBiSrchTreeNode{
   int elem;
   int elemCount; /* for duplicate elem */
   BiSrchTreeNode leftNode;
   BiSrchTreeNode rightNode;
};

BiSrchTree createTree(int elem){
   return createNode(elem);
}

BiSrchTreeNode createNode(int elem){
   BiSrchTreeNode aBiSrchTreeNode = malloc(sizeof(struct struBiSrchTreeNode));
   /* assert(aBiSrchTreeNode == NULL); Why it doesn't work? */
   aBiSrchTreeNode->elem = elem;
   aBiSrchTreeNode->elemCount = 1;
   aBiSrchTreeNode->leftNode = aBiSrchTreeNode->rightNode = NULL;
   return aBiSrchTreeNode;
}

BiSrchTree deleteNode(int elem, BiSrchTree BST){
   BiSrchTreeNode nodeFound = find(elem, BST);
   BiSrchTreeNode tempNode;
   
   if(nodeFound != NULL){
      if(nodeFound->leftNode != NULL && nodeFound->rightNode != NULL){ /* has both left and right sub trees, find min node of right subtree and replace which to the node deleted */
         /* min node of right sub tree*/
         BiSrchTreeNode tempNode = findMin(nodeFound->rightNode);
         /* replace the value with the node needs to be deleted */
         nodeFound->elem = tempNode->elem;
         nodeFound->elemCount = tempNode->elemCount;
         
         /* free(tempNode); not correct, might have right subtree */
         deleteNode(tempNode->elem, nodeFound->rightNode);
      }
      else{ /* one subtree or leaf */
			tempNode = nodeFound;
         if(nodeFound->rightNode == NULL){ /* for left subtree*/
            nodeFound = nodeFound->leftNode;
         }
         else if(nodeFound->leftNode == NULL){ /* for right subtree */
            nodeFound = nodeFound->rightNode;
         }
         free(tempNode);
      }
   }
   return BST;
}

/*
 * My implementation:
 * Disad:
 *    when has two children, attach left subtree to left most of right subtree. If left subtree is some how deep, then make the whole tree much deeper by this way
 */
BiSrchTree deleteNodeMyImplmnt(int elem, BiSrchTree BST){
   BiSrchTreeNode nodeFound = find(elem, BST);
   if(nodeFound != NULL){
      if(nodeFound->leftNode == NULL && nodeFound->rightNode == NULL) /* for leaf */
         free(nodeFound);
      else if(nodeFound->leftNode != NULL && nodeFound->rightNode == NULL) /* for left subtree*/
         ;
      else if(nodeFound->leftNode == NULL && nodeFound->rightNode != NULL) /* for right subtree */
         ;
      else /* has both left and right sub trees, attach left subtree to right subtree */
         ;
   }
   return BST;
}

BiSrchTreeNode find(int elem, BiSrchTree BST){
   if(BST == NULL)
      return NULL;
   else{
      if(elem < BST->elem)
         return find(elem, BST->leftNode);
      else if(elem > BST->elem)
         return find(elem, BST->rightNode);
      else /* found */
         return BST;
   }
}

BiSrchTreeNode findMax(BiSrchTree BST){
   if(BST == NULL)
      return NULL;
   else{
      if(BST->rightNode != NULL)
         return findMax(BST->rightNode);
      else
         return BST;
   }
}

BiSrchTreeNode findMaxNonRecur(BiSrchTree BST){
   if(BST != NULL)
      while(BST->rightNode != NULL)
         BST = BST->rightNode;
   return BST;
}

BiSrchTreeNode findMin(BiSrchTree BST){
   if(BST == NULL)
      return NULL;
   else{
      if(BST->leftNode == NULL)
         return BST;
      else
         return findMin(BST->leftNode);
   }
}

BiSrchTreeNode findMinNonRecur(BiSrchTree BST){
   if(BST != NULL)
      while(BST->leftNode != NULL)
         BST = BST->leftNode;
   return BST;
}

BiSrchTreeNode findMyImplmnt(int elem, BiSrchTree BST){
   if(BST != NULL){
      if(elem < BST->elem)
         find(elem, BST->leftNode); /* Have to return */
      else if(elem > BST->elem)
         find(elem, BST->rightNode);
      else
         return BST;
   }
   return NULL; /* not found */
}

/*
 * better implementation from book
 * 1) avoid unnecessary create tree node each recursion
 * 2) better logic
 */
BiSrchTree insertNode(int elem, BiSrchTree BST){
   if(BST == NULL)
      BST = createNode(elem);
   else{
      if(elem < BST->elem)
         BST->leftNode = insertNode(elem, BST->leftNode);
      else if(elem > BST->elem)
         BST->rightNode = insertNode(elem, BST->rightNode);
      else /* duplicate elem */
         BST->elemCount++;
   }
   return BST;
}

BiSrchTree insertNodeMyImplmnt(int elem, BiSrchTree BST){
   /* to create a BST node each recursion, but unnecessary */
   BiSrchTreeNode aBiSrchTreeNode = createNode(elem);

   if(elem < BST->elem){
      if(BST->leftNode == NULL)
         BST->leftNode = aBiSrchTreeNode;
      else
         insertNode(elem, BST->leftNode);
   }
   else if(elem > BST->elem){
      if(BST->rightNode == NULL)
         BST->rightNode = aBiSrchTreeNode;
      else
         insertNode(elem, BST->rightNode);
   }
   /* else elem is in the BST already, do nothing */
   return BST;    /* don't forget */
}

BiSrchTree makeEmpty(BiSrchTree BST){
   if(BST != NULL){
      makeEmpty(BST->leftNode);
      makeEmpty(BST->rightNode);
      free(BST);
   }
   return NULL;
}

void traverseInOrder(BiSrchTree BST, char *tab){
   if(BST != NULL){
      traverseInOrder(BST->leftNode, tab);
      strcat(tab, "\t");
      printf("%s%d->\n", tab, BST->elem);
      traverseInOrder(BST->rightNode, tab);
   }
}

void traversePostOrder(BiSrchTree BST, char *tab){}

void traversePreOrder(BiSrchTree BST, char tab[]){
   if(BST != NULL){
      strcat(tab, "\t");
      printf("%s%d->\n", tab, BST->elem);
      traversePreOrder(BST->leftNode, tab);
      traversePreOrder(BST->rightNode, tab);
   } 
}
