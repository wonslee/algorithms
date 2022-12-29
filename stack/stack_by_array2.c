#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

/* stack을 structure로 구현 */
typedef int element;

typedef struct {
  element data[MAX_STACK_SIZE];
  int top;
} Stack;

/* is_empty : 공백 상태*/
int is_empty(Stack *s) { return (s->top == -1); }

/* is_full : 포화 상태 검출*/
int is_full(Stack *s) { return (s->top == (MAX_STACK_SIZE - 1)); }

/* push
 * s : stack pointer
 * item : 삽입할 정수 데이터 */
void push(Stack *s, element item) {
  if (is_full(s)) {
    fprintf(stderr, "stack overflow!\n");
    exit(1);
  } else
    s->data[++(s->top)] =
        item; // top을 +1 한 후, stack의 해당 위치( 맨위)에 item 삽입
}

/* pop
 * s : stack pointer
 */
element pop(Stack *s) {
  if (is_empty(s)) {
    fprintf(stderr, "stack underflow!\n");
    exit(1);
  } else
    return s
        ->data[(s->top)--]; // stack의 맨위 위치 데이터를 반환한 후, top을 -1
}

element peek(Stack *s) {
  if (is_empty(s)) {
    fprintf(stderr, "stack 공백임!\n");
    exit(1);
  } else
    return s->data[s->top];
}

int main() {
// initialize
  Stack first_stack;
  first_stack.top = -1;

  push(&first_stack, 100);
  push(&first_stack, 200);
  push(&first_stack, 300);
  printf("%i\n", peek(&first_stack));
  printf("%i\n", pop(&first_stack));
  printf("%i\n", pop(&first_stack));
  printf("%i\n", pop(&first_stack));
}
