/* binary search tree ADT
 * 탐색을 목적으로 한 이진 트리 기반의 자료구조
 *
 * 정의
 *      기본적으로 data는 이진 트리와 동일. ordering이라는 점에서 특별함!
 *      모든 원소의 키는 primary key를 갖는다.
 *      왼쪽 서브 트리 키 <= root key <= 오른쪽 서브 트리 키
 *      서브 트리들도 이진 탐색 트리.
 *      성질상 전위순회 로직을 가질 수밖에 없음.
 *
 * 연산
 *      탐색 : 주어진 탐색 키 값과 현재의 루트 노드 키 값을 비교
 *              비교결과에 따라 왼쪽, 오른쪽 서브트리로 반복 순환
 *              같을 경우 찾은 것이므로 해당 값을 반환.
 *      삽입
 *      삭제
 *
 * 시간복잡도(탐색, 삽입, 삭제)
 *      트리의 높이를 h라고 했을 때 O(h).
 *      좌우 균형적인 트리인 경우 O(log2h)
 *      편향적인 트리의 경우 O(h).
 * */
// NOTE : print_ascii_tree랑 같이 컴파일 해야 함.

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  int data;
  struct TreeNode *left, *right;
} TNode;

// extern 출력 함수
extern void print_ascii_tree(TNode *t);
extern TNode *find_min(TNode *t);
extern TNode *find_max(TNode *t);

// 노드 생성 함수
TNode *createNode(int item, TNode *left, TNode *right) {
  TNode *node = (TNode *)malloc(sizeof(TNode));
  node->data = item;
  node->left = left;
  node->right = right;
  return node;
}

/* search
 * 1. 공백 검사 : 트리가 공백 상태일 경우 함수 종료
 * 2. 탐색키와 노드(루트) 키 비교 조건문
 *      같을 경우 해당 노드 반환
 *      탐색키가 작을 경우 왼쪽 서브트리로 순회
 *      탐색키가 클 경우 오른쪽 서브트리로 순회
 *
 * 특이사항 : 결국 전위순회이기 때문에 반복문으로도 구현 가능.
 * */
TNode *search(TNode *node, int key) {
  // 공백 노드 검사
  if (node == NULL) {
    printf("not found!\n");
    return NULL;
  } else

    // 탐색할 key와 node->data 비교
    if (key == node->data) {
      printf("%i found!\n", node->data);
      return node;
    } else if (key < node->data)
      return search(node->left, key);
    else
      return search(node->right, key);
}

/* 삽입
 * 이진 탐색 트리의 조건은 중복불가이다. 따라서 탐색을 통해 일단 같은게 있지
 않은지
 * 검사해야 함.
 *
 * 1. 탐색 --> 값이 같은지 계속 비교.
 *      같은 값이 없고 탐색에 실패는 조건 충족. 따라서 노드 생성 및 링크 연결.
        탐색 키와 노드 키 값이 크거나 작을 경우에 따라 순회.
2. 탐색 실패(삽입 관점에선 성공) --> 조건을 충족했으므로 노드 생성 후 key값
할당.
 */
TNode *insert(TNode *node, int key) {
  // 노드가 공백일 경우 새로운 노드 생성, 반환
  if (node == NULL)
    node = createNode(key, NULL, NULL);

  // 아닐 경우, 공백 노드가 나올때까지 순환 탐색
  if (key < node->data)
    node->left = insert(node->left, key);
  else if (key > node->data)
    node->right = insert(node->right, key);

  // 중복은 무시
  return node;
}

// 반복문으로 구현해본 삽입 연산
TNode *insert_loop(TNode *node, int item) {
  if (node == NULL)
    return createNode(item, NULL, NULL);
  // 예비 부모 노드
  TNode *parent;
  while (node != NULL) {
    parent = node;
    // 탐색할 key와 node->data 비교
    if (item == node->data) {
      printf(":( duplicated!\n");
      return NULL;
    } else if (item < node->data)
      node = node->left;
    else
      node = node->right;
  }

  TNode *new_node = createNode(item, NULL, NULL);

  // 값에 따라 왼쪽 혹은 오른쪽 링크에 연결
  if (item < parent->data)
    parent->left = new_node;
  else
    parent->right = new_node;

  return new_node;
}

/* 삭제 연산
 * 우선 삭제하려는 키값이 트리안의 어떤 노드에 있는지 알아야 한다. 탐색.
 * 탐색 완료 후에 3가지 경우가 있다.
 * 1. 단말노드
 *      부모노드의 링크를 끊고
 *      동적 할당 메모리 해제
 * 2. 하나의 서브트리를 갖는 노드
 *      부모노드의 링크를 자식 서브트리에게 향하게 하고
 *      동적 할당 메모리 해제
 * 3. 두개의 서브트리를 갖는 노드
 *      어떤 노드를 삭제된 노드 위치로 가져올 것이냐가 가장 문제.
 *      삭제될 노드와 값이 가장 비슷한 노드를 후계자로 선택해야 가장 효율적.
 *      그래야만 기존 트리가 변화없이 조건을 만족할 수 있다.
 *
 *      왼쪽 서브트리에서 가장 큰 값 OR 오른쪽 서브트리에서 가장 작은 값.
 *      그리고 나름의 로직을 통해 둘 중 하나를 후계자로 선택. (상관 없음)
 *
 * */
TNode *delete (TNode *node, int key) {
  // 공백노드일 경우는 해당 key가 트리안에 없는 것. NULL 반환
  if (node == NULL) {
    printf(":( not found!");
    return NULL;
  }

  TNode *temp;
  // 탐색
  if (key < node->data)
    node->left = delete (node->left, key);
  else if (key > node->data)
    node->right = delete (node->right, key);
  // 탐색 key와 노드 key가 같음. 즉 탐색 완료.
  else {
    // 1번째 경우, 단말노드이므로 temp = NULL
    // 2번째 경우, temp = 하나의 서브루트 노드
    if (node->left == NULL) {
      temp = node->right;
      free(node);
      return temp;
    } else if (node->right == NULL) {
      temp = node->left;
      free(node);
      return temp;
      // 3번째 경우, node 양쪽에 서브루트를 갖는다.
    } else {
      // 중간값 (여기선 오른쪽 서브트리에서 가장 작은 값)을 가진 노드를 할당
      TNode *temp = find_min(node->right);
      // 중위순회 시 후계 노드를 복사, 삭제
      node->data = temp->data;
      node->right = delete (node->right, temp->data);
    }
  }
  return node;
}

int main() {
  TNode *myTree, *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9, *n10, *n11, *n12;

  n12 = createNode(1000, NULL, NULL);
  n11 = createNode(460, NULL, n12);
  n10 = createNode(200, NULL, NULL);
  n9 = createNode(70, NULL, NULL);

  n8 = createNode(45, NULL, NULL);
  n7 = createNode(400, n10, n11);
  n6 = createNode(50, n8, n9);
  n5 = createNode(5, NULL, NULL);
  n4 = createNode(2, NULL, NULL);
  n3 = createNode(100, n6, n7);
  n2 = createNode(3, n4, n5);
  n1 = createNode(8, n2, n3);
  myTree = n1;

  print_ascii_tree(myTree);

  int target;
  char mode;
  printf("##########################\n");
  printf("PRESS...\n\
          s : search\n\
          i : insert\n\
          d : delete\n\
          p : print tree\n\
          q : quit\n");
  printf("##########################\n");

  while (scanf(" %c", &mode) && mode !='q') {
    printf("TARGET : ");
    switch (mode) {
    case 'p':
      printf("\n");
      print_ascii_tree(myTree);
      break;
    case 's':
      scanf("%i", &target);
      TNode *result = search(myTree, target);
      break;
    case 'i':
      scanf("%i", &target);
      TNode *new1 = insert(myTree, target);
      break;
    case 'd':
      scanf("%i", &target);
      delete (myTree, target);
      break;
    default:
      exit(0);
    }
  }
  return 0;
}
