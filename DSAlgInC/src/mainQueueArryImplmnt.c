/* 
 * mainQueueArryImplmnt.c
 * main for queue - array implementation
 */

#include <stdio.h>
#include "../include/queue.h"

int main(){
  printf("Test Queue Array Implementation!\n");
  pQueue testQueue = createQueue(5);

  printf("Testcase 1: the queue is not full\n");
  enqueue(1, testQueue);
  enqueue(2, testQueue);
  enqueue(3, testQueue);
  /* printf("The first item is: %d\n", frontAndDequeue(testQueue));   */
  /* printf("The first item is: %d\n", frontAndDequeue(testQueue));   */
  /* printf("The first item is: %d\n", frontAndDequeue(testQueue)); */
  traverseQueue(testQueue);

  printf("Testcase 2: the queue is full\n");
  enqueue(4, testQueue);
  enqueue(5, testQueue);
  traverseQueue(testQueue);
  
  printf("Testcase 3: the rear reach array high end\n");
  dequeue(testQueue);
  enqueue(6, testQueue);
  traverseQueue(testQueue);

  printf("Testcase 4: the rear is smaller/below than the fornt\n");
  dequeue(testQueue);
  enqueue(7, testQueue);
  traverseQueue(testQueue);
}
