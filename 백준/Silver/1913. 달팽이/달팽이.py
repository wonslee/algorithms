# 정사각형 안에 달팽이 모양의 순회를 구현하는 문제
# 좌표 체계를 어떻게 구할것인지가 관건
# 정사각형: N^2만큼의 사이즈

# 좌표 순회 규칙이 일정함.
# 시작 지점 (x,y) = ( N//2, (N-1)//2 )
# N=1 : 0,0   N=2 : 1,0   N=3 : 1,1   N=4 : 2,1   N=5 : 2,2   N=6 : 3,2   N=7 : 3,3

# N=3일 때 1,1 -> 0,1 -> 0,2 -> 1,2 -> 2,2 -> 2,1 -> 2,0 -> 1,0 -> 0,0
# N=5일 때 (1) 2,2 (2) ->  1,2 -> 1,3 -> 2,3 - 3,3 - 3,2 - 3,1 - 2,1 - 1,1
# ... - 0,1 - 0,2 - 0,3 -   0,4 - 1,4 - 2,4 - 3,4 - 4,4
# 1사이클이 2회씩. 위 -> 오른쪽 OR 아래 -> 왼쪽
# 상대적 위치로 돌아야 함.
# 순회 배열 [ (-1,0),(0,1),(1,0),(0,-1)  ] 을 돌자. 사이클 카운트 % 4
# 턴 카운트를 세면서, 사이클

import sys

read = sys.stdin.readline

# input
N = int(input())
target = int(input())

# init
square = [[0 for _ in range(N)] for _ in range(N)]
dirr = [(-1, 0), (0, 1), (1, 0), (0, -1)]  # 회전 방향. (turn-1) % 4를 인덱스로 함

cycle = 0  # 방향의 기준인 턴
turn_step = 0  # 사이클 내에서 몇번 전진해야 하는지 카운트. (turn + 1) // 2
step = 0
x, y = N // 2, (N - 1) // 2  # 시작 지점

cnt = 0
result = ""
# main
for i in range(1, pow(N, 2) + 1):
    square[x][y] = i
    if i == target:
        result = str(x + 1) + " " + str(y + 1)

    # 순회
    dx, dy = dirr[cycle % 4]
    x, y = x + dx, y + dy

    turn_step = (cycle + 2) // 2  # 한 턴에 가야하는 스텝 개수
    step += 1
    if step == turn_step:  # 다 전진했을 경우, 방향 바꾸고 스텝 카운트 초기화
        cnt += 1
        cycle += 1
        step = 0

# 입력값의 좌표 출력
for row in square:
    for el in row:
        print(el, end=' ')
    print()

print(result)
