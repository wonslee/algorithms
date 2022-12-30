#include <stdio.h>

int main() {
  int N, array[100], V, count = 0;

  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d ", &array[i]);
  scanf("%d", &V);

  for (int i = 0; i < N; i++) {
    if (array[i] == V)
      count++;
  }
  printf("%d", count);

  return 0;
}