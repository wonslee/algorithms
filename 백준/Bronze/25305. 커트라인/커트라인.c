#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, k, input;
  scanf("%i %i", &n, &k);

  int *score = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++)
    score[i] = -1;

  for (int i = 0; i < n; i++) {
    scanf("%i", &input);
    // j는 두 파트의 경계선. 가능한한 0번째 index까지 내려가면서 삽입할 자리
    // 찾기.
    int j = i - 1;
    for (; input < score[j] && j >= 0; j--)
      score[j + 1] = score[j]; // 큰 값은 오른쪽으로 이동

    score[j + 1] = input;
  }
  printf("%i", score[n - k]);
}