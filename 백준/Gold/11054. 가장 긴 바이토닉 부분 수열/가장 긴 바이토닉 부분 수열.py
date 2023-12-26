#
# 수열 찾는 문제. DP
# 바이토닉 수열임을 알아내는 로직이 필요
# 바이토닉 중간 지점을 찾는게 중요...

# O(N^2)
# 수열 A 순회 -> 각 원소마다 그 전의 가장 높은 스트릭을 갖는 숫자 찾기
# 스트릭의 기준이 문제다.
# 증가 수열 문제때처럼 증가 부분만 저장해선 안 됨.
# ! 감소 수열도  저장. 원소 x에 대해 증가 수열[x] 값을 가져오기.

# d_up[num] = 증가 수열 저장 = if sequence[i] > sequence[i-1]: d_up[이전 숫자] + 1
# d_down[num] = if < : MAX(d_down[이전 숫자], d_up[num]) + 1

import sys

read = sys.stdin.readline

# input
N = int(input())
sequence = list(map(int, read().split()))

# init
MAX_NUMBER = 1005
d_up = [1 for _ in range(MAX_NUMBER)]   # 모든 숫자는 자기 자신이 카운팅될 수 있기 때문에 1로 초기화
d_down = [1 for _ in range(MAX_NUMBER)]

# main
for i, a in enumerate(sequence[1:]):
    previous = sequence[i - 1]
    for b in sequence[0:i + 1]:
        if a > b:
            d_up[a] = max(d_up[a], d_up[b] + 1)  # 증가수열 저장

        if a < b:
            d_down[a] = max(d_down[a], d_down[b] + 1, d_up[b] + 1)  # 감소 수열 저장

print(max(max(d_up), max(d_down)))
