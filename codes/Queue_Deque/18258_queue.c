/*
 * 명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는
정수가 없는 경우에는 -1을 출력한다. size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는
경우에는 -1을 출력한다. back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에
들어있는 정수가 없는 경우에는 -1을 출력한다.

입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 2,000,000)이 주어진다. 둘째 줄부터 N개의
줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다
작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

*/
/*
 * # 문제접근
 * 말 그대로 큐 ADT에 대한 구현을 묻는 문제. 탐색 부분은 없었지만.
 * 처음엔 링크드리스트로 구현했다.
 * 개인적으로 링크드리스트를 복습하고 싶어서였고, 배열 방법이 잘 기억이 안
 * 나서였기도 하다.
 *
 * # 틀렸습니다
 * 아마도 입력값 N의 범위 2000000을 int값으로는 맞추지 못해서일것.
 * long long으로 바꿨다.
 *
 * # 시간초과
 * 링크드리스트 버전으로 했을 때 시간초과였다.
 * 백준에 아쉬운 점은, 시간초과 이전에 제출한게 맞았는지 틀렸는지는 알려줬으면
 * 좋겠다는 것. 문제의 요구조건이 너무 딱딱하다는 느낌을 받는다. 그냥
 * 징징대봤다.
 *
 * 그래서 배열로 구현했다.
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
 * size: back - front + 1  곧 원소의 개수.
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
