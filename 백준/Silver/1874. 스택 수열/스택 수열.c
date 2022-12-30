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

  // push, pop된 최대 횟수는 n의 2배이다.
  while (1) {
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
            if (result_idx == n * 2) break;

  }

  for (int i = 0; i < result_idx; i++)
    printf("%c\n", result[i]);
  return 0;
}