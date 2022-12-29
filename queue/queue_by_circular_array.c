#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4
/* circular array queue ADT
 *
 * 생성             : struct of 1 array, 2 element
 * 초기 상태        : front = rear = 0
 * front는 항상 첫번째 원소의 하나 앞을, rear는 마지막 원소의 index를 가짐.
 * front 자리는 항상 빈 자리. 공백과 포화를 구분하기 위함.
 * 공백 조건        : front = rear
 * 포화 조건        : front % MAX_SIZE = (rear + 1) % MAX_SIZE
 * enqueue(q,item)  :   1. is_full 검사
 *                      2. rear += 1
 *                      3. q의 (rear)번째 자리에 item 삽입
 * dequeue(q)       :   1. is_empty 검사
 *                      2. q의 (front)번째 자리의 요소 반환
 *                      3. front += 1
 *
 * 특이사항         :   원형 배열은 완전 상상으로 정한거다. 실제로는 배열은
 * 마지막이 있다. 따라서 나머지 연산 (%)을 자주 이용한다. */

typedef char element;
/* create queue */
typedef struct {
  element queue[MAX_SIZE];
  int front, rear;
} CircularQueue;

// create
CircularQueue *createQueue() {
  CircularQueue *Q = (CircularQueue *)malloc(sizeof(CircularQueue));
  Q->front = -1;
  Q->rear = -1;
  return Q;
}

bool isEmpty(CircularQueue *Q) { return (Q->front == Q->rear); }

bool isFull(CircularQueue *Q) { return (Q->front == (Q->rear + 1) % MAX_SIZE); }

// enqueue
void enqueue(CircularQueue *Q, element item) {
  if (isFull(Q)) {
    printf("full!");
    exit(1);
  } else {
    // circular
    Q->queue[(++Q->rear) % MAX_SIZE] = item;
  }
}

// dequeue
void dequeue(CircularQueue *Q) {
  if (isEmpty(Q)) {
    printf("empty !");
    exit(1);
  } else {
    element result = Q->queue[(++Q->front) % MAX_SIZE];
    printf("\n --> %c \n", result);
  }
}

void printQueue(CircularQueue *Q) {
  int first = (Q->front + 1) % MAX_SIZE;
  int last = (Q->rear + 1) % MAX_SIZE;

  printf("\n first =%i last =%i ", first, last);
  printf("\n CircularQueue [ ");
  // for : 첫번째부터 마지막까지
  if (first < last) {
    for (int i = first; i < last; i = (i + 1) % MAX_SIZE) {
      printf("%c ", Q->queue[i]);
    }
  } else {
    // 더 세련되게는 못하려나..
    for (int i = first; i < MAX_SIZE; i++) {
      printf("%c ", Q->queue[i]);
    }
    for (int i = 0; i < last; i++) {
      printf("%c ", Q->queue[i]);
    }
  }

  printf("] \n");
}

int main() {

  CircularQueue *myQ = createQueue();
  enqueue(myQ, 'A');
  printQueue(myQ);
  enqueue(myQ, 'B');
  printQueue(myQ);
  enqueue(myQ, 'C');
  printQueue(myQ);

  dequeue(myQ);
  printQueue(myQ);

  dequeue(myQ);
  printQueue(myQ);
  dequeue(myQ);
  printQueue(myQ);

  // ? 제대로 작동은 하는데 printQueue에서 어떻게 실행해야 보일까.

  enqueue(myQ, 'D');
  printQueue(myQ);
  enqueue(myQ, 'E');
  printQueue(myQ);
  enqueue(myQ, 'F');
  printQueue(myQ);
}
