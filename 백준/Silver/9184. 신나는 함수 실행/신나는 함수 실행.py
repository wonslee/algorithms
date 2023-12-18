# DP 기초

import sys

read = sys.stdin.readline
MAX_N = 50

# init
d = [[[0 for _ in range(MAX_N)] for _ in range(MAX_N)] for _ in range(MAX_N)]

# DP
# 모든 경우의 수 구함. 20^3 = 8000
for a in range(MAX_N):
    for b in range(MAX_N):
        for c in range(MAX_N):
            if a == 0 or b == 0 or c == 0:
                d[a][b][c] = 1
            elif a < b < c:
                d[a][b][c] = d[a][b][c - 1] + d[a][b - 1][c - 1] - d[a][b - 1][c]
            else:
                d[a][b][c] = d[a - 1][b][c] + d[a - 1][b - 1][c] + d[a - 1][b][c - 1] - d[a - 1][b - 1][c - 1]

while True:
    # input
    A, B, C = map(int, read().split())
    if A == -1 and B == -1 and C == -1:
        break

    print("w({}, {}, {}) = ".format(A, B, C), end='')
    if A <= 0 or B <= 0 or C <= 0:
        print(d[0][0][0])
    elif A > 20 or B > 20 or C > 20:
        print(d[20][20][20])
    else:
        print(d[A][B][C])

