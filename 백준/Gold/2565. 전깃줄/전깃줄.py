# DP LIS
# N = 500

# 카운팅 배열 이용
# (1,8) -> [1] = 1, (2,2) -> [2] = 1, (3,9) -> 2, (4,1)
# ! (A,B)의 합을 구하면 둘이 겹치는지 아닌지 알 수 있을듯.

# '모든 전깃줄이 서로 교차하지 않는다'를 알아내는 방법?
# Ai > Aj && rope[Ai] <= rope[Aj] OR Ai < Aj && rope[Ai] >= rope[Aj]


# d[i] = Ai칸을 갔을 때 지금까지의 선택한 최대값. 선택한 것과 선택 안 한 것의
# e.g. (3,9) -> MAX( (1,8)=1 + 1, (2,2) + 1)
# 안 겹치는 경우 + 1, 겹치는 경우 그때까지의 MAX
# e.g. 4 -> MAX( (1,8)=1 , (2,2)=1, (3,9)=2 )


import sys

read = sys.stdin.readline

MAX_CELL = 505
EMPTY = 0

# input
N = int(input())
tower = [EMPTY for _ in range(MAX_CELL)]

d = [0 for _ in range(MAX_CELL)]

for _ in range(N):
    a, b = map(int, read().split())
    tower[a] = b
    d[a] = 1  # 초기값: 최소 줄은 1개 있음

# init


for i, value_i in enumerate(tower):
    for j, value_j in enumerate(tower[:i]):  # 1번 ~ i-1번
        if value_i == EMPTY or value_j == EMPTY:
            continue

        if value_i > value_j:   # 겹치지 않는 경우
            d[i] = max(d[i], d[j] + 1)

# main
print(N - max(d))
