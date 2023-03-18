/* https://www.geeksforgeeks.org/priority-queue-using-array-in-c/
 *
 * 배열로 구현한 우선순위 큐
 * 두가지가 있다.
 * 첫번째, 정렬이 되어있지 않고 삭제시에 우선순위가 높은 요소를 찾는 방법
 * 두번째, 삽입때마다 정렬을 하고 삭제시엔 맨 앞의 요소를 꺼내는 방법
 * 결국 탐색 과정은 꼭 필요하다
 *
 * peek 함수가 가장 구현이 까다로움. (조건문만 잘 짜주면 끝)
 * */

#include <limits.h>
#include <stdio.h>

typedef struct {
  int priority;
  int value;
} Element;

int size = -1;
Element queue[10000];

// enqueue: This function is used to insert new data into the queue.
void enqueue(int priority, int value) {
  size++;
  queue[size].priority = priority;
  queue[size].value = value;
}
// peek : check for the element with highed priority
int peek() {
  int highest = INT_MIN;
  // index of the peek element
  int top = -1;

  // loop for whole queue
  for (int i = 0; i <= size; i++) {
    // 일반적인 경우 : 해당 index 원소의 priority가 가장 높을 때, highest
    // 재할당.
    if (highest < queue[i].priority) {
      highest = queue[i].priority;
      top = i;
      // priority가 같다면 그 다음으로 value를 기준으로.
    } else if (highest == queue[i].priority && top > -1 &&
               queue[top].value < queue[i].value) {
      highest = queue[i].priority;
      top = i;
    }
  }
  return top;
}

// dequeue : removes the element with the highest priority from the queue.
Element dequeue() {
  int top = peek();
  Element temp = queue[top];
  // Shift the element one index before from the position of the element
  for (int i = top; i < size; i++)
    queue[i] = queue[i + 1];

  size--;
  return temp;
}

int main() {
  // Function Call to insert elements
  enqueue(10, 2);
  enqueue(14, 4);
  enqueue(16, 4);
  enqueue(12, 3);
  enqueue(12, 4);
  enqueue(12, 5);

  // Stores the top element at the moment
  int ind = peek();
  printf("{ priority:%i | value:%i }\n", queue[ind].priority, queue[ind].value);

  // Dequeue the top element
  dequeue();
  ind = peek();
  printf("{ priority:%i | value:%i }\n", queue[ind].priority, queue[ind].value);

  dequeue();
  ind = peek();
  printf("{ priority:%i | value:%i }\n", queue[ind].priority, queue[ind].value);

  dequeue();
  ind = peek();
  printf("{ priority:%i | value:%i }\n", queue[ind].priority, queue[ind].value);

  dequeue();
  ind = peek();
  printf("{ priority:%i | value:%i }\n", queue[ind].priority, queue[ind].value);

  return 0;
}
