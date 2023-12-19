# X 경우의 수 문제
# n = 500, 각 층마다 둘중 하나를 고르지만 2^n ~ n^n에 가까움. => 브루트포스로는 어려움
# RGB 거리 문제처럼 DP를 이용해서 경우의 수들을 저장해가는 문제로 보임

# DP 문제
# 점화식: d[x][y] = MAX( d[x-1][y-1], d[x][y-1] ) + d[x][y]
# 삼각형 구현: 2차원 배열로 구현

# 1차원 배열로 구현하면 어떨까? 1층은 1개, 2층은 2개, 3층은 3개 ...
# r층이라고 할 때 대각선 아래 왼쪽은 현재 인덱스 +r, 오른쪽은 현재 인덱스 +r+1
# 대각선 위 왼쪽은 -r, 오른쪽은 -(r-1)
# 문제: 변두리에 있는 놈들에 대한 분기처리가 필요함. 1,2,4,7,11,... 1,3,6,10,...


# DP:


import sys

read = sys.stdin.readline

# init
MAX_TRIANGLE = 500
d = [[0 for _ in range(MAX_TRIANGLE)] for _ in range(MAX_TRIANGLE)]  # 500*500 2차원 배열 -> 1백만 byte = 1MB

# input
N = int(input())
for i in range(N):
    row = list(map(int, read().split()))
    for j, num in enumerate(row):
        d[i][j] = num

# main

for y in range(1, N):
    for x in range(0, y + 1):
        if x == 0:  # 맨 왼쪽
            d[y][x] += d[y - 1][x]
        elif x == y:  # 맨 오른쪽
            d[y][x] += d[y - 1][x - 1]
        else:
            d[y][x] += max(d[y - 1][x - 1], d[y - 1][x])

print(max(d[N - 1]))
