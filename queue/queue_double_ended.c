#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* double ended queue (deque) ADT
 *
 * 개념
 * front와 rear에서 모두 삽입과 삭제가 가능한 queue
 * stack, queue의 연산을 모두 갖고 있다. (push, pop, enqueue, dequeue)
 * double linked list를 사용. 양쪽으로 link를 갖고 있어야 하기 때문.
 * 생성                 :   node, double linked list node 구조. queue(struct of
 front, rear pointer)생성.
 * 공백 상태            :   front = rear = NULL
 * 노드 하나인 상태     :   front = rear = &유일한노드. llink = rlink = NULL
 *
 * 연산
 * is_empty(*q)
 * add_front(*q,item)   :   맨앞에 삽입
 * add_rear(*q, item)   :   맨뒤에 삽입
 * delete_front(*q)     :   맨앞 삭제
 * delete_rear(*q)      :   맨뒤 삭제 */

// 생성
typedef char element;
typedef struct DoubleLinkedListNode {
  element data;
  struct DoubleLinkedListNode *llink;
  struct DoubleLinkedListNode *rlink;
} DListNode;

typedef struct {
  DListNode *front, *rear;
} Deque;

DListNode *createNode(DListNode *llink, element item, DListNode *rlink) {
  DListNode *node = (DListNode *)malloc(sizeof(DListNode));
  node->llink = llink;
  node->rlink = rlink;
  node->data = item;
  return node;
}

Deque *createQueue() {
  Deque *queue = (Deque *)malloc(sizeof(Deque));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

// isEmpty
// 특이사항 : rear은 검사하지 않음.
bool isEmpty(Deque *DQ) { return (DQ->front == NULL); }

/* add_front(*q,item)   :   1. new_node 생성. llink=NULL rlink=q->front
 *                          2. 공백검사
 *                          공백일 경우, q->rear=new_node   -->
 *                          일반적인 경우, q->front->llink=new_node
 *                          3. q->front=new_node */
void addFront(Deque *DQ, element item) {
  DListNode *newNode = createNode(NULL, item, DQ->front);
  // DQ->front 순서 중요
  if (isEmpty(DQ))
    DQ->rear = newNode;
  else
    DQ->front->llink = newNode;
  DQ->front = newNode;
}

/* add_rear(*q, item)   :   맨뒤에 삽입
 *                          1. new_node 생성. llink=q->rear rlink=NULL
 *                          2. 공백검사
 *                          공백일 경우, q->front=new_node
 *                          일반적인 경우, q->rear->rlink=new_node
 *                          3. q->rear=new_node */
void addRear(Deque *DQ, element item) {
  DListNode *newNode = createNode(DQ->rear, item, NULL);
  if (isEmpty(DQ))
    DQ->front = newNode;
  else
    DQ->rear->rlink = newNode;
  DQ->rear = newNode;
}

/* delete_front(*q)     :   1. 공백검사. 공백일 경우 중단
 *                          2. removed_node=q->front 생성. (메모리 해제 목적)
 *                          3. front pointer 옮기기. q->front=q->front->rlink
 *                          4. 후의 front 공백검사.
 *                          front==NULL인 경우, q->rear=NULL  --> 공백상태 됨
 *                          일반적인 경우, q->front->llink=NULL
 *                          5. free(removed_node) */
element deleteFront(Deque *DQ) {
  DListNode *removed_node = (DListNode *)malloc(sizeof(DListNode));
  removed_node = DQ->front;
  element removed_data = DQ->front->data;

  DQ->front = DQ->front->rlink;
  if (isEmpty(DQ))
    DQ->rear = NULL;
  else
    DQ->front->llink = NULL;
  free(removed_node);

  return removed_data;
}

/* delete_rear(*q)      :   1. 공백검사. 공백일 경우 중단
 *                          2. removed_node=q->rear 생성.
 *                          3. rear pointer 옮기기. q->rear=q->rear->llink
 *                          4. 후의 공백검사.
 *                          rear==NULL인 경우, q->front=NULL  -->
 * 공백상태(head=tail=NULL) 됨 일반적인 경우, q->rear->rlink=NULL
 *                          5. free(removed_node) */
element deleteRear(Deque *DQ) {
  DListNode *removed_node = (DListNode *)malloc(sizeof(DListNode));
  removed_node = DQ->rear;
  element removed_data = DQ->rear->data;

  DQ->rear = DQ->rear->llink;
  if (isEmpty(DQ))
    DQ->front = NULL;
  else
    DQ->rear->rlink = NULL;
  free(removed_node);
  return removed_data;
}

void printQueue(Deque *DQ) {
  printf("\nfront");
  for (DListNode *p = DQ->front; p != NULL; p = p->rlink) {
    printf(" --- [ %p | %c | %p ]", p->llink, p->data, p->rlink);
    if (p == DQ->rear)
      printf(" --- rear\n");
  }
}

int main() {
  Deque *myQ = createQueue();

  addFront(myQ, 'A');
  printQueue(myQ);
  addFront(myQ, 'B');
  printQueue(myQ);

  deleteFront(myQ);
  printQueue(myQ);
  addFront(myQ, 'C');
  printQueue(myQ);

  addRear(myQ, 'D');
  printQueue(myQ);
  addRear(myQ, 'E');
  printQueue(myQ);
  addRear(myQ, 'F');
  printQueue(myQ);

  deleteFront(myQ);
  printQueue(myQ);
  deleteFront(myQ);
  printQueue(myQ);
  deleteFront(myQ);
  printQueue(myQ);
}
