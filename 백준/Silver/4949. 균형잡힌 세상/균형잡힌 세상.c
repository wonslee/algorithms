#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define SIZE 102

char text[SIZE];
char stack[SIZE];
int top = -1;

bool isEmpty() { return (top == -1); }

void push(char item) { stack[++top] = item; }
char pop() { return stack[top--]; }
void init() { top = -1; }

int main() {
  while (1) {
        // initialize stack
      init();
      bool flag = true;

    fgets(text, SIZE, stdin);

    // 마지막 마침표일 경우 프로그램 종료
    if (strcmp(text, ".\n") == 0)
      break;

    // 반복: 한 문장에 대한 괄호 처리 과정
    for (int i = 0; i < strlen(text); i++) {
      // 왼쪽 괄호인 경우 무조건 push
      if (text[i] == '(' || text[i] == '[')
        push(text[i]);
      // 오른쪽 괄호일 때. 
      // 공백일 경우 no하고 끝내고, 공백이 아니고 top 원소와 매칭되면 pop
      else if (text[i] == ')') {
          char c = pop();
        if (c != '(') {
          flag = false;
          break;
        }
      } else if (text[i] == ']') {
        char c = pop();
        if (c != '[') {
          flag = false;
          break;
        }
      } 
    }

    if (!isEmpty())
        flag=false;

    // 문장이 균형 이루는지 평가
    if (flag == false)
        printf("no\n");
    else 
        printf("yes\n");
  }
}