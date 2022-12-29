/* https://www.geeksforgeeks.org/priority-queue-using-linked-list/
 *
 * 링크드 리스트로 구현한 우선순위 큐
 *
 * 배열로 구현한 것과 거의 같음
 * 두가지 경우로 나뉨.
 * 여기선 삭제시에 탐색하는 버전을 사용
 *
 * 숫자가 낮을수록 높은 우선순위.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// queue struct
typedef struct PriorityQueueNode {
  int priority;
  int value;
  struct PriorityQueueNode *link;
} PQNode;

typedef struct {
  PQNode *front, *rear;
} LinkedListQueue;

// createNode
PQNode *createNode(int priority, int value) {
  PQNode *node = (PQNode *)malloc(sizeof(PQNode));
  node->priority = priority;
  node->value = value;
  node->link = NULL;
  return node;
}

/* enqueue : 첫번째 노드로 삽입. head pointer 이용 */
void enqueue(PQNode **head, int priority, int value) {
  PQNode *newNode = createNode(priority, value);
  PQNode *start = *head;

  // the head has lessor priority than new node. So insert new
  // node before head node and change head node.
  if ((*head)->priority > priority) {
    newNode->link = *head;
    *head = newNode;
  } else {
    // 인자 priority보다 큰 노드들의 마지막까지 반복
    while (start->link != NULL && start->link->priority < priority) {
      start = start->link;
    }
    // new node를 두 노드사이에 삽입
    newNode->link = start->link;
    start->link = newNode;
  }
}

// dequeue
int dequeue(PQNode **head) {
  int result = (*head)->value;
  PQNode *temp = *head;
  *head = (*head)->link;
  return result;
}

bool isEmpty(PQNode **head) { return (*head) == NULL; }

int main() {
  PQNode *myPQ = createNode(8, 100);
  enqueue(&myPQ, 5, 200);
  enqueue(&myPQ, 3, 300);
  enqueue(&myPQ, 1, 0);

  while (!isEmpty(&myPQ)) {
    printf("[ %i | %i ]  ", myPQ->priority, myPQ->value);
    dequeue(&myPQ);
  }
  return 0;
}
