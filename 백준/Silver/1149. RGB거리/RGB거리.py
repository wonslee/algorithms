# 11:10 ~
# 시간 제한 0.5초, N =1000. O(N^2)까지는 가능

# 인접한 칸끼리는 다른 색을 칠해야 함.
# 앞 놈과 다른 색깔 && 최대한 비용이 싼 색깔

# 그리디 방식으론 절대 안 됨 (예제 입력 5)
# 모든 경우의 수를 다 구하기 -> 2^1000... 시간 제한상 절대 안 됨

# 방법1. DP + 그리디
# 초기값: d[0] = min(matrix[0])
# 점화식: d[i] = d[i-1] + min( d[i-1]에서 고르지 않은 색깔 2개  )


# 방법2. 미리 비용에 따라 정렬 ->
# 매트릭스 초기화할 때부터 정렬해서 넣을 순 있겠다. r,g,b
# 나중에 해당 값을 찾아서 더해주면 됨.

# 방법3. 2차원 DP
# 점화식: d[i][j] = i번째 집을 j색으로 칠했을 때 그때까지의 총 비용(0,1,2 = r,g,b)
# DP에서 꽤 중요한 유형인듯. 모든 경우의 수를 구할 수 있는데 시간 복잡도가 O(N)

import sys

read = sys.stdin.readline
COLOR_KIND = 3

# input
N = int(input())
rgb_matrix = [[] for _ in range(N)]
result = 0

# init
# 2차원 배열로 저장할까? 아니면 딕셔너리?
for i in range(N):
    r, g, b = map(int, read().split())
    rgb_matrix[i].extend([r, g, b])

# main
d = [[0 for _ in range(COLOR_KIND)] for _ in range(N)]  # 2차원 DP 배열
for i in range(COLOR_KIND):  # 초기값: 1번째 집에 방문한 모든 경우의 수
    d[0][i] = rgb_matrix[0][i]

for i in range(1, N):
    for c in range(COLOR_KIND):
        prev = d[i-1].copy()
        prev.pop(c)     # 이전에 선택된 색깔 제외
        d[i][c] = min(prev) + rgb_matrix[i][c]
        
        # next_color = (c + 1) % COLOR_KIND
        # next_next_color = (c + 2) % COLOR_KIND
        # d[i][c] = min(d[i-1][next_color], d[i-1][next_next_color]) + rgb_matrix[i][c]


print(min(d[-1]))

