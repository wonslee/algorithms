/* ADT
 * */
#include <stdio.h>
#define SIZE 9
int list[SIZE] = {10, 4, 5, 1, 9, 6, 3, 8, 2};

void printList() {
  printf("[ ");
  for (int i = 0; i < SIZE; i++) printf("%i ", list[i]);
  printf("]\n");
}

/* swap : swap ith element with jth element */
void swap(int i, int j, int length) {
/*  printf("---------swap--------------\n"); */
  /* printf("v[%i]=%i\t v[%i]=%i\n", i, v[i], j, v[j]); */
  int temp = list[i];
  list[i] = list[j];
  list[j] = temp;

  printList();
}

/* quick sort : sort v[left]...v[right] into increasing order */
void quick_sort(int left, int right, int length) {
      // do nothing if array contains fewer than two elements
  if (left >= right) return;

  printf("---------quick_sort--------------\n");
  printf("\n left=%i\t right=%i\n\n", left, right);

  int mid = (left + right) / 2;
  // move partition(left) element to middle
  swap(left, mid, length);

  int last = left;
  int pivot = list[left];
  printf("pivot=%i\n", pivot);

  // left + 1부터, right 번째까지 반복
  for (int i = left + 1; i <= right; i++) {
    printf("last=%i\t v[%i]=%i\t \n", last, i, list[i] );
    // 핵심 분기임. left+1 번째가 left번째(pivot)보다 작을 경우, last+1번째와 i번째끼리 swap
    if (list[i] < pivot)
      swap(++last, i, length);
  }
  swap(left, last, length);

  // recursive call
  quick_sort(left, last - 1, length);
  quick_sort(last + 1, right, length);
}

/* main */
int main() {
  int left = 0, right = 8;

  printList();
 
  quick_sort(left, right, SIZE-1);

    printList();

 }
