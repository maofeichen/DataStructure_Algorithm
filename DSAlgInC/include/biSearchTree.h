/*
 * biSearchTree.h
 * Binary Search Tree - Header File
 */

#ifndef BISEARCHTREE_H
#define BISEARCHTREE_H

struct struBiSrchTreeNode;		  /* struct declaration */
typedef struct struBiSrchTreeNode *pBiSrchTreeNode;
typedef pBiSrchTreeNode BiSrchTree;
typedef pBiSrchTreeNode BiSrchTreeNode;

BiSrchTree createTree(int elem);
BiSrchTreeNode createNode(int elem);
void disposeTree(BiSrchTree BST);

BiSrchTree deleteNode(int elem, BiSrchTree BST);
BiSrchTree deleteNodeMyImplmnt(int elem, BiSrchTree BST);

BiSrchTreeNode find(int elem, BiSrchTree BST);
BiSrchTreeNode findMax(BiSrchTree BST);
BiSrchTreeNode findMaxNonRecur(BiSrchTree BST);
BiSrchTreeNode findMin(BiSrchTree BST);
BiSrchTreeNode findMinNonRecur(BiSrchTree BST);
BiSrchTreeNode findMyImplmnt(int elem, BiSrchTree BST);

BiSrchTree insertNode(int elem, BiSrchTree BST);
BiSrchTree insertNodeMyImplmnt(int elem, BiSrchTree BSt);
BiSrchTree makeEmpty(BiSrchTree BST);
int retrive(BiSrchTreeNode Node);

void traverseInOrder(BiSrchTree BST, char *tab);
void traversePostOrder(BiSrchTree BST, char *tab);
void traversePreOrder(BiSrchTree BST, char tab[]);

#endif
