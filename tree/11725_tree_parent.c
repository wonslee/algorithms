/*
 * 루트 없는 트리가 주어진다.
 * 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을
작성하시오.

입력
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다.
둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

출력
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로
출력한다.
*/
/* 문제접근
둘째 줄부터 주어지는 입력은 두 정점의 짝을 뜻하는 거. 순서는 상관 없음.
출력상의 n번 노드는 트리상의 순서가 아닌 그 노드의 숫자값을 뜻함.

왠만하면 binary tree이지 않을까 생각해보긴 하는데 tree로 구현하는게 정석일 것
같긴 하다.

이진 트리라고 가정,
길이 100000의 배열로 구현해보자.
루트 노드의 index를 1이라고 할 때, (배열의 0번째는 비워놓자)
부모 index = 자식 index / 2
왼쪽 자식 index = 부모 index * 2
오른쪽 자식 index = 부모 index * 2 + 1

배열[1] = 1
1. N 입력
2. loop: N 만큼
2-1. x, y 입력
2-2. 둘 중 하나는 배열상에 존재한다. 배열 내 탐색, 존재하는 놈 찾기
2-3. 없던 놈을 자식으로 삽입. 이 때 먼저 들어온 자식이 있는지 검사, 있다면 +1
index로.
3. loop: 2번째 index부터, N-1만큼
3-1. 부모 노드 index상의 값을 출력

궁금한 점
풀이들을 보면 dfs 등 탐색이 나오는데, 이렇게 탐색하면 안되는건가? 
그냥 배열 첫번째 index부터 무식하게 찾기..

*/
#include <stdio.h>

// 0번째는 미사용, 1번째는 1로 고정.
int tree[300009] = {0, 1};

// find: 배열상의 원소의 index 반환, 없다면 0
int find(int arr[], int target) {
  // 0번째가 비어있는 특이한 배열이므로 1부터 100000(index)까지
  for (int i = 1; i <= 300009; i++)
    if (arr[i] == target) return i;
    
  return 0;
}

int main() {
  int n;
  scanf("%i", &n);
  
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%i %i", &x, &y);
    // 둘 중 하나는 무조건 존재
    int x_index = find(tree, x);
    int y_index = find(tree, y);

    if (x_index != 0) {
      if (tree[x_index * 2])
        tree[x_index * 2 + 1] = y;
      else
        tree[x_index * 2] = y;
    } else {
      if (tree[y_index * 2])
        tree[y_index * 2 + 1] = x;
      else
        tree[y_index * 2] = x;
    } 
  }

  // 2 ~ n index까지 탐색
  for (int i = 2; i <= n; i++) {
    int index = find(tree, i);
    int parent = tree[index / 2];
    // 자식이 없는 경우가 있으니 조건문 필요
    if (parent) printf("%i\n", parent);
  }
  return 0;
}
