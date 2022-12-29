#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* expression evaluate 알고리즘
 *
 * 이진 트리를 사용하기 떄문에 하나의 디렉토리 안에 최대 2개..
 * 먼저 서브트리의 용량을 모두 계산한 다음에 루트 디렉토리의 용량이 계산되어야
 * 한다. 즉, 후위순회!
 * */

typedef int element;
typedef struct TreeNode {
  element data;
  struct TreeNode *left, *right;
} TNode;

// create
TNode *createNode(element item, TNode *left, TNode *right) {
  TNode *node = (TNode *)malloc(sizeof(TNode));
  node->data = item;
  node->left = left;
  node->right = right;
  return node;
}
// calculate
int calculateSize(TNode *root) {

  int size;
  if (root == NULL)
    return 0;
  // 만약 왼쪽 오른쪽 자식 노드가 모두 없으면 단말노드로, 하나의 파일로 생각
  if (root->left == NULL && root->right == NULL) {
    size = root->data;
    printf("file = %i \n", size);
    return size;
  }
  // 자식 노드가 있으면 더하기 연산을 해서 자식 노드들을 더함.
  else {
    int leftSize = calculateSize(root->left);
    int rightSize = calculateSize(root->right);
    size = leftSize + rightSize;
    printf("directory = %i \n", size);
    return size;
  }
}

int main() {
  TNode *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9;

  n9 = createNode(90, NULL, NULL);
  n8 = createNode(80, NULL, NULL);
  n7 = createNode(70, NULL, NULL);
  n6 = createNode(60, NULL, NULL);
  n5 = createNode(50, NULL, NULL);
  n4 = createNode(0, n8, n9);
  n3 = createNode(0, n6, n7);
  n2 = createNode(0, n4, n5);
  n1 = createNode(0, n2, n3);

  calculateSize(n1);
}
