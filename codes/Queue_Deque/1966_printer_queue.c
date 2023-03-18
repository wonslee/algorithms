/*
 * 현재 Queue의 가장 앞에 있는 문서의 ‘중요도’를 확인한다.
나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서를
인쇄하지 않고 Queue의 가장 뒤에 재배치 한다. 그렇지 않다면 바로 인쇄를 한다.
예를 들어 Queue에 4개의 문서(A B C D)가 있고, 중요도가 2 1 4 3 라면 C를
인쇄하고, 다음으로 D를 인쇄하고 A, B를 인쇄하게 된다.

여러분이 할 일은, 현재 Queue에 있는 문서의 수와 중요도가 주어졌을 때,
어떤 한 문서가 몇 번째로 인쇄되는지 알아내는 것이다.
예를 들어 위의 예에서 C문서는 1번째로, A문서는 3번째로 인쇄되게 된다.

# 문제접근 첫번째
일단 큐. 우선순위 큐로 구현한다면 삽입 메커니즘이 맨 뒤로 넣는걸로 바뀔 것.
원소들의 값은 중복될 수 있기 때문에, 특정 값으로 식별해선 안 된다.
처음 들어왔을 때 target인지를 true로 해두거나, 뒤로 보낼 때마다 M index 를
바꿔야 한다.

원형큐로 구현해보자. 삭제를 너무 많이 한다.

배열을 일단 받아두고, target index를 통해 원소에 표시를 해두는 방법.
그러나 이건 비효율적이라는 생각이 든다.

# 연산
- 원소 생성(value, isTarget)
malloc..
value와 isTarget 할당
- 공백 검사:
return front==rear
- 큐 초기화:
front = rear = -1
- 삽입(item):
queue[++rear] = item
- 맨 뒤로 보내기(arr[]):
front번째 원소를 삭제. item = queue[++front]
삽입(item)

더 큰 값 존재여부 탐색(arr[], size):
index 0 원소보다 큰 값을 찾고, 있는지 여부 boolean값을 반환.

# 로직
1. loop(테스트케이스 수 T):
1-1. 입력: 문서 개수 N, target
1-2. loop(N): 큐에 삽입
1-3. target index의 원소에다 표시.
1-3. loop(!isEmpty()):
1-3-1. 더 큰 값 존재여부 탐색.
있을 경우 맨 뒤로 보낸다.
없을 경우 삭제. 삭제할 때마다 count + 1
1-3-2. 삭제한 원소가 처음에 표시해둔 target일 경우, count 출력. 반복문 break.

# 데이터
struct {
    int value
    bool isTarget
} element
int queue[100]
int front, rear (초기값 -1)
int T, N, target
반복문
int count
element old

# 배운 점
선형 큐는 삭제 및 삽입을 할 때마다 증가하는 pointer(front, rear) 때문에
담을 수 있는 데이터의 한계가 크다.
만약 선형큐로 구현했을 때 N값이 10000을 넘어갔다면 꽤 힘들었을 것.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 101
// definition
typedef struct {
  int value;
  bool isTarget;
} element;

element queue[SIZE];
int front, rear;

void init() {
  front = -1;
  rear = -1;
}
bool isEmpty() { return (front == rear); }

void enqueue(element item) {
  rear = (rear + 1) % SIZE;
  queue[rear] = item;
}
element dequeue() {
  front = (front + 1) % SIZE;
  return queue[front];
}
// isThere() : 탐색
bool isThere() {
  for (int i = (front+1)%SIZE ; i != rear; i = (i + 1) % SIZE)
    if (queue[i].value > queue[front].value)
      return true;

  return false;
}

void printQueue() {
  int first = (front + 1) % SIZE;
  int last = (rear + 1) % SIZE;

  printf("\nfirst =%i last =%i ", first, last);
  printf("\[ ");
  // for : 첫번째부터 마지막까지
  if (first < last) {
    for (int i = first; i < last; i = (i + 1) % SIZE) {
             if (queue[i].isTarget) printf("#");
      printf("%i ", queue[i].value);
    }
  } else {
    // 더 세련되게는 못하려나..
    for (int i = first; i < SIZE; i++) {
     if (queue[i].isTarget) printf("#");
      printf("%i ", queue[i].value);
    }
    for (int i = 0; i < last; i++) {
             if (queue[i].isTarget) printf("#");
      printf("%i ", queue[i].value);
    }
  }
  printf("] \n");
}

int main() {

  int T;
  scanf("%i", &T);

  while (T--) {
    init();
    int N, target, count = 0;
    scanf("%i %i", &N, &target);
    // 초기 큐 생성
    for (int i = 0; i < N; i++) {
      int input;
      scanf("%i", &input);
      element e = {input, i == target};
      enqueue(e);
    }

    while (!isEmpty()) {
      // 일단 삭제
      element d = dequeue();
      // 더 큰 값이 있다면, enqueue
      if (isThere())
        enqueue(d);
      // 더 큰 값이 없다면 count 1 증가. target이라면 count 출력.
      else {
        count++;
        if (d.isTarget) {
          printf("%i\n", count);
          break;
        }
      }
    }
  }
}
