# DFS BFS 기본 문제

import sys
from collections import deque

read = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

# 입력
N, M, V = map(int, read().split())

# 그래프 정의
adj_list = [[] for _ in range(N + 1)]
visited = [False for _ in range(N + 1)]
stack = deque()
queue = deque()

# 간선 입력
for _ in range(M):
    x, y = map(int, read().split())
    adj_list[x].append(y)
    adj_list[y].append(x)

# 오름차순으로 인접 노드 방문하기 위한 정렬
for i in range(N + 1):
    adj_list[i].sort()


# DFS
def dfs(node):
    print(node, end=' ')
    visited[node] = True

    for adj in adj_list[node]:
        if not visited[adj]:
            dfs(adj)

dfs(V)
print()

visited = [False for _ in range(N + 1)]  # 방문 기록 초기화


# BFS
# queue가 비지 않는 동안
# 1. node <- dequeue
# 2. 인접한 노드들을 모두 enqueue
queue.appendleft(V)
visited[V] = True

while queue:
    node = queue.pop()
    print(node, end=' ')

    for adj in adj_list[node]:
        if not visited[adj]:
            queue.appendleft(adj)
            visited[adj] = True

