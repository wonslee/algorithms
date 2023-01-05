/* BFS
 *
 * 무방향 그래프 구현
 * */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 50
#define MAX_QUEUE_SIZE 10

void error(const char *message) {
  fprintf(stderr, "%s\n", message);
  exit(1);
}
// definition: queue (circular)
int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

bool isEmpty() { return (front == rear); }
bool isFull() { return ((rear + 1) % MAX_QUEUE_SIZE == front); }
void enqueue(int v) {
  if (isFull())
    error("포화상태!");
  rear = (rear + 1) % MAX_QUEUE_SIZE;
  queue[rear] = v;
}
int dequeue() {
  if (isEmpty())
    error("공백상태!");
  front = (front + 1) % MAX_QUEUE_SIZE;
  return (queue[front]);
}
void printQueue() {
  printf("[ ");
  for (int i = front + 1; i <= rear; i++)
    printf("%i ", queue[i]);
  printf("]\n");
}

// definition: graph
typedef struct {
  int n; // 정점의 개수
  int matrix[MAX_VERTEX][MAX_VERTEX];
} Graph;
// 방문된 정점들의 리스트
bool visited[MAX_VERTEX];

void init() {
  for (int i = 0; i < MAX_VERTEX; i++)
    visited[i] = false;

  front = -1;
  rear = -1;
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

/* breath first search
 * dequeue한 순서가 곧 방문의 순서
 *
 * 1. 방문 표시
 * 2. enqueue
 * 3. loop(정점 갯수):
 * 3-1. dequeue()한 놈을 기준으로 첨부터 끝까지 loop:
 * 3-1-1. 간선이 존재하고 아직 방문 안 된 경우, 방문 표시 후 enqueue
 * 3-1-2. 아닐 경우, 패스.
 * */
void bfs(Graph *g, int v) {
  printf("\nbfs :\n");
  visited[v] = true;

  enqueue(v);

  // queue가 공백 될 때까지 반복
  while (!isEmpty()) {

    v = dequeue(); // 정점 꺼내기
    /* printf("\nvisiting %i... \n", v); */
    printf("%i -> ", v);

    for (int w = 0; w < g->n; w++) {
      /* printf("%i-%i ", v, w); */
      // 간선이 존재하고 아직 방문 안 된 경우
      if (g->matrix[v][w] && !visited[w]) {
        visited[w] = true; // 방문 표시
        enqueue(w);
      }
      /* printQueue(); */
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

  for (int i = 0; i < 6; i++)
    insert_vertex(myG, i);

  insert_edge(myG, 0, 2);
  insert_edge(myG, 2, 1);
  insert_edge(myG, 2, 3);
  insert_edge(myG, 0, 4);
  insert_edge(myG, 4, 5);
  insert_edge(myG, 1, 5);

  print_matrix(myG);

  for (int i = 0; i < 6; i++) {
    bfs(myG, i);
    init();
  }
}
