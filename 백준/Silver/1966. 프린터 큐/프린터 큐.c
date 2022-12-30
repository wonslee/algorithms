#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// definition
typedef struct {
  int value;
  bool isTarget;
} element;

element queue[10000];
int front, rear;

void init() {
  front = -1;
  rear = -1;
}
bool isEmpty() { return (front == rear); }

void enqueue(element item) { queue[++rear] = item; }
element dequeue() { return queue[++front]; }
// isThere() : 탐색
bool isThere() {
  for (int i = front; i <= rear; i++)
    if (queue[i].value > queue[front].value)
      return true;

  return false;
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
      element e = {input, i==target};
      enqueue(e);
    }

    while (!isEmpty() ) {
      // 일단 삭제
      element d = dequeue();
      // 더 큰 값이 있다면, enqueue
      if (isThere())
        enqueue(d);
      // 더 큰 값이 없다면 count 1 증가. target이라면 count 출력.
      else {
          count ++;
        if (d.isTarget) {
        printf("%i\n", count);
        break;
      }

      } 
    }
  }
}