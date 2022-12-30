#include <stdio.h>

int heap[100000];
int size = 0;
// abs: 절댓값 반환
int abs(int x) { return (x < 0) ? -x : x; }

void insert(int item) {
  int target = ++size;
  // 루트노드까지 목표 index를 증가시키면서 절댓값 힙 조건에 안 맞는 윗 노드들을
  // 끌어내린다
  while (target != 1) {
    // 윗노드의 절댓값이 작거나,
    // 절댓값은 같은데 윗노드가 더 작거나 같은 경우, 조건 충족
    if (abs(item) > abs(heap[target / 2]) ||
        (abs(item) == abs(heap[target / 2]) && item >= heap[target / 2]))
      break;
    // 아니면 끌어내림
    heap[target] = heap[target / 2];
    target /= 2;
  }
  heap[target] = item;
}

void delete () {
  int parent = 1, child = 2;
  int dead = heap[parent];
  int temp = heap[size--];

  while (child <= size) {
    // 두 자식중 절댓값 더 작거나, 절댓값은 같은데 값이 더 작은 놈 고르기
    if (child < size && (abs(heap[child]) > abs(heap[child + 1]) ||
                         (abs(heap[child]) == abs(heap[child + 1]) &&
                          heap[child] > heap[child + 1]))) 
        child++;
    // 새로 뽑힌 노드가 자식보다 절댓값이 작거나,
    // 절댓값은 같은데 아랫노드보다 값이 작다면, 힙 조건 충족
    if (abs(temp) < abs(heap[child]) || ( abs(temp)==abs(heap[child]) && temp < heap[child]  )  )
      break;
    // 아랫노드의 절댓값이 더 작다면, 아랫 노드를 한 레벨씩 올린다.
    heap[parent] = heap[child];
    parent = child;
    child *= 2;
  }

  heap[parent] = temp;
  printf("%i\n", dead);
}

int main() {
  int n;
  scanf("%i", &n);
  while (n--) {
    int input;
    scanf("%i", &input);

    if (input == 0) {
      if (size > 0)
        delete ();
      else
        printf("%i\n", 0);
    } else
      insert(input);
  }
}