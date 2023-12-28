# DP LIS
# 같은 위치에 2개 이상 연결될 수 없음 => 1차원 배열이면 됨.
# N = 500

# 카운팅 배열 이용
# (1,8) -> [1] = 1, (2,2) -> [2] = 1, (3,9) -> 2, (4,1)
# ! (A,B)의 합을 구하면 둘이 겹치는지 아닌지 알 수 있을듯.

# '모든 전깃줄이 서로 교차하지 않는다'를 알아내는 방법?
# Ai > Aj && rope[Ai] <= rope[Aj] OR Ai < Aj && rope[Ai] >= rope[Aj]

# 이거 dp 배열을 두개 쓸까? 위로 가는 줄, 아래로 가는 줄. 둘 모두 평행인 줄들 포함.
# FOR i IN rope
#   FOR j in rope[:i]
#        IF 겹치지 않음:
#           d_up[i] = MAX( d[j]+1, d[i] )


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
    d[a] = 1    # 초기값: 최소 줄은 1개 있음

# init

# d[i] = Ai칸을 갔을 때 지금까지의 선택한 최대값. 선택한 것과 선택 안 한 것의
# e.g. (3,9) -> MAX( (1,8)=1 + 1, (2,2) + 1)
# 안 겹치는 경우 + 1, 겹치는 경우 그때까지의 MAX
# e.g. 4 -> MAX( (1,8)=1 , (2,2)=1, (3,9)=2 )

for i, bi in enumerate(tower):

    for j, bj in enumerate(tower[:i]):  # 1 ~ i-1
        if bi == EMPTY or bj == EMPTY:
            continue

        if (i > j and bi < bj) or (i < j and bi > bj):  # 겹치는 경우
            continue
        else:
            if d[j] >= d[i]:
                d[i] = d[j] + 1

# main
print(N - max(d))
