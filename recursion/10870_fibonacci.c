/* 피보나치 수
 * 피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치
수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

Fn = Fn-1 + Fn-2 (n ≥ 2)

입력
첫째 줄에 n이 주어진다. n은 20보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄에 n번째 피보나치 수를 출력한다.

사고과정
피보나치 수열은 본질적으로 반복적이다.
n에 어떤 값이 들어오든지 자기 자신의 정의로 해결이 되는 개념.
그래서 반복문, 재귀함수 두가지 방법으로 구현이 가능.

실행횟수에 대한 생각.
fib(1), fib(0)의 실행횟수는 1(자기자신)
fib(2)의 실행횟수는 1(자기자신) + 2(fib(1)과 fib(0)) = 3
fib(3)의 실행횟수는 1(자기자신) + 3(fib(2)) + 1(fib(1)) = 5
fib(4)의 실행횟수는 1(자기자신) + 5(fib(3)) + 3(fib(2)) = 9
fib(5)의 실행횟수는 1 + 9 + 5 = 15
1,1,3,5,9,15,25,41,...

실행횟수는 fibonacci와 꽤나 비슷하다.
시작하는 값이 다르고 자기 자신의 실행횟수를 더해야 한다는 점에선 다르지만,
이전의 두 순서의 값을 더한 값이 자기자신의 값에 영향을 준다는 점에서 같다.
아무래도 자기자신의 실행횟수가 더해지기 때문에 값이 오르는 속도가 빠르다.
*/

#include <stdio.h>
#include <time.h>

/* here, do your time-consuming job */

int fib(int n) {
  if (n == 0 || n == 1)
    return n;
  else
    return fib(n - 1) + fib(n - 2);
}

int fib_loop(int n) {
  if (n <= 1)
    return n;
  int prev2 = 0, prev1 = 1, cur;
  for (int i = 2; i <= n; i++) {
    cur = prev1 + prev2;
    prev2 = prev1;
    prev1 = cur;
  }
  return cur;
}

int main() {
  clock_t begin = clock();

  int input;
  scanf("%d", &input);

  printf("%d\n", fib(input));
  /* printf("%d\n", fib_loop(input)); */

  clock_t end = clock();

  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%f \n", time_spent);

  return 0;
}
