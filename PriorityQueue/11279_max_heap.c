/*
 * 널리 잘 알려진 자료구조 중 최대 힙이 있다. 최대 힙을 이용하여 다음과 같은
연산을 지원하는 프로그램을 작성하시오.

배열에 자연수 x를 넣는다.
배열에서 가장 큰 값을 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.

입력
첫째 줄에 연산의 개수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 연산에
대한 정보를 나타내는 정수 x가 주어진다. 만약 x가 자연수라면 배열에 x라는 값을
넣는(추가하는) 연산이고, x가 0이라면 배열에서 가장 큰 값을 출력하고 그 값을
배열에서 제거하는 경우이다. 입력되는 자연수는 2^31보다 작다.

출력
입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 가장
큰 값을 출력하라고 한 경우에는 0을 출력하면 된다.

*/
/*
# 문제접근
말 그대로 최대 힙을 구현하는 문제.
어차피 배열이 표준 구현 방법이라 맘 편하네.
입력되는 자연수의 범위를 주의하면 될 듯.
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
     printf("[");
    for (int i=1; i<size+1; i++){
        printf("%i ", heap[i]);
    }
    printf("]\n");
    printf("size=%i\n", size);

  }
}
