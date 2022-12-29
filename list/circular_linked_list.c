#include <stdio.h>
#include <stdlib.h>

// TODO 이해 필요

typedef int element;
typedef struct Node {
  element data;
  struct Node *link; // 자기참조 구조체
} ListNode;

/* insert_first
 * phead : head pointer을 가리키는 pointer (call by reference 때문에 씀)
 * p : 선행 노드
 * node : 삽입될 노드
 * */
ListNode *insert_first(ListNode **phead, element value) {
  ListNode *inserted = (ListNode *)malloc(sizeof(ListNode));
  inserted->data = value;

  // 리스트가 비어있는 경우
  if (*phead == NULL) {
    // head를 새로운 노드를 가리키도록 하고, 
    // 새로운 노드는 자기 자신을 가리키도록 함. (원형ㅋㅋ)
    *phead = inserted;
    inserted->link = inserted;
  } else { // 일반적인 경우
    // head link가 바라보던 노드를 새로운 노드 link가 가리키도록 하고,
    // head link는 이제 새로운 노드를 바라보도록 함.
    inserted->link = (*phead)->link;
    (*phead)->link = inserted; // !! 이로써 새로운 노드가 맨 첫번째.
  }

  return inserted;
}

// ?? 뭔 차이지.
ListNode *insert_last(ListNode **phead, element value) {
  ListNode *inserted = (ListNode *)malloc(sizeof(ListNode));
  inserted->data = value;

  // 리스트가 비어있는 경우
  if (*phead == NULL) {
    *phead = inserted;
    inserted->link = inserted;
  } else {
    inserted->link = (*phead)->link;
    (*phead)->link = inserted;
    *phead = inserted; // head가 새로운 노드를 가리키도록 바꿔주면 
                       // 새로운 노드가 마지막 노드.
  }
  return inserted;
}

/* display (개수 +1만큼만 반복)
 * head : head pointer
 * */
void display(ListNode *head, int number) {
  ListNode *p = head; // call by value
  // 반복문 : 다음 노드의 주소값을 할당해 앞으로 나아가면서 print
  for (int i = 0; i < number + 1; i++) {
    printf(" ---> [ %i | %p ]", p->data, p->link);
    p = p->link;
  }
}

int main() {
  ListNode *h = NULL; // head pointer 정의 (리스트 생성)

  for (int i = 0; i < 10; i++) {
    printf("\n\n");
    h = insert_first(&h, i);
    printf("%p", h);
    display(h, i);
  }

      printf("\n============================\n");
  ListNode *h2 = NULL; // head pointer 정의 (리스트 생성)

  for (int i = 0; i < 10; i++) {
    printf("\n\n");
    h2 = insert_last(&h2, i);
    printf("%p", h2);
    display(h2, i);
  }

}
