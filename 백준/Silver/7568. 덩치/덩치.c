#include <stdio.h>

typedef struct {
  int x, y, rank;
} Person;

int main() {
  int N;
  Person arr[50];
  scanf("%d", &N);

  // 배열에 입력값(사람과 덩치) 저장
  for (int i = 0; i < N; i++) {

    int x, y, rank = 1;
    scanf("%i %i", &arr[i].x, &arr[i].y);
    arr[i].rank = 1;
  }

  // N만큼 반복. 원소들끼리 덩치 비교
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // x가 작고 y도 작을 때 랭크 +1
      if (arr[i].x < arr[j].x && arr[i].y < arr[j].y)
        arr[i].rank++;
    }
    printf("%i ", arr[i].rank);
  }
}