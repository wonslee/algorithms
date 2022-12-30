/*
문제접근
첫번째. 평균을 구하는 로직은 결국 점수들의 합 / 과목의 개수.
원래의 시험과 달라지는건 조작 부분이다.
원래의 점수는 저장되어있어야 maximum값을 구할 수 있다.
이 문제는 최댓값, 원래 점수들의 배열, 과목의 개수가 중요한 데이터다.
수정.
'/'연산과 int에 대해 간과. float으로 했어야 했음. 문제의 요구조건이 float이기도
했고. 반복문 안에선 평균값을 구하기보단 total을 구하는게 가독성이 더 좋다. 굳이
input이라는 변수는 필요없다. 그냥 arr[i]에 바로 scanf 할당하면 된다. (%lf)

data.
과목의 개수 int N
과목들의 성적을 저장할 배열 float arr[N]
maximum값을 저장할 int maximum.

logic.
1. scanf : N
2. for (N) : scanf -> 각 성적을 배열에 저장, maximum값을 갱신
3. for (N) : 조작하는 연산 -> total += arr[i] / maximum * 100
4. 그 평균값(total / N )을 printf
*/

#include <stdio.h>

int main() {
  int N, maximum = -1;
  scanf("%i", &N);
  int arr[N];
  // 소수점 아래로 계산되어야 하므로 float 혹은 double
  double total = 0;

  // 성적을 배열에 저장. 그리고 최댓값 저장
  for (int i = 0; i < N; i++) {
    scanf("%i", &arr[i]);
    if (arr[i] > maximum)
      maximum = arr[i];
  }
  // 성적 조작 부분
  for (int i = 0; i < N; i++)
    total += (double)arr[i] / maximum * 100;

  printf("%.14f", total / N);
}
