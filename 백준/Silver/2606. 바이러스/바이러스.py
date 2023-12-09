# 그래프 순회 기본 문제
# BFS로 풀어보자.

import sys
from collections import deque

read = sys.stdin.readline

# input
N = int(input())
M = int(input())


# graph
graph = [[] for _ in range(N+1)]
queue = deque()
visited = [False for _ in range(N+1)]
vis_count = 0

# input
for _ in range(M):
    x, y = map(int, read().split())
    graph[x].append(y)
    graph[y].append(x)

# sort for traversal
for i in range(N+1):
    graph[i].sort()


def bfs(initial_node):
    queue.append(initial_node)
    visited[initial_node] = True
    global vis_count

    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                vis_count += 1
                queue.append(neighbor)



bfs(1)
print(vis_count)