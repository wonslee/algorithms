#include <stdio.h>
#define MAX_VERTEX 50

int n = 4;                          // number of vertex
int matrix[MAX_VERTEX][MAX_VERTEX]; // 최소 n * n 크기의 matrix

void init() {
  for (int i = 0; i < MAX_VERTEX; i++)
    for (int j = 0; j < MAX_VERTEX; j++)
      matrix[i][j] = 0;
}
// insert_vertex
void insert_vertex(int data) {
  if (n + 1 > MAX_VERTEX) {
    fprintf(stderr, "정점 개수 초과");
    return;
  }
  n++;
}
// insert edge
void insert_edge(int start, int end) {
  if (start >= n || end >= n)
    fprintf(stderr, "정점 번호 오류");

  matrix[start][end] = 1;
  matrix[end][start] = 1;
}

void print_matrix() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%2d ", matrix[i][j]);
    printf("\n");
  }
}

int main() {
  init();

  for (int i = 0; i < 4; i++)
    insert_vertex(i);

  insert_edge(0, 1);
  insert_edge(0, 2);
  insert_edge(0, 3);
  insert_edge(1, 2);
  insert_edge(2, 3);

  print_matrix();
}
