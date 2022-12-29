/*
 * N개의 정점과 M개의 간선으로 구성된 무방향 그래프(undirected graph)가
주어진다. 정점 번호는 1번부터 N번이고 모든 간선의 가중치는 1이다. 정점 R에서
시작하여 깊이 우선 탐색으로 노드를 방문할 경우 노드의 방문 순서를 출력하자.

깊이 우선 탐색 의사 코드는 다음과 같다. 인접 정점은 오름차순으로 방문한다.

dfs(V, E, R) {  # V : 정점 집합, E : 간선 집합, R : 시작 정점
    visited[R] <- YES;  # 시작 정점 R을 방문 했다고 표시한다.
    for each x ∈ E(R)  # E(R) : 정점 R의 인접 정점 집합.(정점 번호를
오름차순으로 방문한다) if (visited[x] = NO) then dfs(V, E, x);
}
입력
첫째 줄에 정점의 수 N (5 ≤ N ≤ 100,000), 간선의 수 M (1 ≤ M ≤ 200,000), 시작
정점 R (1 ≤ R ≤ N)이 주어진다.

다음 M개 줄에 간선 정보 u v가 주어지며 정점 u와 정점 v의 가중치 1인 양방향
간선을 나타낸다. (1 ≤ u < v ≤ N, u ≠ v) 모든 간선의 (u, v) 쌍의 값은 서로
다르다.

출력
첫째 줄부터 N개의 줄에 정수를 한 개씩 출력한다. i번째 줄에는 정점 i의 방문
순서를 출력한다. 시작 정점의 방문 순서는 1이다. 시작 정점에서 방문할 수 없는
경우 0을 출력한다.


# 문제접근
일반적인 가중치 1 무방향 그래프에 대한 DFS 구현. (오름차순)
graph ADT를 제대로 구현하면 된다.

정점 i의 방문 순서들을 기억하고 있어야 한다.
visited를 응용하면 어떨까 싶다

1. 입력: 정점의 수 N, 간선의 수 M, 시작 정점 R
2. loop(M):
2-1. 입력: u, v
2-2. 양방향 간선 생성. 코드 상으론 두번 넣어줘야 함.
3. dfs(R): 정점 i에 대한 DFS 방문 순서 출력. 시작 정점 R의 방문순서는 1.
방문할 수 없는, 즉 끊어진 노드에 대해선 0 출력

# 구현
## 연산
dfs(int start, int size):
1. 시작 정점에 대한 방문 표시. visited[start] = true
2. loop(m 만큼): 처음부터 끝까지
2-1. v-w간선이 존재하고, 아직 방문되지 않았을 경우 dfs(w)
2-2. 아닐 경우 패스

간선 생성(int u, int v):
adj_matrix의 (u,v)칸을 1로 만든다.

## 데이터
int adj_matrix[MAX_VERTEX][MAX_VERTEX]
int visited[MAX_VERTEX]
int N, M, R
int u, v

# 배운점
내 gcc 컴파일러 문제일 수도 있는데, 100000짜리 2D 배열은 생성하자마자 에러가 생긴다.
그래서 동적 할당 malloc을 이용했다. 사실 calloc에 익숙치 않아서 그랬다.

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 10000

int adj_matrix[MAX_VERTEX][MAX_VERTEX] = {0};
int visited[MAX_VERTEX] = {0};
int count = 0;

// dfs
void dfs( int v, int size) {
// 핵심: 방문 여부뿐만 아니라 몇번째로 방문했는지를 기록
  count++;
  visited[v] = count;

  for (int w = 1; w <= size; w++)
    if (adj_matrix[v][w] && !visited[w])
      dfs(w, size);
}

int main() {
  int n, m, r;
  scanf("%i %i %i", &n, &m, &r);

  // m개 만큼 입력에 따라 간선 생성
  while (m--) {
    int v, w;
    scanf("%i %i", &v, &w);
    // (v,w) 양방향 간선 생성
    adj_matrix[v][w] = 1;
    adj_matrix[w][v] = 1;
  }

  dfs(r, n);

  for (int i=1; i<=n;i++)
      printf("%i\n", visited[i]);
}
