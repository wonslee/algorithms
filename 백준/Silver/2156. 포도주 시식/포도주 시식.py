# 경우의 수 DP 문제
# i번째에서 그떄까지의 최대값들을 저장하면 될 것 같음.
# N = 10000, 시간 제한 2초

# O(N^2) 될듯.
# 연속 3칸을 방문할 수 없기 때문에, 이전의 2칸을 방문했는지를 저장해야 함
# 예: 6(1), 10(2), 13(X), 9(1), 8(2), 1(X)
# 각 칸마다 결국 2가지다. 방문하냐 안 하냐.

# 점화식
# d[i][j] = i번째에 연속j번째일때 최대값 = d[i][j-1] + wine[i]
# 연속 횟수에 따라 분기 처리. if j>2: pass

# ----------------
# 경우의 수
# 1. 현재 + 이전 포도주를 마신다: wine[i] + wine[i-1] + d[i-3]
# 2. 현재 + 전전 포도주를 마신다: wine[i] + d[i-2]
# 3. 현재 포도주를 마시지 않는다: d[i-1]

# 점화식: d[i] = MAX( 1, 2, 3)

# 회고
# 어떻게 보면 간단한 점화식인데, 괜히 복잡하게 경우의 수에 빠져서 풀이를 못 찾았다.

import sys

read = sys.stdin.readline

# input
N = int(input())

# init
MAX_N = 10005
wine = [0 for _ in range(N)]
d = [0 for _ in range(N)]

for i in range(N):
    wine[i] = int(input())

# 초기값: index 에러 때문에 N값에 따라 지정
d[0] = wine[0]

if N > 1:
    d[1] = wine[0] + wine[1]
if N > 2:
    d[2] = max(wine[1]+wine[2], wine[0]+wine[2], d[1])
# main
for i in range(3, N):
    d[i] = max(d[i - 1], d[i - 2] + wine[i], d[i - 3] + wine[i] + wine[i - 1])

print(max(d))
