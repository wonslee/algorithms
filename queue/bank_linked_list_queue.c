#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 은행 서비스
 *
 * 고객들은 서비스를 받기 위해 대기 행렬 (큐)에서 기다리고,
 * 앞의 고객부터 순서대로 서비스를 받는다.
 * 고객은 랜덤한 간격으로 대기행렬에 들어오고
 * 서비스 시간도 한계값 안에서 랜덤하게 결정.
 *
 * 구하려는 아웃풋 : 고객들이 기다리는 평균시간
 *
 * 1. 상태 변수 :
 *      현재 시각을 나타낼 변수 clock. 1분씩 반복 증가
 *      현재 처리중인 고객의 서비스 시간 serviceTime
 *      현재 처리중인 고객 이름 serviceCustomer
 *      총 대기시간 totalWait
 *      총 대기행렬 고객 수 totalCustomers
 * 2. 고객 생성 :
 *      0~10 사이의 난수 생성, 3보다 작으면 (33%) 새로운 고객 삽입
 *      새로운 고객은 구조체로 구현. 고객이 필요로 하는 서비스 시간을 랜덤 생성.
 *      도착시간, 이름 할당.
 * 3. 서비스 진행 :
 *      serviceTime이 0일 경우, 큐에서 고객 구조체를 꺼내어 서비스 시작
 *      0이 아닐 경우, 고객이 지금 서비스를 받고 있는 중이므로 가만 냅두기
 * 4. 60분의 시간이 지나면 고객들이 기다린 시간의 평균을 출력
 */

// 타입 선언
typedef struct {
  char name;
  int arrivalTime;
  int neededTime;
} element;

typedef struct QueueNode {
  element data;
  struct QueueNode *link;
} QNode;

typedef struct {
  QNode *front, *rear;
} LinkedListQueue;

// 생성
LinkedListQueue *createQueue() {
  LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

// 공백 검사
bool isEmpty(LinkedListQueue *LQ) { return (LQ->front == NULL); }

// 삽입
void enqueue(LinkedListQueue *LQ, element item) {
    // 노드 동적 할당
  QNode *newNode = (QNode *)malloc(sizeof(QNode));
  newNode->data = item;
  newNode->link = NULL;
  // 조건 : 공백일 경우와 아닌 경우
  if (isEmpty(LQ)) {
    LQ->front = newNode;
    LQ->rear = newNode;
  } else {
    LQ->rear->link = newNode;
    LQ->rear = newNode;
  }
}

// 삭제
element dequeue(LinkedListQueue *LQ) {
  // 해제용 pointer 생성
  QNode *oldNode = LQ->front;

  // 조건 : 공백일 경우와 아닐 경우
  if (isEmpty(LQ)) {
    printf("empty!");
    exit(1);
  }
  element item = LQ->front->data;

  // front가 뒷 노드를 가리키도록
  LQ->front = LQ->front->link;
  // 큐가 공백이 된 경우 rear=NULL  --> front=rear=NULL (공백상태)
  if (LQ->front == NULL)
    LQ->rear = NULL;

  free(oldNode);
  return item;
}

// 출력
void printQueue(LinkedListQueue *LQ) {
  for (QNode *p = LQ->front; p != NULL; p = p->link)
    printf("\t [ %c | %i분에 도착 | %i분 필요 | %p ]\n", p->data.name,
          p->data.arrivalTime,  p->data.neededTime, p->link);
}

int main() {
  // 상태 변수들 선언
  int minutes = 60;
  int totalWait = 0;
  int totalCustomers = 0;

  int serviceTime = 0;
  char serviceCustomer;
  char alphabet = 'A';

  // 큐 선언
  LinkedListQueue *BQ = createQueue();
  // 난수 초기화
  srand(time(NULL));

  // 반복 : 0~60분동안 1분마다 실행
  for (int clock = 0; clock < minutes; clock++) {
    printf("%i분 ", clock);

    if (serviceTime)
      printf("\t 남은 업무처리 시간 = %i분 (%c 진행중) \n", serviceTime,
             serviceCustomer);

    // 33% 확률로 고객 태어남
    if (rand() % 10 < 3) {
      // 고객 정의
      element customer;
      customer.name = alphabet++;
      customer.arrivalTime = clock;
      customer.neededTime = rand() % 3 + 1;
      // 총 대기인원 +1
      totalCustomers++;
      // 삽입
      enqueue(BQ, customer);

      printQueue(BQ);
    }

    // 업무진행중일 경우, 업무시간 -1
    if (serviceTime > 0)
      serviceTime--;

    // 업무진행중이지 않고 대기행렬이 비어있지 않은 경우, 대기행렬에서 한명 탈출
    else {
      if (!isEmpty(BQ)) {
        // 큐에서 새로운 고객 빼내서 업무중인 고객에다 할당
        element customer = dequeue(BQ);
        serviceCustomer = customer.name;
        serviceTime = customer.neededTime;

        // 총 대기시간 += 현재 고객이 기다린 시간
        totalWait += clock - customer.arrivalTime;
        printf("\n\t --- %c 대기행렬 탈출. 대기시간 = %i분 --- 총 대기시간 = "
               "%i분 --- \n",
               customer.name, clock - customer.arrivalTime, totalWait);
      }
    }
    printf("\n");
  }

  printf("총 대기행렬 인원 = %i명 \n", totalCustomers);
  printf("평균 대기시간 = %i분 \n", totalWait / totalCustomers);
}
