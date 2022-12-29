/*
struct쓰지 말아보자. 정수(우선순위)만 담으면 된다.
!! 핵심 로직은 결국 insert와 delete 안에 있다.
insert에선 삽입하려는 노드보다 우선순위가 낮은 위의 노드들을 끌어내리고 최종 목표 index에 삽입.
delete에선 일단 삭제한 뒤 막내 노드와 비교,
막내 노드보다 우선순위가 높은 밑의 노드들을 끌어올리고 최종 목표 index에 삽입.

insert(num): heap에 num을 삽입.
맨 처음엔 막내 자리에 넣었다가, 반복문을 통해 매번 직속 부모와 비교해가면서
올려보낸다. 이는 heap tree의 성질을 만족시키기 위한 과정. (사실상 직속 부모를
한칸씩 끌어내리다가, 최종 index가 정해지면 거기에 삽입)

delete(): heap의 루트 노드를 삭제 및 출력.
맨 처음엔 막내 노드를 루트에 앉히고, 반복문을 통해 매번 직속 자식(둘 중 더 큰
자식)과 비교해가면서 내려보낸다. (사실상 직속 자식을 한칸씩 올리다가, 최종
index가 정해지면 거기에 삽입)
*/
#include <stdio.h>

int heap[100000];
int size = 0;

void insert(int newbie) {
  // 목표 index는 일단 마지막 index에서 시작
  int target = ++size;

  // loop: 목표 index를 올리면서 우선순위 낮은 부모 노드들을 끌어내린다
  while ((target != 1) && newbie > heap[target / 2]) {
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
    // 두 자식 중 더 큰 놈 고르기
    if (child < size && heap[child] < heap[child + 1])
      child++;
    // 새로 뽑힌 노드가 자식보다 크다면, 힙 트리 조건 충족이므로 끝.
    if (temp >= heap[child])
      break;
    // 자식보다 작다면, 자식을 한 레벨씩 올린다. 두 index는 한 레벨씩 내린다.
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

