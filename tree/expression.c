#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* expression evaluate 알고리즘
 *
 * 만약 수식트리가 공백 상태이면 그냥 복귀.
 * 그렇지 않으면 왼쪽 서브트리 계산 함수를 재귀호출. 이때 인자는 자식 노드
 * 똑같은 식으로 오른쪽 서브트리 계산
 *
 * 루트 노드의 데이터 필으뎅서 연산자 추출
 * 추출된 연산자로 연산 반복 수행
 * */

// type definition
typedef struct TreeNode {
  int data;
struct TreeNode *left;
  struct TreeNode *right;
} TNode;

TNode *createNode(int item, TNode *left, TNode *right) {
  TNode *node = (TNode *)malloc(sizeof(TNode));
  node->data = item;
  node->left = left;
  node->right = right;

  return node;
}

int evaluate(TNode *node) {
  if (node == NULL)
    return 0;

  // 자식 없는 노드, 즉 피연산자의 경우 더 이상 evaluate 실행 하지 않음.
  if (node->left == NULL && node->right == NULL) {
    printf("operand %i \n", node->data);
    return node->data;
  } else {
    printf("operator %c \n", node->data);
    // !! 결국 후위 연산.
    // 본질적으로 왼쪽, 오른쪽 자식 재귀를 먼저 한 다음에 node에 방문하는 로직.
    int operand_x = evaluate(node->left);
    int operand_y = evaluate(node->right);
    // 방문
    int operator= node->data;
    int result;

    switch (operator) {
    case '+':
      result = operand_x + operand_y;
      break;
    case '-':
      result = operand_x - operand_y;
      break;
    case '*':
      result = operand_x * operand_y;
      break;
    case '/':
      result = operand_x / operand_y;
      break;
    }
      printf("result = %i \n", result);
    return result;
  }
}

int main() {
  TNode *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9;

  n9 = createNode(100, NULL, NULL);
  n8 = createNode(3, NULL, NULL);
  n7 = createNode(4, NULL, NULL);
  n6 = createNode('/', n9, n8);
  n5 = createNode('*', n6, n7);
  n4 = createNode(25, NULL, NULL);
  n3 = createNode(16, NULL, NULL);
  n2 = createNode('+', n3, n4);
  n1 = createNode('-', n5, n2);

  int result = evaluate(n1);
    printf("%i \n", result);
}
