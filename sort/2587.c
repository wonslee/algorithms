/*
 * 다섯 개의 자연수가 주어질 때 이들의 평균과 중앙값을 구하는 프로그램을 작성하시오.

입력
첫째 줄부터 다섯 번째 줄까지 한 줄에 하나씩 자연수가 주어진다. 주어지는 자연수는 100 보다 작은 10의 배수이다.

출력
첫째 줄에는 평균을 출력하고, 둘째 줄에는 중앙값을 출력한다. 평균과 중앙값은 모두 자연수이다.


# 문제접근
중앙값을 구하기 위해선 sorting이 필요.
n이 작아서 무슨 방법을 써도 총 걸리는 시간에는 차이가 크지 않을듯.
삽입 정렬을 써볼까?

'정렬되지 않은 왼쪽' 배열과 index가 필요. 
input은 '정렬되지 않은 오른쪽'으로 생각. 
insertion_sort(int arr[], int item):
loop ('왼쪽' 배열의 가장 오른쪽부터 0 index까지 ):
    if item < 원소 : 오른쪽으로 한칸씩. target index는 한칸씩 왼쪽으로
target index에다 item 삽입

1. loop(입력이 끝날 때까지): 정렬 과정
1-1. 입력: input
1-2. insertion_sort(input)
2. 정렬 끝. 배열의 평균과 중앙값 (n / 2 +1) 구하기
3. 출력: 평균, 중앙값

[ 10,  ]
1) 맨 첨엔 첫번째놈을 0번째에 넣고 시작
2) rear = 1 target = 1
input >= arr[target-1] --> target
<                    --> loop: 오른쪽으로 한칸씩 이동. target --
*/
#include <stdio.h>
#define SIZE 5
int list[SIZE];

int main() {
int average=0;
  for (int i = 0; i < SIZE; i++) {
    int j, input;
    scanf("%i", &input);
    // insertion_sort : 입력값보다 큰 애들은 오른쪽으로 한 칸씩 이동
    for (j = i - 1; j >= 0 && list[j] > input; j--)
      list[j + 1] = list[j];
    // 찾은 index에다 삽입
    list[j + 1] = input;

    average += (input / SIZE);
  }
  // 출력
  printf("%i\n%i", average, list[SIZE /2 ]);
}
