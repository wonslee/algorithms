/*
 * # 문제접근
 * 말 그대로 큐 ADT에 대한 구현을 묻는 문제. 배열로 구현했다.
 * data: int를 담을 배열, front와 back을 가리킬 index값.
 * 초기 조건: front = back = -1
 * 공백 조건: front = back
 * 포화 조건: back = 마지막 index
 * enqueue: is_full 검사 (여기선 필요 없다)
 *          ++back
 *          queue[back]에 값 삽입
 * dequeue: is_empty 검사
 *          front번째 원소 출력
 *          front ++
 * size: back - front 
 * 특이사항: 안정적인 큐를 구현하려면, 포화상태를 막기 위해
 * pop이 될 때마다 주기적으로 front, rear을 감소시키고 원소들을 이동시켜야 한다.
 * 여기선 구현 안 했음.
 * */
#include <stdio.h>
#include <string.h>

#define MAX 2000000

// initialize
int queue[MAX];
int front = -1, back = -1;

// is_empty: 비어있으면 1, 아니면 0 반환
int is_empty() { return (front == back); }
int is_full() { return (back == MAX - 1); }
// size: queue->size출력
void print_size() { printf("%d\n", back -front ); }

// push(enqueue): 정수 value를 queue에 삽입
void enqueue(int value) {
  queue[++back] = value;
}
// pop(dequeue): front를 증가시키고 원래의 맨 앞 값을 출력.
void dequeue() {
  if (is_empty())
    printf("%d\n", -1);
  else
    printf("%d\n", queue[++front]);
}

// front: 맨 앞의 정수를 출력
void print_front() {
  if (is_empty())
    printf("%d\n", -1);
  else
    printf("%d\n", queue[front+1]);
}
// back: 가장 뒤의 정수를 출력
void print_back() {
  if (is_empty())
    printf("%d\n", -1);
  else
    printf("%d\n", queue[back]);
}

int main() {
  long long n;
  scanf("%lld", &n);
  char command[6]; // 입력 문자 넣을 string

  while (n--) {
    scanf("%s", command);
    // strcmp로 비교
    if (strcmp(command, "front") == 0)
      print_front();
    else if (strcmp(command, "back") == 0)
      print_back();
    else if (strcmp(command, "empty") == 0)
      printf("%d\n", is_empty());
    else if (strcmp(command, "size") == 0)
      print_size();
    else if (strcmp(command, "pop") == 0)
      dequeue();
    else if (strcmp(command, "push") == 0) {
      int num;
      scanf("%d", &num);
      enqueue(num);
    }
  }
  return 0;
}