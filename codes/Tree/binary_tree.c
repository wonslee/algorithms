#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* binary tree ADT
 * 데이터
 *      공백이거나 root node, left subtree, right subtree로 구성된 노드들의 유한
 *      집합
 * 연산
        createTree() : 공백 이진 트리 생성 isEmpty(*bt) : 공백 여부에 대한
 *      boolean 값 return makeTree(*left, item, *right) : 두개의 이진서브트리를
 *      연결해 하나의 이진트리를 생성 getLeft(*bt) : 왼쪽 서브트리를 구함
 *      getRight(*bt) : 오른쪽 서브트리를 구함
 *      getData(*bt) : 루트노드의 데이터를 구함
 *
 *      순회 : parameter은 노드의 pointer. root node가 맨 처음 들어가게 된다.
 *      recursion으로 구현된다는 것에 집중. 하나의 서브트리를 순회할 수 있다면
 *      전체 트리를 순회할 수 있음.
 *      전위순회 : root-->left-->right
 *      중위순회 : left-->root-->right
 *      후위순회 : left-->right-->root
 *
 *      레벨 순회 : 각 노드를 레벨 순으로 검사. 루트노드의 레벨이 1이고, 아래로
 내려갈수록 레벨 증가
 *      큐에 하나라도 노드가 있으면 계속 반복
 *      1. 큐를 초기화
 *      2. 트리의 루트 노드를 큐에 삽입
 *      3. 큐가 공백이 될 때까지 계속 다음을 반복
 *      4. 큐에서 맨 처음에 있는 노드x를 꺼낸다 (dequeue)
 *      5. 노드 x에 대한 NULL 검사. NULL이 아닐 경우,
 *      6. x의 데이터 출력
 *      7. x->left를 순환 호출
 *      8. x->right를 순환 호출
 *  */

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

// 전위순회
void preorder(TNode *node) {
  if (node != NULL) {
    printf("%i \n", node->data);
    preorder(node->left);
    preorder(node->right);
  } else
    printf("NULL\n");
}
// 중위순회
void inorder(TNode *node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%i \n", node->data);
    inorder(node->right);
  } else
    printf("NULL\n");
}

// 후위순회
void postorder(TNode *node) {
  if (node != NULL) {
    postorder(node->left);
    postorder(node->right);
    printf("%i \n", node->data);
  } else
    printf("NULL\n");
}

/* 레벨 순회
 *
 * queue로 구현
 * 큐에 하나라도 노드가 있으면 계속 반복.
 * 노드를 꺼내어 방문한 다음, 그 노드의 자식 노드를 큐에 삽입하는 것이
 * 한번의 반복.*/

/* create queue */
typedef TNode *element;
typedef struct QueueNode {
  element data;
  struct QueueNode *link;
} QNode;

typedef struct {
  QNode *front, *rear;
} LinkedListQueue;

LinkedListQueue *createQueue() {
  // ?? malloc 안 하면 에러난다.
  LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

bool isEmpty(LinkedListQueue *LQ) { return (LQ->front == NULL); }

void enqueue(LinkedListQueue *LQ, element item) {
  // dynamic allocation
  QNode *newNode = (QNode *)malloc(sizeof(QNode));

  // initialize
  newNode->data = item;
  newNode->link = NULL;
  // 조건 : 공백일 경우와 아닌 경우
  if (isEmpty(LQ)) {
    LQ->front = newNode;
    LQ->rear = newNode;
  } else {
    // 순서 중요
    LQ->rear->link = newNode;
    LQ->rear = newNode;
  }
}

element dequeue(LinkedListQueue *LQ) {
  // pointer old 생성
  QNode *oldNode = LQ->front;

  // 조건 : 공백일 경우와 아닐 경우
  if (isEmpty(LQ)) {
    printf("empty!");
    exit(1);
  }
  element item = LQ->front->data;

  // front가 뒷 노드를 가리키도록
  LQ->front = LQ->front->link;
  // 큐가 공백이 된 경우 rear=NULL  --> front=rear=NULL (공백상태)
  if (LQ->front == NULL) {
    LQ->rear = NULL;
  }

  free(oldNode);
  return item;
}

// 출력
void printQueue(LinkedListQueue *LQ) {
  printf("\nfront ");
  for (QNode *p = LQ->front; p != NULL; p = p->link) {
    // 큐 노드를 갖는 트리의 노드!
    printf(" ---> [ [%p | %i | %p] | %p ]", p->data->left, p->data->data,
           p->data->right, p->link);
    if (p == LQ->rear)
      printf(" <-- rear\n");
  }
}

// 레벨 순회
void levelorder(TNode *node) {
  // 큐 생성
  LinkedListQueue *Q = createQueue();

  if (!node)
    return;

  // 루트 노드 삽입
  enqueue(Q, node);

  // 큐가 공백상태일 때까지 반복
  while (!isEmpty(Q)) {
    printQueue(Q);
    // dequeue한 뒤의 반환값(트리의 한 노드)를 할당
    // !! 맨 왼쪽부터 꺼낸다는 큐의 성질.
    node = dequeue(Q);
    // 방문
    printf("dequeue : %i\t enqueue : ", node->data);

    // NULL이 아닌 한, 왼쪽 오른쪽 자식 노드를 enqueue.
    if (node->left != NULL){
      printf("%i ", node->left->data);
      enqueue(Q, node->left);
    }
      if (node->right != NULL){
      printf("%i ", node->right->data);
      enqueue(Q, node->right);

    }
      printf("\n");
  }
}

/* 노드 개수 세기 & 높이 구하기
 * 둘 다 후위순회! */
int getCount(TNode *node){
    int count = 0;
    // 단말 노드의 경우 0 + 0 + 1(자신) = 1
    // 비단말 노드의 경우 왼쪽자식 + 오른쪽 자식 + 1 (자신)
    if (node !=NULL)
        count = getCount(node->left) + getCount(node->right) + 1;
    
    return count;
}

int max(int x,int y){
    return ( (x>y) ? x : y );
}
int getHeight(TNode *node){ 
    int height = 0;
    // 단말 노드의 경우 0 + 0 + 1(자신) = 1
    // 비단말 노드의 경우 왼쪽자식과 오른쪽자식 중 최대값 + 1(자신)
    if (node !=NULL){
        height = max(getHeight(node->left), getHeight(node->right)) + 1;
        printf("height=%i\n", height);
    }

    return height;
}


int main() {
  TNode *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9;

  n7 = createNode(70, NULL, NULL);
  n6 = createNode(60, NULL, NULL);
  n5 = createNode(50, NULL, NULL);
  n4 = createNode(40, NULL, NULL);
  n3 = createNode(30, n6, n7);
  n2 = createNode(20, n4, n5);
  n1 = createNode(10, n2, n3);

    printf("\n 전위순회 \n\n");
  preorder(n1);
  printf("\n 중위순회 \n\n");
  inorder(n1);
  printf("\n 후위순회 \n\n");
  postorder(n1);
  printf("\n 레벨순회 n\n");
  levelorder(n1);

  getHeight(n1);
}
