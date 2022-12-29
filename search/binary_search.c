#include <stdio.h>

int bin_search(int x, int v[], int n) {
  int low = 0, high = n - 1, index;

  printf("low : %i high : %i \n", low, high);

  while (low <= high) {
    index = (low + high) / 2;
    printf("index : %i value : %i \n", index, v[index]);
    if (x < v[index]) {
      printf("high %i-> %i\n", high, index - 1);
      high = index - 1;

    } else if (x > v[index]) {
      printf("low %i-> %i\n", low, index + 1);
      low = index + 1;
    } else // found match
      return index;
  }
  return -1; // no match
}
int main() {
  int target = 10, myarr[] = {-1, 1, 3, 6, 8, 10, 100, 1431, 623442}, n = 10;

  int result = bin_search(target, myarr, n);

  printf("target is on %i th\n", result + 1);
  return 0;
}
