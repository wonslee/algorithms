#include <stdio.h>
int list[5];

int main() {
int average=0;
  for (int i = 0; i < 5; i++) {
    int j, input;
    scanf("%i", &input);
    // 입력값보다 큰 애들은 오른쪽으로 한 칸씩 이동
    for (j = i - 1; j >= 0 && list[j] > input; j--)
      list[j + 1] = list[j];
    // 찾은 index에다 삽입
    list[j + 1] = input;

    average += (input / 5);
  }
  // 출력
  printf("%i\n%i", average, list[2]);
}