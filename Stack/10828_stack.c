/* 문제
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을
작성하시오.

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는
정수가 없는 경우에는 -1을 출력한다. size: 스택에 들어있는 정수의 개수를
출력한다. empty: 스택이 비어있으면 1, 아니면 0을 출력한다. top: 스택의 가장 위에
있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의
줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다
작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.


문제접근
ADT : stack은 LIFO. 나중에 삽입된게 가장 먼저 삭제된다.
array로도 가능하지만, linked_list로 구현해보자.

data:
우선 node(struct). data와 link 필드를 갖는다.
stack(struct). node를 가리키는 top pointer이 있다. (bottom도 필요한가?)

입력 명령을 잘 수행할 수 있도록 연산 함수를 짜자.
명령들을 분기처리할 수 있도록 switch case를 쓰자.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10000

int stack[MAX_STACK_SIZE]; // stack array
int top = 0;               // top 변수

void push(int num) {
  stack[top] = num;
  top++;
}

void pop() {
  if (top != 0) {
    top--;
    printf("%d\n", stack[top]);
    stack[top] = 0;
  }
  //만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다
  else
    printf("%d\n", -1);
}
// peek: 스택의 가장 위에 있는 정수를 출력
void peek() {
  if (top != 0)
    printf("%d\n", stack[top - 1]);
  //스택에 들어있는 정수가 없는 경우에는 - 1
  else
    printf("%d\n", -1);
}
// size: 스택에 들어있는 정수의 개수를 출력
void size() { printf("%d\n", top); }
void empty() {
    printf("%i\n", (top ==0) ?1 : 0 );
}

int main() {
  int n;
  char command[5]; // 입력 문자 넣을 string
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s", command);
    // strcmp로 비교
    if (strcmp(command, "top") == 0)
      peek();
    else if (strcmp(command, "empty") == 0)
      empty();
    else if (strcmp(command, "size") == 0)
      size();
    else if (strcmp(command, "pop") == 0)
      pop();
    else if (strcmp(command, "push") == 0) {
      int num; // 숫자는 따로 입력받음.
      scanf("%i", &num);
      push(num);
    }
  }
  return 0;
}
