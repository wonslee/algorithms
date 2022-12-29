/*
 * 모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와
짝지어지지 않는다. 짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이
잡혀야 한다. 정민이를 도와 문자열이 주어졌을 때 균형잡힌 문자열인지 아닌지를
판단해보자.

입력
하나 또는 여러줄에 걸쳐서 문자열이 주어진다. 각 문자열은 영문 알파벳, 공백,
소괄호("( )") 대괄호("[ ]")등으로 이루어져 있으며, 길이는 100글자보다 작거나
같다. 각 줄은 마침표(".")로 끝난다.

입력의 종료조건으로 맨 마지막에 점 하나(".")가 들어온다.
출력
각 줄마다 해당 문자열이 균형을 이루고 있으면 "yes"를, 아니면 "no"를 출력한다.


# 문제접근
stack을 써서, 왼쪽 괄호는 push 오른쪽 괄호는 짝이 맞을 경우 pop하는 과정을 갖자.
다른 문자들은 무시하고, switch case로 괄호와 .만 보자.

data:
stack[100];
int top=-1;

연산:
isEmpty():
스택이 공백상태인지 boolean 값을 반환.

isFull()은 길이가 한정되어있으므로 구현 안 함.

push(int item):
stack의 맨 위에 아이템 삽입. top index 1 증가

pop():
맨 위의 아이템 제거 후 return. top index 1 감소

init():
stack을 초기화 (top index만 초기화하면 됨ㅋㅋ)

1. 반복(인풋이 들어오는 한.):
1-1. switch case:
왼쪽 괄호일 경우  push, 오른쪽 괄호일 경우 pop,
마침표일 경우 현재 stack의 size에 따라 yes 혹은 no를 출력
출력한 후, stack을 초기화.

오른쪽 괄호가 빈 stack일 때 나왔을 경우, 이건 아예 처음부터 no다.
만약 이 경우에 대한 로직을 안 짜놓으면, 그 뒤의 괄호들이 정상적일 때 오류를
감지할 수 없다. e.g. hello)()(). 그래서 top순서를 아예 망쳐버려서 -1이 나올 수
없도록 한다.

# 주의점
맨 마지막에 점 하나.. 악랄하다.
왜 입력과 출력 갯수가 안 맞나 했더니 마지막의 마침표는 아예 입력 종료조건.

# 배운점
gets, fgets라는 '문장 입력'용 함수가 있었다.
안일하게 모든 경우의 수를 다 안 살펴봤다. 
*/
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
