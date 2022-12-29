#include <stdio.h>

#define MAX_LIST_SIZE 100 // 배열의 최대 크기

typedef int element;
typedef struct {
  int list[MAX_LIST_SIZE]; // 배열 정의
                           // 현재 배열에 저장된 항목들의 개수
  int length;
} ArrayList;

/* is_empty
 * 리스트가 비어있으면 1을 반환, 그렇지 않으면 0을 반환 */
int is_empty(ArrayList *L) { return L->length == 0; }

/* is_full
 * 리스트가 가득 차 있으면 1을 반환, 그렇지 않으면 0을 반환 */
int is_full(ArrayList *L) { return L->length == MAX_LIST_SIZE; }

void display(ArrayList *L) {
  for (int i = 0; i < L->length; i++) {
    printf("%i ", L->list[i]);
  }
}

void add(ArrayList *L, int pos, element item) {
    printf("\n\n=====add========\n");
  // 삽입의 조건 : array가 가득 차 있지 않고, 삽입할 index가 array 범위 안에
  // 있어야 한다.
  if (!is_full(L) && pos >= 0 && pos <= L->length) {

    // 반복문 : (length -1 )번째부터 줄어들면서 pos번째까지 하나씩 뒤로 밀기.
    // 마지막엔 pos번째가 그 다음번째와 값이 같아야 한다.
    for (int i = L->length - 1; i >= pos; i--) {
      printf("list[%i]=%i\t <-- list[%i]=%i\n",  i+1, L->list[i + 1], i,
             L->list[i]);
      L->list[i + 1] = L->list[i]; // 이전 index의 element를 다음으로 이동
    }
      printf("list[0]=%i\t <-- %i.\n", L->list[pos], item);
    L->list[pos] = item; // 해당 index에 item 할당
    L->length++; // length 1 증가
  } else
    printf("error!");
}

element delete (ArrayList *L, int pos) {
        printf("\n\n=====delete========\n");

  element item;
  // 삭제의 조건 : array가 비어있지 않아야 한다. 또한 pos가 array 범위내에
  // 있어야 함.
  if (!is_empty(L) && pos >= 0 && pos <= L->length) {

    item = L->list[pos]; // 반환할 item 할당

    // 반복문 : pos번째부터 늘어나면서 하나씩 앞으로 당기기.
    for (int i = pos; i < L->length - 1; i++) {
        printf("list[%i]=%i\t -->   list[%i]=%i\n",  i+1, L->list[i + 1], i,
             L->list[i]);
      L->list[i] =L->list[i + 1]; // 다음 index의 element를 현 위치(이전)으로 이동
    }
          printf("%ith item deleted. \n", pos);

    /* L->list[pos] = -1; // 남은 마지막 찌거기 삭제..할 필요 없음. */
    L->length--;       // length 1 감소

  } else
    printf("error!");
  return item;
}

int main() {
  ArrayList myList = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10};

  display(&myList);

  add(&myList, 0, 1000);
  display(&myList);

  delete (&myList, 3);
  display(&myList);
}
