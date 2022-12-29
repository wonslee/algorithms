/* priority queue heap ADT
 * 히프의 효율은 O(log2n)로, 우선순위 큐에서 상당히 유리
 * 여기선 최대히프만 다루자.
 *
 * 히프는 완전 이진 트리.
 * 부모 노드의 키 값이 자식 노드의 키 값보다 항상 크거나 같다.
 * 이진탐색트리와 달리 노드간의 중복된 값을 허용한다.
 * 왼쪽 자식의 index = parent index * 2
 * 오른쪽 자식의 index = parent index * 2 + 1
 * 부모 노드의 index = 자식 노드의 index / 2
 * 여기선 index를 1부터 시작. 루트 노드의 index는 1
 *
 * ADT 확실히 하자.
 * 우선순위 큐를 구현하는 여러 방법중에서 힙을 쓰는거.
 * 힙 또한 추상적 개념이다. ADT를 위한 ADT.
 * 정의상 완전이진트리이고, 이는 배열로 구현하는 것이 표준.
 *
 * data
 * 히프는 1차원 배열로 표현될 수 있다. (index 0은 비어있음)
 * 각 원소의 1차원 배열과 heap_size를 묶은 구조체가 heap가 된다.
 *
 * operation
 * 삽입
 * 1. 새로운 노드를 생성
 * 2. 히프의 마지막 노드로 삽입
 * 3. 히프 트리의 성질을 만족시키는 과정..
 *      새로운 노드를 부모 노드들과 반복 교환(재구성)
 *
 * 삭제
 * 1. 최대 히프이므로 삭제는 최대값을 갖는 요소
 * 최대 히프에서 최대값은 루트노드이므로 루트노드를 삭제.
 * 2. 히프 트리의 성질을 만족시키기 위해 재구성.
 *      자식 노드들과 반복 비교, 교환
 * */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEGNTH 200

// type definition
typedef struct {
  int priority;
  // other values
} element;

typedef struct {
  element heap[MAX_LEGNTH];
  int size;
} Heap;

void printHeap(Heap *H){
    printf("[ ");
    // heap의 0번째는 편의상 안 쓰므로 1부터.
    for (int i=1; i<H->size +1; i++){
        printf("%i ", H->heap[i].priority);
    }
    printf("]\n");
}

// insert
void insert_max_heap(Heap *H, element item) {
    printf("size=%i\n", H->size);
  // 새로 넣을 노드의 목표 index는 일단 마지막 index로 시작
  int target = ++(H->size);

      printf("item.priority = %i\t H->heap[i / 2].priority = %i\n", item.priority , H->heap[target / 2].priority);
  // 부모 노드와 비교하면서 올라가는 과정
  while ((target != 1) && item.priority > H->heap[target/ 2].priority) {
    // 사실상 부모 노드들을 밑으로 끌어내리기만 함.
    H->heap[target] = H->heap[target/ 2];
    // 부모 노드의 index로 이동
    target/= 2;
  }

        printf("target=%i\n", target);
  // 최종 index에 새로운 노드 삽입
  H->heap[target] = item;
}

element delete_max_heap(Heap *H) {
  int parent = 1, child = 2;
  element item, temp;

  // 삭제된 루트 노드(index=1)와 새로 뽑힌 막내 노드
  item = H->heap[parent];
  temp = H->heap[H->size--];

  while (child <= H->size) {
    // 현재 노드의 양쪽 자식노드 중 더 큰 자식노드를 찾는다.
    // 앞의 조건은 꼭 필요한건가?
    if (child < H->size &&
        H->heap[child].priority < H->heap[child + 1].priority)
      child++;
    // 핵심 분기점: 새로 뽑힌 노드가 힙의 조건을 충족하는지
    if (temp.priority >= H->heap[child].priority)
      break;
    // 한 단계 아래로 이동.
    else {
      // 사실상 자식 노드들을 위로 끌어올리기만 함.
      H->heap[parent] = H->heap[child];
      // 두 index를 밑으로 한 레벨 내림.
      // child가 heap size를 넘지 않는한 계속 반복하도록 함.
      parent = child;
      child *= 2;
    }
  }
  // 최종 index에다 새로 뽑혔던 막내 노드 삽입
  H->heap[parent] = temp;
  return item;
}

int main() {
  element e1 = {10}, e2 = {5}, e3 = {30};
  // array of structs
  element els[8] = { {10}, {19}, {3}, {1000}, {-1}, {56}, {109}, {33} };
  Heap *myH = (Heap *)malloc(sizeof(Heap));
  myH->size = 0;

  for (int i=0; i<8; i++){
    insert_max_heap(myH, els[i]);
    printHeap(myH);
  }

    for (int i=0; i<8; i++){
    delete_max_heap(myH);
    printHeap(myH);
  }
 
  free(myH);
}
