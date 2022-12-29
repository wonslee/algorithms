#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 50

typedef struct G {
  int vertex; // 정점
  struct G *link;
} GraphNode;

int n;                              // number of vertex
GraphNode *adj_list[MAX_VERTEX]; // 각 정점들의 리스트

// insert_vertex
void insert_vertex(int v) {
  if (n + 1 > MAX_VERTEX)
    fprintf(stderr, "정점 개수 초과");
  else
    n++;
}
// insert_edge
void insert_edge(int index, int v) {
  GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
  node->vertex = v;
  // 갈아끼우는 부분
  node->link = adj_list[index];

  // 배열에 저장
  adj_list[index] = node;
    printf("[ %i | %p]\n", node->vertex, node->link);

}

void print_adj_list() {
  for (int i = 0; i < n; i++) {
    printf("list of vertex %i %p\n", i, &adj_list[i]->link);
    for (GraphNode *p = adj_list[i]; p != NULL; p = p->link)
      printf("-> %i | %p", p->vertex, p->link);
    printf("\n");
  }
}

int main() {
  // initialize graph
  n = 0;
  for (int v = 0; v < MAX_VERTEX; v++)
    adj_list[v] = NULL;

  for (int i = 0; i < 4; i++)
    insert_vertex(i);

  // 무방향 그래프는 대칭도 다 넣어줘야 함..
  insert_edge(0, 1);
  insert_edge(1, 0);

  print_adj_list();

  insert_edge(0, 2);
  insert_edge(2, 0);

  print_adj_list();

  insert_edge(0, 3);
  insert_edge(3, 0);

  insert_edge(1, 2);
  insert_edge(2, 1);

  insert_edge(2, 3);
  insert_edge(3, 2);

  print_adj_list();
}
