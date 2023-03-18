/*
 * 선택 정렬
 * 가장 이해하기 쉬운 정렬 방법.
 * 두 리스트가 있고 오름차순으로 정렬한다고 가정.
 * 반복(오른쪽 리스트가 공백이 될 때까지):
 * 1. 오른쪽 리스트에서 가장 작은 숫자를 선택(탐색)
 * 2. 왼쪽 리스트로 옮기기
 *
 * 실제로는 메모리공간을 절약하기 위해 배열 하나 안에서 다 처리한다.
 * 제자리 정렬. 즉 옮겨질 숫자를 옮길 index의 숫자와 교환한다.
 * 이렇게 0 index ~ n-2 index 까지 정렬.
 * 마지막인 n-1 index이 가장 큰 값이기 때문.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void printList(int list[]) {
  printf("[ ");
  for (int i = 0; i < SIZE; i++) printf("%i ", list[i]);
  printf("]\n");
}
// sort(int list[], int size): size-1만큼 반복하면서 정렬해나감.
void selection_sort(int list[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int least = i; // 가장 작은 값 index를 초기화
    // i번째와 i+1 ~ size-1 들을 비교하기를 반복
    for (int j = i + 1; j < size; j++)
      if (list[j] < list[least])
        least = j; // 가장 작은 값 탐색
    swap(&list[i], &list[least]);
  }
}

int main() {

  int myList[SIZE];

  srand(time(NULL));
  for (int i = 0; i < SIZE; i++)
    myList[i] = rand() % 100;

  printList(myList);

  clock_t begin = clock();

  selection_sort(myList, SIZE);

  clock_t end = clock();

  printList(myList);

  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time_spent = %lf\n", time_spent);

  
}
