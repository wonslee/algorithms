# direction graph traversal
# 방향 그래프 문제. B -> A 관계를 설정해야 한다.
import sys
from collections import deque

# input
read = sys.stdin.readline
N, M = map(int, read().split())

# graph
adj_list = [[] for _ in range(N+1)]
vis_rank = [0 for _ in range(N+1)]
q = deque()

# input
for _ in range(M):
    x, y = map(int, read().split())
    adj_list[y].append(x)


# BFS
def bfs(initial_node):
    q.append(initial_node)
    visited = [False for _ in range(N + 1)]     # 방문 리스트 초기화
    visited[initial_node] = True

    while q:
        node = q.popleft()
        for adj in adj_list[node]:
            if not visited[adj]:
                visited[adj] = True
                vis_rank[initial_node] += 1
                q.appendleft(adj)


for i in range(1, N+1):
    bfs(i)

mx = max(vis_rank)

for i in range(1, N+1):
    if vis_rank[i] == mx:
        print(i, end=' ')






