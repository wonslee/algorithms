/* 스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주
이용되는 개념이다. 스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가
같아 제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을
가지고 있다.

1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수
있다. 이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자.
임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면
어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 이를 계산하는
프로그램을 작성하라.

입력
첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다.
둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로
주어진다. 물론 같은 정수가 두 번 나오는 일은 없다.

출력
입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다.
push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.


# 문제접근
일단 stack ADT를 구현. 문제는 수열이 만들어지는 과정을 표현하는 것.

NO의 조건이 잘 이해가 안 된다.
한번 pop된 숫자는 다시 push될 수 없다는 얘긴가?

- queue가 필요. front, rear index를 야무지게 써야 함.
- 핵심 loop (입력 curr > front) : push(dequeue())

# stack ADT
배열과 top index
isEmpty()
push()
pop()

# 로직
1. 입력: n
1-1. 1 ~ n 배열 생성
2. loop(n):
2-1. 입력: input
top index보다 input이 클 경우, loop(top~input):push
top index보다 input이 작은 경우:
2-2. loop(input)

# 데이터
queue 필요. 1~8의 숫자들이 순서대로 나와야 함.
stack[n]
top index


push, pop이 이뤄진 순서를 기억할 수 있는 배열이 필요.
불가능한지 여부에 따라 배열 원소들을 출력해야 하기 때문.

# 배운 점
- stack의 목표 수 조건.
    1. 목표 수가 stack top보다 큰 경우 push
    2. 목표 수가 stack top과 같은 경우 pop
    3. 목표 수가 stack top보다 낮은 경우, 원하는 수열을 만들 수 없음.

- loop 로직을 세울 때 처음부터 condition이 애매하면, 결과도 맞지 않다. 처음에 생각 똑바로 하라는 소리다.
생각 정립이 안 되어있으면 코드는 치나 마나다.
- 배열 등 데이터의 범위를 주의하자. result의 범위를 MAX_SIZE로 했었다가 틀렸다.

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

/* stack */
int stack[MAX_SIZE];
int top = -1;
// log of push, pop
char result[MAX_SIZE * 2];

int main() {
  int n;
  scanf("%i", &n);
  // 목표 수열 initialize
  int *target = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++)
    scanf("%i", &target[i]);

  // index
  int number = 1, idx = 0, result_idx = 0;

  // loop: result index 끝까지
  while (result_idx != n * 2) {
    // 1. 목표 수가 stack top보다 큰 경우 push
    if (top == -1 || target[idx] > stack[top]) {
      stack[++top] = number++;
      result[result_idx++] = '+';
    }
    // 2. 목표수와 stack top이 같은 경우 pop
    else if (target[idx] == stack[top]) {
      top--;
      result[result_idx++] = '-';
      idx++;
    }
    // 3. 목표수가 stack top보다 낮은 경우, 원하는 수열을 만들 수 없음.
    else {
      printf("NO\n");
      return 0;
    }
  }

  for (int i = 0; i < result_idx; i++)
    printf("%c\n", result[i]);
  return 0;
}
