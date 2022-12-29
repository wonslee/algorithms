#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100
#define INFINITE 1000L

/* union-find
 * 트리로 집합 표현
 *
 * 1차원 배열로 구현 가능.
 * 배열은 부모 노드의 인덱스를 저장하고, 값이 -1이면 부모 노드가 없는 상태.
 *
 * 두 노드가 같은 트리에 있습니까?에 대해서 같은 루트 노드를 가리키도록.
 * */
// 부모 노드들
int parent[MAX_VERTEX];

void set_init(int n) {
  for (int i = 0; i < n; i++)
    parent[i] = -1;
}
int set_find(int curr) {
  while (parent[curr] != -1) // root될때까지 반복
    curr = parent[curr];
  return curr; // root 반환
}

void set_print(int curr) {
  printf("{ %i ", curr);
  while (parent[curr] != -1) { 
    curr = parent[curr];
    printf("%i ", curr);
  }
  printf("}\n");
}
void print_parent(){

    printf("[ ");
    for (int i=0; i<7; i++)
        printf("%i(%i) ", i, parent[i]);
    printf("]\n");
}

void set_union(int a, int b) {
  int root_a = set_find(a);
  int root_b = set_find(b);

  if (root_a != root_b)
    parent[root_a] = root_b; // 집합 합치기
}

// Graph ADT
struct Edge {
  int start, end, weight;
};

typedef struct {
  int n_edge;
  int n_vertex;
  struct Edge edge[2 * MAX_VERTEX];
} Graph;
// 초기화
void graph_init(Graph *g) {
  g->n_edge = g->n_vertex = 0;

  for (int i = 0; i < 2 * MAX_VERTEX; i++) {
    g->edge[i].start = 0;
    g->edge[i].end = 0;
    g->edge[i].weight = INFINITE;
  }
}
// 간선 삽입
void insert_edge(Graph *g, int start, int end, int weight) {
  g->edge[g->n_edge].start = start;
  g->edge[g->n_edge].end = end;
  g->edge[g->n_edge].weight = weight;
  g->n_edge++;
}
// for qsort
int compare(const void *a, const void *b) {
  struct Edge *x = (struct Edge *)a;
  struct Edge *y = (struct Edge *)b;
  return (x->weight - y->weight);
}

/* kruskal
간선을 기반으로 오름차순으로 정렬한 뒤,
집합에 집어넣는 과정을 반복하는 탐욕 알고리즘.

1. 먼저 그래프의 간선들을 가중치의 오름차순으로 정렬.
2. 정렬된 간선들의 리스트(q->edge)에서 사이클을 형성하지 않는 간선을 찾아서 현재의 MST 집합에 추가
    이를 위해서 set_find, set_union 등의 로직이 필요
*/ 
void kruskal(Graph *g) {
  int edge_count = 0; // 선택된 간선들 카운트
  int uset, vset;     // 정점 u와 정점 v의 집합 번호
  struct Edge e;

  set_init(g->n_vertex); // 집합 초기화. 개수는 정점의 개수만큼
  // qsort : 모든 간선들을 가중치에 대해 오름차순으로 정렬
  qsort(g->edge, g->n_edge, sizeof(struct Edge), compare);

  // loop(간선 수 < n-1): 첫번째부터 
  for (int i=0; edge_count < (g->n_vertex - 1); i++) { 
    e = g->edge[i];

    print_parent();

    uset = set_find(e.start);
    vset = set_find(e.end);

    if (uset != vset) { // 서로 속한 집합이 다를 경우 해당 간선 선택
      printf("edge (%i-%i) 가중치: %i\n", e.start, e.end, e.weight);
      edge_count++;
      set_union(uset, vset); // 두 집합 합치기 시도
    }
  }
  print_parent();
}



int main() {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  graph_init(g);
  g->n_vertex = 7;

  insert_edge(g, 0, 1, 29);
  insert_edge(g, 1, 2, 16);
  insert_edge(g, 2, 3, 12);
  insert_edge(g, 3, 4, 22);
  insert_edge(g, 4, 5, 27);
  insert_edge(g, 5, 0, 10);
  insert_edge(g, 6, 1, 15);
  insert_edge(g, 6, 3, 18);
  insert_edge(g, 6, 4, 25);

  kruskal(g);
  free(g);
}
