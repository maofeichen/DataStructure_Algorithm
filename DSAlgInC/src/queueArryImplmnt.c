/* 
 * queueArryImplmnt.c
 * Queue - Array Implementation
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

struct Queue{
  int capacity;
  int nElem;
  int *pFront;
  int *pRear;
  int *pQueueBuf;
};
typedef struct Queue QUEUE;

int frontAndDequeue(pQueue Q){
  if(isQueueEmpty(Q) != 1){
    Q->nElem--;
    return *Q->pFront++;
  }
}

int frontQueue(pQueue Q){
  if(isQueueEmpty(Q) != 1)
    return *Q->pFront;
}

int isQueueEmpty(pQueue Q){
  return Q->nElem == 0;
}

int isQueueFull(pQueue Q){
  return Q->nElem == Q->capacity;
}

pQueue createQueue(unsigned int QUEUE_SIZE){
  assert(QUEUE_SIZE > 0);
  pQueue pNewQueue = malloc(sizeof(QUEUE));
  assert(pNewQueue != NULL);

  pNewQueue->pQueueBuf = malloc(sizeof(int) * QUEUE_SIZE);
  assert(pNewQueue->pQueueBuf != NULL);

  pNewQueue->capacity = QUEUE_SIZE;
  pNewQueue->nElem = 0;
  pNewQueue->pRear = pNewQueue->pFront = pNewQueue->pQueueBuf;
  return pNewQueue;
}

void dequeue(pQueue Q){
  if(Q->nElem > 1){
    Q->pFront++;
    Q->nElem--;
  }
  else if(Q->nElem == 1)
    Q->nElem--;
}

void disposeQueue(pQueue Q){}

/* if queue not full, insert item at rear
 * it might happen that the rear has reached the array maximum position,
 * then it need to jump at the begin of the array
 */
void enqueue(int elem, pQueue Q){
  if(isQueueFull(Q) != 1){   /* if there is space */
    if(Q->pRear == Q->pQueueBuf + Q->capacity){ /* pRear reach array high end */
      *Q->pRear = elem;
      Q->pRear = Q->pQueueBuf;                  /* pRear repoint to array low end  begin */
    }
    else
      *Q->pRear++ = elem;      
    Q->nElem++;
  }
}

void makeQueueEmpty(pQueue Q){}

void traverseQueue(pQueue Q){
  int *pTmpFront = Q->pFront;   /* have to use temp pointer */
  int *pTmpRear = Q->pRear;

  if(pTmpFront <= pTmpRear){    /* if front ptr is below rear ptr */
    while(pTmpFront < pTmpRear){
      printf("%d->", *pTmpFront++);
    }
  }
  else{                         /* if front ptr is upper rear ptr */
    while(pTmpFront != Q->pQueueBuf + Q->capacity){
      printf("%d->", *pTmpFront++);
    }

    printf ("%d->", *pTmpFront); /* print the item at high end */
    pTmpFront = Q->pQueueBuf;    /* front ptr re points to low end */

    while(pTmpFront < pTmpRear){
      printf("%d->", *pTmpFront++);
    }
  }
  printf("\n");
}
