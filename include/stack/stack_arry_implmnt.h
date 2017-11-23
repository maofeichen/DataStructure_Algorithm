/*
 * stack - array implementation
 */

#ifdef STACKARRAYIMPLEMENT_H
#define STACKARRAYIMPLEMENT_H 

typedef struct stack *pStack;
typedef struct stack Stack;

// pStack create_stack(void);
int isStackFull(pStack S);
int is_stack_empty(pStack S);
int numItem(pStack S);  /* not implement */
int top(pStack S);
pStack create_stack(unsigned int STACK_SIZE);
void disposeStack(pStack S); /* not implement */
void makeStackEmpty(pStack S);
void pop(pStack S);
void push(int item, pStack S);

#endif
