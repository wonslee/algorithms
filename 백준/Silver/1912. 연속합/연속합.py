# DP 응용
# 음수라고 끊어버리는 꼼수는 안 됨. 3 4 -4 6 5 -5 1 -> 6+5가 아닌 3+4-4+6+5 = 14이다.
# 처음부터 순차적으로 모든 합을 저장해야 함

# 모든 경우의 수를 다 구하면 O(N^2)으로 시간 초과.
# 반복문 1번으로 풀 수밖에 없음. 그 안에서 max값을 구해야 함
# 이전까지의 합이 음수일 경우, 무조건 현재 원소만 취해야 함. 그 반대일 경우, 현재 원소와 더해야 함
# 이전까지의 합( d[i] ) + 현재 원소 vs 현재 원소 
# 점화식: d[i] = max(input[i], d[i-1] + input[i])
import sys

read = sys.stdin.readline

# input
N = int(input())
input_list = list(map(int, read().split()))

# init
d = [0 for _ in range(N)]
d[0] = input_list[0]

# main
for i in range(1, N):
    # 현재 원소 vs 이전까지의 합 + 현재 원소
    d[i] = max(input_list[i], d[i - 1] + input_list[i])

print(max(d))


# O(N) 그리디
# cur = 0
# mx = -1
# for i in range(N):
#     cur += input_list[i]
#     if cur < 0:
#         cur = 0     # cur < 0이 될 때 초기화.
#     elif cur > mx:
#         mx = cur
#
# print(mx)


# O(N^2)
# mx = max(input_int)

# for i in range(N):
#     d[i] = input_int[i]
#     for j in range(i+1, N):
#         d[i] += input_int[j]
#         if d[i] > mx:
#             mx = d[i]
#
# print(mx)
