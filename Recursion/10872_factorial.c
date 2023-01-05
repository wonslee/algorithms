#include <stdio.h>
/* 문제
    0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을
작성하시오. 입력 첫째 줄에 정수 N(0 ≤ N ≤ 12)이 주어진다. 출력 첫째 줄에 N!을
출력한다.

입력
    정수 N(0 ≤ N ≤ 12)
사고 과정
    팩토리얼 개념. N! = N * N-1 * N -2 * ... * 1
    어떻게 재귀로 구현할까? N=1이 될 때까지, 자기 자신을 n-1인자로 호출하는
함수를 만든다.
    !! 팩토리얼의 성질. N! = N * (N-1)!  e.g. 3! = 3 * 2! , 2! = 2 * 1!
    이게 완전히 재귀함수에 적합하다.

    1. 변수 정의 : 입력값 N
    2. 입력 scanf
    2. 함수 fact(n) : 팩토리얼 성질 이용.
    n-1 인자로 재귀호출한 반환값과 자기자신의 인자 n을 곱.
    n=1일 경우를 생각해야 함. 이 경우엔 재귀호출하지 않고(멈추고) 1을 반환.

주의
    입력이 0부터 시작하기 때문에, 조건문이 n == 1이어선 안 된다. >, <로 범위로
잡아야 함.
*/

static int result = 1;

int fact(int n) {
  if (n == 1)
    return result;
  else {
    result *= n;
    printf("n=%i result=%i\n", n, result);
    fact(n - 1);
    return 0;
  }
}

int fact2(int n) {
  if (n == 1)
    return 1;
  else {
    result *= n;
    printf("n=%i result=%i\n", n, result);
    fact(n - 1);
    return 0;
  }
}

int factorial(int n) {
  if (n <= 1) {
    printf("n=0 OR n=1\n");
    return 1;

  } else {
    printf("n=%i result=%i\n", n, n * factorial(n - 1));
    return n * factorial(n - 1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%i\n", factorial(n));
  return 0;
}
