/*
문제접근
stack을 썼을 때 효율적이라고 배웠다.
array로 구현해봄.

1. data:
char arr[50], input
int top, N

2. operation:
push : arr[++top] = input
pop : if empty(top <=0), "NO"
if 쌍 매칭, top --
else  print "NO" return


3. loop: for N, 각 줄에 대한 괄호열 검사 반복, arr[50] 및 top 초기화
    1-1. scanf input -> if 왼쪽 괄호, push. (조건 없이)
    1-2. else(오른쪽 괄호),
            if stack이 공백, "NO".
            else if 매칭, pop.
            else, push.
    1-3. top==0이 될 때까지 문제 없을 경우 "YES"


수정:
- 괄호 매칭 성공 여부는 매번 매칭이 맞아야만 하는게 아니다.
마지막에 정산해야 함. 연속으로 ')'가 나오는 경우가 많기 때문. ')'도 push해야 함.
- 괄호 매칭 성공의 기준이 핵심.
모든 원소를 알맞게 push, pop했다는 전제 하에,
마지막에 top==-1 (공백 스택)이면 성공.

- 런타임 에러: OutofBounds. 보통 배열에서 할당된 경계를 넘어가서 발생.
string의 마지막 index인 '\0'자리를 비워놔야 한다.
문제의 조건은 50이었고, 51 이상이었어야 함.

*/
#include <stdio.h>


void Swappointer(int **ptr1, int **ptr2)
{
	int *temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int main() {

        int num1 = 5;
int num2 = 10;

	
	int *ptr1 = &num1;
	
	int *ptr2 = &num2;
	
	//Swappointer(ptr1, ptr2);
	
	printf("%d %d\n", *ptr1, *ptr2);
	printf("ptr1: %p, ptr2: %p\n", ptr1, ptr2);
    printf("===================\n");
	Swappointer(&ptr1, &ptr2);
	printf("%d %d\n", *ptr1, *ptr2);
	printf("ptr1: %p, ptr2: %p\n", ptr1, ptr2);

  int N;
  scanf("%d", &N);

  while (N--) {
    // initialize
    char input[52], stack[52];
    // index of top
    int top = -1;
    scanf("%s", input);

    // loop: input string
    for (int i = 0; input[i] != '\0'; i++) {
      switch (input[i]) {
        // 왼쪽 괄호일 경우, push
      case '(':
        stack[++top] = input[i];
        break;
        // 오른쪽 괄호일 경우,
      case ')':
        // 공백인 경우 NO
        if (top == -1) {
          top = 1000;
          break;
        }
        // stack의 top 요소와 매칭된 경우 pop
        if (stack[top] == '(')
          top--;

        break;
      }
    }

    // 출력: 아무 문제 없을 경우 YES, 아닐 경우 NO
    if (top == -1)
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
