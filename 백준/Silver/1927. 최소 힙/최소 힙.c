/*
# 문제접근
말 그대로 최소 힙을 구현하는 문제.
최대 힙에서, 비교의 방향만 달라진 것.
*/
#include <stdio.h>

int heap[100000];
int size = 0;

void insert(int newbie) {
  // 목표 index는 일단 마지막 index에서 시작
  int target = ++size;

  // loop: 목표 index를 올리면서 높은 부모 노드들을 끌어내린다
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
  }
}