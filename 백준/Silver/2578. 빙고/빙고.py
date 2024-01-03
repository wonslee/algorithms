# 구현
# 2차원 배열, 그 안에서 가로 세로 대각선이 가득찬 걸 체크하는 로직을 짜는 문제

# 빙고판 배열 -> 사회자가 부르면 0으로 바꾸자
# 사회자가 부르고 체크가 끝난 후, 해당 원소를 기준으로 가로 세로 대각선 빙고를 체크
# 빙고 카운트를 세야 함.

import sys

read = sys.stdin.readline

# init
SIZE = 5
WIN = 3
board = [[-1 for _ in range(SIZE)] for _ in range(SIZE)]
coord = [(-1, -1) for _ in range(SIZE * SIZE + 1)]  # 좌표 저장

# input
for i in range(SIZE):
    line = list(map(int, read().split()))
    for j, num in enumerate(line):
        board[i][j] = num
        coord[num] = (i, j)

# main
bingo_count = 0  # 3이 되면 빙고 외침
sum_left = sum_right = 10000


def find_bingo(x_axis, y_axis):
    global bingo_count, sum_left, sum_right

    sum_x = sum(board[x_axis])
    sum_y = sum(board[_][y_axis] for _ in range(SIZE))
    bingo_count += int(sum_x == 0) + int(sum_y == 0)

    # 대각선 빙고는 한번만 카운트해야 함.
    if sum_left != 0:
        sum_left = sum(board[_][_] for _ in range(SIZE))
        bingo_count += (sum_left == 0)
    if sum_right != 0:
        sum_right = sum(board[i][4 - i] for i in range(SIZE))  # (0,4) (1,3) (2,2) (3,1) (4,0)
        bingo_count += (sum_right == 0)


for i in range(SIZE):
    line = list(map(int, read().split()))
    for j, num in enumerate(line):
        cnt = i * SIZE + j + 1  # 몇번째 부르는 중인지
        x, y = coord[num]
        board[x][y] = 0
        find_bingo(x, y)

        if bingo_count >= WIN:  # 주의: 한번에 빙고 여러개가 될 수 있기 때문에 (e.g. 정중앙 칸) 2개 이상씩 늘어날 수 있다. >= 연산 필수
            print(cnt)
            sys.exit(0)
