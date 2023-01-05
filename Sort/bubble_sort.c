/* 버블 정렬
 *
 * 반복(길이 N):
 * 1. 인접한 2개의 레코드를 비교
 * 2. 크기가 순서대로 되어있지 않으면 서로 교환
 * --> 한번의 스캔 이후엔 가장 큰 레코드가 리스트의 오른쪽 끝으로 이동
 *
 *  비교횟수는 어떤 경우에도 항상 일정하고 O(n^2)
 *
 *  이동횟수가 가장 문제.
 *  버블 정렬의 가장 큰 문제점은 교환 과정이다.
 *  하나의 요소가 가장 왼쪽에서 가장 오른쪽으로 이동하기 위해선
 *  배열의 모든 다른 요소들과 교환되어야 한다.
 *  swap은 이동 작업보다 더 복잡하기 때문에, 버블 정렬은 
 *  단순함에도 불구하고 거의 쓰이지 않는다.
 *  */
#include <stdio.h>
#define SIZE 6
void swap(int *x,int *y){
    int temp = *x;
    *x=*y;
    *y=temp;
}
void printList(int list[]) {
  printf("[ ");
  for (int i = 0; i < SIZE; i++) {
    printf("%i ", list[i]);
  }
  printf("]\n");
}

void bubble_sort(int list[], int size){
    while (size --)
        for (int j=0; j < size; j++){
            printf("j=%i\t%i %c %i\n", j, list[j], list[j] > list[j+1] ? '>' : '<',  list[j+1]);
            if (list[j] > list[j+1]) swap(&list[j], &list[j+1]);
                                    printList(list);

        }
}

int main(){
    int myList[SIZE] = {5,3,8,1,2,7};
    bubble_sort(myList, SIZE);
}
