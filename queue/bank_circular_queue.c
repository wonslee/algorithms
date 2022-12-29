#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 20
/* 은행 서비스 ADT
 *
 * 고객들은 서비스를 받기 위해 대기 행렬 (큐)에서 기다리고,
 * 앞의 고객부터 순서대로 서비스를 받는다. 
 * 고객은 랜덤한 간격으로 대기행렬에 들어오고
 * 서비스 시간도 한계값 안에서 랜덤하게 결정된다.
 *
 * 구하려는 아웃풋 : 고객들이 기다리는 평균시간
 *
 * 1. 현재 시각을 나타낼 변수 clock 선언, 하나 증가
 * 2. 현재 처리중인 고객의 서비스 시간을 저장해둘 변수 service_time 선언
 * 3. 0~10 사이의 난수 생성, 3보다 작으면 새로운 고객 삽입
 * 새로운 고객은 구조체로 구현. 고객이 필요로 하는 서비스 시간을 난수로 생성.
 * 기타 정보들도 구조체에 넣는다.
 * 4. 분기 : service_time이 0일 경우, 큐에서 고객 구조체를 꺼내어 서비스 시작
 * 아닐 경우, 고객이 지금 서비스를 받고 있는 중이므로 가만 냅두기
 * 5. 60분의 시간이 지나면 고객들이 기다린 시간의 평균을 출력한다. 
 */

typedef struct  {
    char name;
    int arrivalTime;
    int neededTime;
} element;

typedef struct {
    element data[MAX_SIZE];
    int front, rear;
}BankQueue;

// create
BankQueue *createQueue() {
  BankQueue *Q = (BankQueue *)malloc(sizeof(BankQueue));
  Q->front = -1;
  Q->rear = -1;
  return Q;
}

bool isEmpty(BankQueue *Q) { return (Q->front == Q->rear); }

bool isFull(BankQueue *Q) { return (Q->front == (Q->rear + 1) % MAX_SIZE); }

// enqueue
void enqueue(BankQueue *Q, element item) {
  if (isFull(Q)) {
    printf("full!");
    exit(1);
  } else {
    // circular
    Q->data[(++Q->rear) % MAX_SIZE] = item;
  }
}

// dequeue
element dequeue(BankQueue *Q) {
  if (isEmpty(Q)) {
    printf("empty !");
    exit(1);
  } else {
    element result = Q->data[(++Q->front) % MAX_SIZE];
  }
  return Q->data[Q->front];
}

void printQueue(BankQueue *Q) {
  int first = (Q->front + 1) % MAX_SIZE;
  int last = (Q->rear + 1) % MAX_SIZE;

  /* printf("\n first =%i last =%i ", first, last); */
  printf("\n\t Queue  [ ");
  // for : 첫번째부터 마지막까지
  if (first < last) {
    for (int i = first; i < last; i = (i + 1) % MAX_SIZE) {
      printf("%c ", Q->data[i].name);
    }
  } else {
    // 더 세련되게는 못하려나..
    for (int i = first; i < MAX_SIZE; i++) {
      printf("%c ", Q->data[i].name);
    }
    for (int i = 0; i < last; i++) {
      printf("%c ", Q->data[i].name);
    }
  }

  printf("] \n");
}

int main(){
    int minutes=60;
    int totalWait=0;
    int totalCustomers=0;
    
    int service_time=0;
    char service_customer;
    char count='A';

    // queue 생성
    BankQueue *BQ = createQueue();
    // 난수
    srand(time(NULL));

    // 반복 : 0~60분동안 1분마다 실행
    for (int clock=0;clock < minutes; clock++){
        printf("%i분 ", clock);
        service_time ? printf("\t 남은 업무처리 시간=%i (%c 진행중) \n", service_time, service_customer) : 1;
         if (rand()%10 < 3){
        // initialize new customer
        element customer;
        customer.name= count++;
        totalCustomers ++;
        customer.arrivalTime=clock;
        customer.neededTime=rand()%6 +1;
        // enqueue
        enqueue(BQ, customer);
        printf("\t %c 대기행렬 삽입. 필요 업무시간= %i분", customer.name,  customer.neededTime);
        printQueue(BQ);
    }
    if (service_time >0)
        service_time--;
    else{
        // 대기행렬에 고객이 남아있어서 기다려야 하는경우
        if (!isEmpty(BQ)){
            // 큐에서 새로운 고객 빼내서, 업무처리 시킴
            element customer = dequeue(BQ);
            service_customer=customer.name;
            service_time=customer.neededTime;

            totalWait += clock - customer.arrivalTime;
            printf("\t --- %c 대기행렬 탈출. 대기시간 = %i분 --- 총 대기시간 = %i분 --- \n", customer.name, clock - customer.arrivalTime, totalWait);
        }
    }
    printf("\n");
    }

    printf("총 대기행렬 인원 = %i명 \n", totalCustomers);
    printf("평균 대기시간 = %i분 \n", totalWait / totalCustomers);
}

