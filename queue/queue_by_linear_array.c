#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3
/* linear array queue ADT
 *
 * 생성             : 특정 길이의 array 혹은 struct
 * 초기 상태        : front = rear = -1
 * 공백 조건        : front = rear
 * 포화 조건        : rear = n-1 (array 마지막 index)
 * enqueue(q,item)  :   1. is_full 검사
 *                      2. rear += 1
 *                      3. q의 (rear)번째 자리에 item 삽입
 * dequeue(q)       :   1. is_empty 검사
 *                      2. q의 (front)번째 자리의 요소 반환
 *                      3. front += 1
 *
 * 특이사항         : front, rear는 계속 증가하기만 하게 된다. 그리고 array는
 * 한정된 길이를 갖고 있으므로 문제다. 따라서 주기적으로 front, rear을 하나씩
 * 감소시켜야 한다. 여기선 구현 안 했음 */

typedef char element;
/* create queue */
typedef struct {
  element queue[MAX_SIZE];
  int front, rear;
} ArrayQueue;

ArrayQueue *createQueue() {
  ArrayQueue *Q;
  Q = (ArrayQueue *)malloc(sizeof(ArrayQueue));
  Q->front = -1;
  Q->rear = -1;
  return Q;
}

bool isEmpty(ArrayQueue *Q) { return (Q->front == Q->rear); }

bool isFull(ArrayQueue *Q) { return (Q->rear == (MAX_SIZE - 1)); }

void enqueue(ArrayQueue *Q, element item) {
  // check is queue full
  if (isFull(Q)) {
    printf("queue is full!");
    exit(1);
  } else {
    Q->queue[++Q->rear] = item;
  }
}

void dequeue(ArrayQueue *Q) {
  // check is empty
  if (isEmpty(Q)) {
    printf("queue is empty!");
    exit(1);
  } else {
    element result = Q->queue[++Q->front];

    printf("dequeue --> %c\n", result);
  }
}

void printQueue(ArrayQueue *Q) {
  printf("\nfront=%i rear=%i \n", Q->front, Q->rear);
  printf("QUEUE [ ");
  for (int i = Q->front + 1; i < Q->rear + 1; i++) {
    printf("%c ", Q->queue[i]);
  }
  printf("]\n");
}

int main() {
  ArrayQueue *myQ = createQueue();
  printQueue(myQ);

  enqueue(myQ, 'A');
  printQueue(myQ);
  enqueue(myQ, 'B');
  printQueue(myQ);
  enqueue(myQ, 'C');
  printQueue(myQ);

  dequeue(myQ);
  printQueue(myQ);

  // 특이사항 : 앞에 한 자리가 비어있음에도, rear가 마지막 index이므로 수행 불가  
  enqueue(myQ, 'A');
  printQueue(myQ);
  enqueue(myQ, 'B');
  printQueue(myQ);

  dequeue(myQ);
  printQueue(myQ);
  dequeue(myQ);
  printQueue(myQ);



}
