#include <stdio.h>

int fib(int n) {
  if (n == 0 || n == 1)
    return n;
  else
    return fib(n - 1) + fib(n - 2);
}
int main() {
  int input;
  scanf("%d", &input);

  printf("%d", fib(input));
  return 0;
}