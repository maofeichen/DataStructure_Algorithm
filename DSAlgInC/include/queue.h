/* queue.h 
 * header file
 */
#ifndef QUEUE_H
#define QUEUE_H

struct Queue;
typedef struct Queue *pQueue;

int frontAndDequeue(pQueue Q);
int frontQueue(pQueue Q);
int isQueueEmpty(pQueue Q);
int isQueueFull(pQueue Q);
pQueue createQueue(unsigned int QUEUE_SIZE);
void dequeue(pQueue Q);
void disposeQueue(pQueue Q);
void enqueue(int elem, pQueue Q);
void makeQueueEmpty(pQueue Q);
void traverseQueue(pQueue Q);

#endif
