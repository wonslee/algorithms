/*
 * 삽입정렬
 *
 * 선택정렬과 유사한 점은, 리스트를 반으로 쪼갠다는 것
 * 정렬된 부분을 A, 정렬되어있지 않은 부분을 B라고 할 때
 * N만큼 반복하면서
 * 매번 B의 첫번째 숫자가 A의 어느 위치에 삽입되어야 할지를 결정한다. 이게 핵심.
 * 삽입하게 되면, A의 길이는 1 증가하고 B의 길이는 1 감소한다.
 * 그리고 반복에 쓰이는 index는 1 증가한다.
 * */
#include <stdio.h>
#define SIZE 6

void printList(int list[]) {
  printf("[ ");
  for (int i = 0; i < SIZE; i++) {
    printf("%i ", list[i]);
  }
  printf("]\n");
}
void insertion_sort(int list[]) {
  // index는 1부터 size-1 까지
  for (int i = 1; i < SIZE; i++) {
      int j, key = list[i]; // list[i]값은 자리 이동 중에 묻힌다. 미리 저장
    // 핵심 : 삽입할 index 찾기. i-1번째부터 역순으로 조사
    for (j = i - 1; j >= 0 && list[j] > key; j--)
      list[j + 1] = list[j]; // 오른쪽으로 한칸씩 이동
                             //
    list[j + 1] = key;   // 삽입될 자리를 찾음
    printList(list);
  }
}

int main(){
    int myList[SIZE] = {5,3,8,1,2,7};
    printList(myList);

    insertion_sort(myList);

    printList(myList);
}
