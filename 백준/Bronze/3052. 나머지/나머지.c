/*
 * 문제
두 자연수 A와 B가 있을 때, A%B는 A를 B로 나눈 나머지 이다. 예를 들어, 7, 14, 27,
38을 3으로 나눈 나머지는 1, 2, 0, 2이다.

수 10개를 입력받은 뒤, 이를 42로 나눈 나머지를 구한다. 그 다음 서로 다른 값이 몇
개 있는지 출력하는 프로그램을 작성하시오.

입력
첫째 줄부터 열번째 줄 까지 숫자가 한 줄에 하나씩 주어진다. 이 숫자는 1,000보다
작거나 같고, 음이 아닌 정수이다.

출력
첫째 줄에, 42로 나누었을 때, 서로 다른 나머지가 몇 개 있는지 출력한다.

문제접근

1번째 : 나머지값들을 담을 배열을 정의,
10번 반복하는 반복문 안에서 입력받은 값 % 42를 input에 할당
input을 배열의 모든 값들과 비교해서, 기존에 없다면 count ++, 배열에 삽입
그 후, 배열의 원소 갯수를 출력

data
길이 10의 int 배열, input, 서로 다른 나머지를 담을 배열

logic
1. 데이터 정의. array, input, isSame, count
2. LENGTH만큼 반복: input값을 입력받고,
    2-1. 반복중인 i만큼 반복:
        배열의 원소들 중 하나라도 입력값과 같다면 isSame ++
    2-2. isSame == 0이라면 같은게 없으므로 배열에 삽입. count ++
3. count 출력

2번째 : 일단 나머지값들을 담은 다음, 다른 원소들과 비교해서
*/
#include <stdio.h>
#define LENGTH 10

int main() {
  int array[LENGTH], input, result= 0, count ;

    // LENGTH만큼 반복 : 입력받고 각 index에 삽입
    for (int i = 0; i < LENGTH; i++) {
            scanf("%d", &input);
        array[i] = input % 42;
    }
      // LENGTH만큼 반복
  for (int i = 0; i < LENGTH; i++) {
      count =0; // initialize
    // 가능한 이전 삽입 갯수(i)만큼 반복
    for (int j = 0; j < i; j++)
      // 원소중 하나라도 중복일 경우 count ++
      if (array[j] == array[i]) count++;

    //  count가 0일 때 result ++
    if (count==0) result++;
    
  }

  printf("%d", result);
}