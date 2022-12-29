#include <stdio.h>
#include <stdlib.h>

typedef int element;
// StackNode : linked list의 노드
typedef struct StackNode {
  element data;
  struct StackNode *link;
} SNode;

SNode *top = NULL; // top node를 가리킬 pointer. 초기값은 NULL pointer

void push(element item) {
  SNode *temp = (SNode *)malloc(sizeof(SNode)); // dynamic allocation
  // 새로운 노드에 item인자와 기존의 top이 가리키던 주소값(다음 노드)을 할당한
  // 뒤 top이 그걸 가리키도록
  temp->data = item;
  temp->link = top;
  top = temp;
}

element pop() {
  element item;
  // 기존의 top이 가리키던 노드를 해제해야 하기 때문에, temp라는 새로운 pointer
  // 선언
  SNode *temp = top;
  if (top == NULL) {
    fprintf(stderr, "\n\n Stack is empty!\n");
    exit(0);
  } else {
    // return할 용도의 item은 기존의 data, 이제 top은 temp가 가리키던 다음
    // 노드를 가리킴
    item = temp->data;
    top = temp->link;
    free(temp); // 해제
    return item;
  }
}

void printStack() {
  SNode *p = top;
  printf("STACK [ ");
  for (SNode *p = top; p != NULL;) {
    printf("%i ", p->data);
    p = p->link;
  }
  printf("]  \n");
}

int main() {
    const int LENGTH = 5;
    for(int i=0; i < LENGTH; i++){
    push(i+1);
    printStack();
    }
    for(int i=0; i < LENGTH + 1; i++){
    pop();
    printStack();
    }

}
