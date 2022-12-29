/*
 * ADT
 * 원형 큐로 deque를 구현하려면, 반대 방향의 회전 필요
 * front, rear을 감소시켜야 함.
 * index가 음수가 되면 MAX_SIZE를 더해줘야 한다.
 * 
 * 연산
 * is_empty(*q)
 * add_front(*q,item)   :   맨앞에 삽입
 * add_rear(*q, item)   :   맨뒤에 삽입
 * delete_front(*q)     :   맨앞 삭제
 * delete_rear(*q)      :   맨뒤 삭제
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Deque;

int isEmpty(Deque *q){
    return (q->front == q->rear);
}
int isFull(Deque *q){
    return ((q->rear+1) % MAX_SIZE == q->front);
}

void printDeque(Deque *q){
    printf("[ ");

    int i = q->front;
    do {
        i = (i+1 ) % MAX_SIZE;
        printf("%i ", q->data[i]);
        if (i == q->rear) break;
    } while (i != q->front);

    printf("]\n");
}

void add_rear(Deque *q, int item){
    if (isFull(q))
        return;
    // rear++
    q->rear= (q->rear+1)%MAX_SIZE;
    q->data[q->rear]  = item;
    }
void add_front(Deque *q, int item ){
    if (isFull(q)) return;

    q->data[q->front] = item;
    q->front = (q->front -1 + MAX_SIZE) % MAX_SIZE;
}
int delete_front(Deque *q){
    if (isEmpty(q)){
        printf("empty!\n");
        exit(1);
    }
    q->front = (q->front  +1 ) % MAX_SIZE; 
    return q->data[q->front];
}
int delete_rear(Deque *q){
    int item = q->data[q->rear];
    if (isEmpty(q)){

    printf("empty! \n");
    exit(1);
  }
    q->rear = (q->rear-1+ MAX_SIZE) % MAX_SIZE;
    return item;
}

int main(){
    Deque *myDeq =(Deque *) malloc(sizeof(Deque)); 
    myDeq->front= 0;
    myDeq->rear=0;

    int input; 
    scanf("%i", &input);


    for (int i=1; i<input; i++){
        add_rear(myDeq, i);
    }
        printDeque(myDeq);

    for (int i=1; i<input; i++){
        add_front(myDeq, i);
    }
        printDeque(myDeq);

    while (input --){
        delete_rear(myDeq);
        delete_front(myDeq);
    }
    printDeque(myDeq);
    
}
