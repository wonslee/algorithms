#include <stdio.h>

int queue[100000];
int front = -1;
int rear = -1;

int main() {
  int n;
  scanf("%i", &n);

  while (1) {
    int input;
    scanf("%i", &input);
    
    // 0일 경우 dequeue. 문제조건중에 비어있을 땐 0이 입력으로 들어오지 않으므로
    // 공백상태 검사는 생략.
    if (input == 0) ++front;
    
    // -1일 경우 모든 원소 출력. 비어있을 경우 empty 출력
    else if (input == -1) {
      if (front == rear)
        printf("empty");
      else
        for (int i = front + 1; i < rear + 1; i++)
          printf("%i ", queue[i]);

      return 0;
    }
    
    // 양의 정수이고 '버퍼'가 포화 상태가 아닐 경우, enqueue.
    else if (!(rear-front == n ))
      queue[++rear] = input;
  }
}