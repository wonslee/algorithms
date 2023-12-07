# DFS 기본 구현 문제
import sys

sys.setrecursionlimit(10 ** 6)
read = sys.stdin.readline

n, m, r = map(int, read().split())

graph = [[] for _ in range(n+1)]    # 0번째 인덱스는 생략
visited = [0 for _ in range(n+1)]

# m개의 연결된 간선 정보 입력받기
for i in range(m):
    a, b = (map(int, read().split()))
    graph[a].append(b)
    graph[b].append(a)


cnt = 0     # 정점 방문 순서


def dfs(x):
    if visited[x] > 0:
        return

    global cnt
    cnt += 1
    visited[x] = cnt   # 방문 순서 표시

    for num in graph[x]:
        dfs(num)


for i in range(n+1): # 오름차순으로 인접노드 방문하기 위해 정렬
    graph[i].sort()

dfs(r)

for i in range(1, n+1):
    print(visited[i])


