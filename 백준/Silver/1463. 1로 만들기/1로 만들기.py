# 경우의 수 문제
# 시간 제한 0.15초로 매우 짧음. DP로 풀어야 할듯.
# RGB 문제와 비슷

# 1,2,3 세가지 경우를 연산했을 때의 결과를 메모리제이션해가자
# 10 -> X / 5 / 9 -> X / 4 / 3/8  -> X / 2/3 / 1/2 4/7
# d[i] = i값을 만들기까지 걸린 최소 횟수

import sys

read = sys.stdin.readline

# input
N = int(input())

# init
MAX_INT = sys.maxsize
d = [MAX_INT for _ in range(N+1)]  # 3MB

d[N] = 0

# main
for num in reversed(range(1, N+1)):
    if num % 3 == 0:
        d[num // 3] = min(d[num] + 1, d[num // 3])
    if num % 2 == 0:
        d[num // 2] = min(d[num] + 1, d[num // 2])
    if num > 1:
        d[num - 1] = min(d[num] + 1, d[num - 1])

print(d[1])

