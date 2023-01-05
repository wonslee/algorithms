#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
  element data;
  struct Node *link; // 자기참조 구조체
} ListNode;

ListNode *insert_first(ListNode *head, int value) {
  ListNode *p = (ListNode *)malloc(sizeof(ListNode));
  p->data = value;
  p->link = head; // head가 가리키던 뒷 노드(원래 1번째였던 노드)의 주소값 복사
  head = p;       // head pointer 값 변경
  printf("\ninsert_first: head=%p", head);

  return head;
}

ListNode *delete_first(ListNode *head) {
  ListNode *removed;
  if (head == NULL)
    return NULL;
  removed = head; // head 주소값을 removed가 받음
  head = removed->link; // removed 링크가 가리키던 뒷노드(원래 2번째였던 노드)의
                        // 주소값 복사
  printf("\ndelete: head=%p", head);
  free(removed);
  return head;
}

/* insert
 * phead : head(head pointer)에 대한 pointer. call by reference를 위해.
 * pre : 삽입될 위치의 선행노드를 가리키는 pointer
 * inserted : 새로운 노드를 가리키는 pointer
 */
ListNode *insert(ListNode **phead, ListNode *pre, element value) {
  // 삽입의 조건 : 없음. 연결리스트에선 링크를 바꿔주는걸로 삽입 개념을 구현함.

  ListNode *inserted = (ListNode *)malloc(sizeof(ListNode));
  inserted->data = value;

  /* 삽입의 3가지 경우 */
  if (*phead == NULL) {
    // 1. head가 NULL일 경우 : 공백리스트이므로, new_node는 NULL을 가리키고 head
    // pointer(=*phead)가 new_node를 가리키도록 함. (리스트의 첫번째 노드로써
    // 생성)
    inserted->link = NULL;
    *phead = inserted;
  } else if (pre == NULL) {
    // 2. before_node가 NULL일 경우 : 리스트 첫번째에 삽입한다는 거!!
    // head pointer가 가리키던 값(after_node 주소값)을 new_node link에 할당
    inserted->link = *phead;
    *phead = inserted;
  } else {
    // 3. 일반적인 경우 : 리스트의 중간에 삽입
    // pre link에 있던 after node 주소값을 new node link에 할당
    // pre link에는 이제 new node의 주소값을 할당.
    inserted->link = pre->link;
    pre->link = inserted;
  }
  printf("\ninsert: pre=%p", pre);

  return pre; // pre 반환
}

/* delete_node
 * 만약 연결리스트가 공백상태(NULL pointer)이면
 * 1. 에러
 * 그렇지 않으면
 * 1. after node를 가리키도록 removed node의 link값을 before node link에 할당
 * 2. removed node 삭제 */
void remove_node(ListNode **phead, ListNode *pre,
                 ListNode *removed) {
  // 삭제의 조건 : 없나?

  if (pre== NULL) {
    // 선행노드가 NULL을 가리킬 경우, head pointer값을 변경한 후 첫번째 노드를
    // 삭제
    *phead = (*phead)->link;
  } else
    // 삭제될 노드의 링크값을 before_node에 할당한 후 삭제
    pre->link = removed->link;

  free(removed);
}

/* concat
 * */
ListNode *concat(ListNode *head1, ListNode *head2) {
  if (head1 == NULL)
    return head2;
  else if (head2 == NULL)
    return head1;

  ListNode *p = head1;
  while (p->link != NULL)
    p = p->link; // 마지막 노드까지 이동.

  p->link = head2; // 원래 NULL이던 link에다 head2 붙이기
  return head1;
}


/* display
 * head : head pointer
 * */
void display(ListNode *head) {
  ListNode *p = head; // call by value
  // 반복문 : 다음 노드의 주소값을 할당해 앞으로 나아가면서 print
  while (p != NULL) {
    printf(" ---> [ %i | %p ]", p->data, p->link);
    p = p->link;
  }
}

/* reverse
 * 역순연산 */
ListNode *reverse(ListNode *head) {
      // p는 역순으로 만들 리스트, q는 역순으로 만들 노드. r은 이전 노드
  ListNode *p = head, *q = NULL, *r; 

  while (p != NULL) {
    r = q, q = p, p = p->link; // 마지막 노드까지 p를 앞으로 전진시킨다
                               // r은 q, q는 p를 차례로 따라간다.
    q->link = r;               // q의 링크 방향을 반대로 바꾼다. 이래도 p를 미리 전진시켜놨기 때문에 다음 에 q에다 p를 할당하면 끝.
  }
  return q;
}

void print_list(ListNode *head) {
  for (ListNode *p = head; p != NULL; p = p->link)
    printf("%i->", p->data);
  printf("NULL \n");
}

ListNode *search(ListNode *head, int target) {
  ListNode *p = head;

  // 반복문 : 다음 노드의 주소값을 할당해 앞으로 나아가면서 찾아진 맨 첫번째
  // 노드(주소값)를 반환
  while (p != NULL) {
    if (p->data == target)
      return p;
    p = p->link;
  }
  return p; // 탐색 실패의 경우 맨 마지막 노드가 가리키던 곳 즉 NULL을 반환
}

int main() {
  ListNode *h = NULL; // head pointer 정의 (리스트 생성)
                      /* 반복해서 첫번째 노드에 삽입
                       * 반복해서 첫번째 노드 삭제*/
  for (int i = 0; i < 4; i++) {
    h = insert_first(h, i);
    display(h);
  }

  printf("\n\n");
  ListNode *p;
  for (int i = 0; i < 4; i++) {
    p = search(h, i);
    insert(&h, p, i * -1);
    display(h);
  }
  printf("\n\n");

  for (int i = 0; i < 4; i++) {
    h = delete_first(h);
    display(h);
  }
  printf("\n\n");


  /* 노드 이해하기
   * 각 노드 변수는 애초에 malloc에서 나오는 주소값을 갖는 pointer이다.
   * 동적 메모리가 하나의노드가 되는 것.
   * head pointer 선언 => 리스트 생성.
   * 단순연결리스트는 원칙적으로 해당 type의 헤드 포인터만 있으면 된다.
   */
  ListNode *head = (ListNode *)malloc(sizeof(ListNode)); // 노드 하나 생성
  head->data = 10;

  ListNode *n1 = (ListNode *)malloc(
      sizeof(ListNode)); // ListNode 하나만큼 동적 메모리 할당
  head->link = n1;       // head pointer과 첫번째 노드 연결!
  n1->data = 100;

  ListNode *n2 = (ListNode *)malloc(sizeof(ListNode));
  n1->link = n2;
  n2->data = 200;

  ListNode *n3 = (ListNode *)malloc(sizeof(ListNode));
  n2->link = n3;
  n3->data = 300;

  ListNode *n4 = (ListNode *)malloc(sizeof(ListNode));
  n3->link = n4;
  n4->data = 400;

  ListNode *n5 = (ListNode *)malloc(sizeof(ListNode));
  n4->link = n5;
  n5->data = 500;

  ListNode *n6 = (ListNode *)malloc(sizeof(ListNode));
  n5->link = n6;
  n6->data = 600;
  n6->link = NULL; // 마지막 노드 link는 NULL

  concat(head, h);
  printf("\n\nconcat: head=%p", head);
  display(head);

  printf("\n\nreverse: ");
    display(reverse(head));

}
