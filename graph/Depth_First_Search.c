/* DFS 
 * 
 * 무방향 그래프 구현
 * */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 50
#define SIZE 8

// graph
typedef struct {
  int n; // 정점의 개수
  int matrix[MAX_VERTEX][MAX_VERTEX]; 
} Graph;
// 방문된 정점들의 리스트
bool visited[MAX_VERTEX];

void init(Graph *g) {
  for (int i = 0; i < MAX_VERTEX; i++)
    for (int j = 0; j < MAX_VERTEX; j++)
      g->matrix[i][j] = 0;
}
// insert_vertex
void insert_vertex(Graph *g, int data) {
  if (g->n + 1 > MAX_VERTEX) {
    fprintf(stderr, "정점 개수 초과");
    return;
  }
  (g->n)++;
}
// insert edge
void insert_edge(Graph *g, int start, int end) {
  if (start >= g->n || end >= g->n)
    fprintf(stderr, "정점 번호 오류");

  g->matrix[start][end] = 1;
  g->matrix[end][start] = 1;
}

// 깊이 우선 탐색
void dfs(Graph *g, int v) {
  visited[v] = true;
  printf("\nvisiting... ");
  // 인접 정점 탐색 (정점의 개수 n만큼 반복)
  // v : 행(정점), w : 열
  // w가 0부터 점점 올라가는 순서므로 자연스럽게 오름차순스럽게 된다.
  for (int w = 0; w < g->n; w++){
    printf("%i-%i ", v,w);
      // 현재 정점에 대해 인접 정점(간선 v-w)이 있고 방문된 적 없다면, 해당 열에 대해서 dfs 호출
    if (g->matrix[v][w] && !visited[w]){
        printf("#");
      dfs(g, w);
    }
  }
}

void print_matrix(Graph *g) {
  for (int i = 0; i < g->n; i++) {
    for (int j = 0; j < g->n; j++)
      printf("%2d ", g->matrix[i][j]);
    printf("\n");
  }
}

int main() {
  Graph *myG = (Graph *)malloc(sizeof(Graph));
  init(myG);

  for (int i = 0; i < SIZE; i++)
    insert_vertex(myG, i);

  insert_edge(myG, 0, 1);
  insert_edge(myG, 0, 2);
  insert_edge(myG, 0, 3);
  insert_edge(myG, 1, 2);
  insert_edge(myG, 2, 3);

  print_matrix(myG);

  dfs(myG, 0);
}
