/*
 *이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder
traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을
작성하시오.

입력
첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다.
둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가
주어진다. 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트
노드가 된다. 자식 노드가 없는 경우에는 .으로 표현한다.

출력
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다.
각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.


# 문제접근
이진 트리 자료구조 ADT대로 구현할 수 있는가를 물어보는 문제.
난 pointer과 struct를 쓰는 linked list 방법을 쓸 거.

기존에 있던 앤지 탐색해야 하나?
그럼 이진탐색트리인데..

결국 알파벳들은 A를 제외하곤 총 2번 나오게 되어있다.
자신이 루트일 때와 자신이 자식일 때.
자식으로써 나올 땐 배열(큐)에 해당 노드를 저장해놓고,
루트로써 나올 땐 배열에서 빼면 됨.

1. 입력: int N
'A'는 루트로 먼저 삽입
2. loop(N):
2-1. 입력: char input
2-2. 뒤의 두 알파벳의 경우, 노드 생성(malloc)
2-3. input이 .인 경우 무시
2-4. 루트에다 입력된 대로 노드 연결
3. 전위순회
4. 중위순회
5. 후위순회

데이터:
1개의 int data와 2개의 pointer을 갖는 struct TreeNode
root를 가리키는 TreeNode pointer

연산:
노드 생성
전위 순회: 루트 -> 왼쪽 자식 -> 오른쪽 자식
중위 순회: 왼쪽 자식 -> 루트 -> 오른쪽 자식
후위 순회: 왼쪽 자식 -> 오른쪽 자식 -> 루트


 궁금한 점
 - 1차원 배열로 트리를 구현했을 때 순회하는 방법?
배운 점 
- 순회 탐색 로직.
왜 일반적인 순회로 했을 때 계속 에러가 나온걸까?

 */
#include <stdio.h>
#include <stdlib.h>

// type definition
typedef struct T {
  char data;
  struct T *left, *right;
} TreeNode;

// 노드 생성
TreeNode *makeNode(char ch) {
  TreeNode *nd = (TreeNode *)malloc(sizeof(TreeNode));
  nd->data = ch;
  nd->left = NULL;
  nd->right = NULL;
  return nd;
}
// 노드에 값 집어넣기
void setNode(TreeNode *nd, char fir, char sec, char thr) {
  nd->data = fir;
  if (sec != '.') {
    nd->left = makeNode(sec);
  }
  if (thr != '.') {
    nd->right = makeNode(thr);
  }
}

// 순회 탐색..
TreeNode *find(TreeNode *node, char data) {
  if (node != NULL) {
    if (node->data == data) {
        printf("node->data=%c\n", node->data);
      return node;
    } else {
      TreeNode *ndd = find(node->left, data);
      printf("ndd=%p\n", ndd);
      if (ndd != NULL)
        return ndd;
      else
        return find(node->right, data);
    }
  } else
    return NULL;
}
// preorder(): 전위순회
void preorder(TreeNode *node) {
  if (node != NULL) {
    printf("%c", node->data);
    preorder(node->left);
    preorder(node->right);
  }
}
// inorder(): 중위순회
void inorder(TreeNode *node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%c", node->data);
    inorder(node->right);
  }
}
// postorder(): 후위수노히
void postorder(TreeNode *node) {
  if (node != NULL) {
    postorder(node->left);
    postorder(node->right);
    printf("%c", node->data);
  }
}

int main() {
  int n;
  char a, b, c;
  scanf("%i", &n);
  getchar();

  TreeNode *root = makeNode('A');
  TreeNode *sub;

  for (int i = 0; i < n; i++) {
    scanf("%c %c %c", &a, &b, &c);
    getchar();
    // 서브 루트 노드 찾기
    sub = find(root, a);
    // 자식 노드 만들기
    setNode(sub, a, b, c);
  }

  preorder(root);
  printf("\n");
  inorder(root);
  printf("\n");
  postorder(root);
}
