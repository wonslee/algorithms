/*
# 문제접근
말 그대로 최소 힙을 구현하는 문제.
최대 힙에서, 비교의 방향만 달라진 것.

struct쓰지 말아보자. 자연수만 담으면 된다.

insert(num): heap에 num을 삽입.
맨 처음엔 막내 자리에 넣었다가, 반복문을 통해 매번 직속 부모와 비교해가면서
올려보낸다. 이는 heap tree의 성질을 만족시키기 위한 과정. (사실상 직속 부모를
한칸씩 끌어내리다가, 최종 index가 정해지면 거기에 삽입)

delete(): heap의 루트 노드를 삭제 및 출력.
맨 처음엔 막내 노드를 루트에 앉히고, 반복문을 통해 매번 직속 자식(둘 중 더 큰
자식)과 비교해가면서 내려보낸다. (사실상 직속 자식을 한칸씩 올리다가, 최종
index가 정해지면 거기에 삽입)

1. 입력: 연산의 개수 N
2. loop: N만큼 반복.
    입력: 정수 x
    조건: x==0일 경우 delete, x>0일 경우 insert

*/
#include <stdio.h>

int heap[100000];
int size = 0;

void insert(int newbie) {
  // 목표 index는 일단 마지막 index에서 시작
  int target = ++size;

  // loop: 목표 index를 올리면서 우선순위 낮은 부모 노드들을 끌어내린다
  while ((target != 1) && newbie < heap[target / 2]) {
    heap[target] = heap[target / 2];
    target /= 2;
  }
  heap[target] = newbie;
}

void delete () {
  // 처음의 부모 index와 자식 index
  int parent = 1, child = 2;
  // 처음의 루트 노드와 새로 뽑힌 막내 노드
  int dead = heap[parent];
  int temp = heap[size--];

  while (child <= size) {
    // 두 자식 중 더 작은 놈 고르기
    if (child < size && heap[child] > heap[child + 1])
      child++;
    // 새로 뽑힌 노드가 자식보다 작거나 같다면, 힙 트리 조건 충족이므로 끝.
    if (temp <= heap[child])
      break;
    // 자식이 더 작다면, 자식을 한 레벨씩 올린다. 두 index는 한 레벨씩 내린다.
    else {
      heap[parent] = heap[child];
      parent = child;
      child *= 2;
    }
  }
  heap[parent] = temp;
  printf("%i\n", dead);
}

int main() {
  int n;
  scanf("%i", &n);
  while (n--) {
    int x;
    scanf("%i", &x);
    if (x > 0)
      insert(x);
    else {
      if (size > 0)
        delete ();
      else
        printf("%i\n", 0);
    }

    printf("[ ");
    for (int i=1; i<size+1; i++){
        printf("%i ", heap[i]);
    }
    printf("]\n");
  }
}
