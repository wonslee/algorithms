# 요소 30개로, 대상이 정해져 있다.
# 카운팅이 필요.
# 배열로 체크?


import sys

read = sys.stdin.readline

# input
inputs = [int(input()) for _ in range(28)]

# init
FIRST=0
LAST=29

students = [False for _ in range(LAST+1)]


# main
# 배열을 순회하면서, 체크되지 않은 번호를 출력
for input in inputs:
    students[input-1] = True

for i, st in enumerate(students):
    # print(i+1, st)
    if not st:
        print(i+1)

