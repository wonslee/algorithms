/*
 * 원형큐 버전
 * 참고 https://blog.naver.com/kim-nan-hee/221901814483
 * */
#include <stdio.h>
#define SIZE 500000

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int item) {
  rear = (rear + 1) % SIZE;
  queue[rear] = item;
}
int dequeue_twice() {
  front = (front + 2) % SIZE;
  return queue[front];
}

int main() {
  int n;
  scanf("%i", &n);

  for (int i = 1; i <= n; i++) enqueue(i);

  while (rear-front!=1) enqueue(dequeue_twice());
  
  printf("%i", queue[rear]);
}
