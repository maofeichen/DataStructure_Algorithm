/*
 * stack_arry_implmnt.c
 * stack - array implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/stack_arry_implmnt.h"

#define EMPTY_STACK -1

struct stack {
  int capacity;
  int top_stack;
  int *stackBuf;
};

typedef struct stack *pStack;
typedef struct stack Stack;

int is_stack_empty(pStack S){
  return S->top_stack == EMPTY_STACK;
}

int isStackFull(pStack S){
  return S->top_stack == S->capacity - 1;
}

pStack create_stack(unsigned int STACK_SIZE){
  if (STACK_SIZE == 0)
	;

  pStack S = malloc(sizeof(Stack));
  if (S == NULL)
	;

  S->stackBuf = malloc(sizeof(int) * STACK_SIZE);
  if (S->stackBuf == NULL)
	;

  S->capacity = STACK_SIZE;
  S->top_stack = EMPTY_STACK;
  return S;
}

void push(int item, pStack S){
  if (isStackFull(S) == 1)
	;

  S -> stackBuf[++S->top_stack] = item;
}

void pop(pStack S){
  if(is_stack_empty(S) == 1)
	;

  S->top_stack--;
}

int top(pStack S){
  if(is_stack_empty(S) == 1)
	;
  return S->stackBuf[S->top_stack];
}
