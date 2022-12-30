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
      return node;
    } else {
      TreeNode *ndd = find(node->left, data);
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