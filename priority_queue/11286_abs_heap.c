/*
 * 절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.

- 배열에 정수 x (x ≠ 0)를 넣는다.
- 배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서
제거한다.
- 프로그램은 처음에 비어있는 배열에서 시작하게 된다.

입력
첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다.
다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다.
x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고,
x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는
경우이다. 입력되는 정수는 -231보다 크고, 231보다 작다.

출력
입력에서 0이 주어진 회수만큼 답을 출력한다.
만약 배열이 비어 있는 경우인데 값을 출력하라고 한 경우에는 0을 출력하면 된다.
*/
/*
# 문제접근
일단 최소 힙. 근데 절댓값으로 평가한다.
값은 일단 음수 양수 정확히 들어가야 한다.
그러나 힙 트리는 절댓값을 기준으로 짜여야 한다.
예를 들어 -100과 1이 있다면 루트 노드는 1이다.
!! 힙 트리는 중복을 허용한다. 그리고 절댓값이니까 -1, 1 이렇게 들어갈 수 있다.
루트 노드에서 -1과 1이 경쟁한다면, 둘의 값을 비교해서 -1을 위로 올려야 한다는
얘기. 그러면 삭제는 간단하다.

1. 데이터 정의 : int heap[100000], size, N, input
2. 함수 정의
abs(int x): x의 절댓값을 반환
insert(int x): x를 힙에 삽입.
일단 new node를 말단에 넣는다.
new node가 삽입될 index를 결정하는게 핵심이다.
loop: 루트노드까지
    윗노드와 절댓값 비교: 끌어내리는 경우의 수는 2가지다.
                    아예 윗노드의 절댓값이 더 큰 경우,
                    절댓값은 같지만 윗노드의 원래 값이 더 큰 경우.
                    --> 밑으로 끌어내리고 target index /= 2
                    나머지는 반복문 과정을 거치지 않는다.
                    --> break
최종 결정된 index에다 node 삽입

delete(): 루트 노드를 삭제, 그 값을 반환. 만약 힙이 비어있다면 0반환.
index 정의. parent, child
막내 노드 정의. 루트 노드로 옮기기
loop: 말단 노드까지
    밑 노드 중 더 작은 애 고르기:
        절댓값 작은 순으로.
        절댓값이 같다면 값이 더 작은 놈을
    밑 노드와 절댓값 비교:
        밑노드 절댓값이 더 작을 경우,
        절댓값은 같지만 아랫노드의 원래 값이 더 작은 경우.
        --> 위로 끌어올리고 parent = 밑노드
index, child = parent *2 크다면 break 같다면 원래값끼리 비교 최종 결정된
index(parent)에다 node 삽입

3. loop: N회
    input에 따라 분기처리. ==0일 경우 insert 호출, 아닐 경우 delete 호출
*/

#include <stdio.h>

int heap[100000];
int size = 0;
// abs: 절댓값 반환
int abs(int x) { return (x < 0) ? -x : x; }
// greater: 절댓값 비교. 절댓값이 같다면 그냥 값끼리 비교
int greater(int a, int b){
    if(abs(a) < abs(b)) return 0;
    else if (abs(a) > abs(b)) return 1;
    else return a>=b;
}

void insert(int item) {
  int target = ++size;
  // 루트노드까지 목표 index를 증가시키면서 절댓값 힙 조건에 안 맞는 윗 노드들을
  // 끌어내린다
  while (target != 1 && greater(heap[target/2], item)) {
    // 끌어내림
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
    if (child < size && greater(heap[child], heap[child+1]) ) 
        child++;
    // 새로 뽑힌 노드가 자식보다 절댓값이 작거나,
    // 절댓값은 같은데 아랫노드보다 값이 작다면, 힙 조건 충족
    if ( greater(heap[child], temp)   )
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
