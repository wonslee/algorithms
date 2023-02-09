/*
# 문제 재정의
 CCTV들의 방향에 대한 조합 문제. 상태공간트리를 정의하고 백트래킹(DFS)
 기본적으로 2차원 보드와 방향의 문제이므로 DIR을 이용.
# 계획
 1. 각 cctv의 방향 정하기.
 2. 그 방향대로 watch함수에서 쭉 지나가면서 마크(7)를 남긴다.
 3. 해당 경우의 사각 지대의 크기를 구하고, 최소 사각지대 크기를 갱신해나간다.
# 복잡도 검증
# 회고
*/


#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, -1, 0, 1}; //0 == right, 1 == up, 2 == left, 3 == down
int dy[4] = {1, 0, -1, 0};

int n, m;
int board[8][8]; // 0 빈칸, 1 ~ 5 board, 6 벽
vector<pair<int, int> > cctv;
int mn = 64;


// 2. watch: 그 방향대로 쭉 지나가면서 마크(#)를 남긴다.
void watch(int x, int y, int dir) {// (x,y)에 위치한 cctv가 DIR 방향으로만 감시
    dir %= 4; // 가능한 감시방향 right, up, left, down (0 ~ 3)
    while (true) {
        x += dx[dir];// x,y는 한 방향으로만 나아감. 반복문에 상관없이 dir값은 똑같으니까. x -1-1-1-1-1... y는 00000...
        y += dy[dir];
        if (x < 0 || y < 0 || x >= n || y >= m)return;
        if (board[x][y] == 6) return;
        if (board[x][y] != 0) continue;
        board[x][y] = '#'; // 봤다고 표시
    }
}

//idx번째 cctv를 회전
void dfs(int idx) {// DFS: idx번째 cctv에 대해 방향 정하기
    if (idx == cctv.size()) {// 3. BASE CONDITION: 모든 cctv를 다 확인했을 때
        int temp_res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) temp_res++;
            }
        }
        mn = min(mn, temp_res);// MIN: 사각지대 최소값 갱신
        return;
    }

    int x,y;
    tie(x, y) = cctv[idx];// 해당 idx의 cctv 좌표 (x,y)

    int backup[8][8];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            backup[i][j] = board[i][j];
        }
    }

    // 1. cctv 종류에 따라 방향 정하기
    for (int dir = 0; dir < 4; dir++) { // 4번까지 회전시켜본다
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                backup[i][j] = board[i][j];
            }
        }
        /*dir 1증가하면 90도 회전*/
        if (board[x][y] == 1) {// 1번 cctv : right ( 0 index)
            watch(x, y, dir);
        }
        else if (board[x][y] == 2) {// 2번 cctv: left  + right (2 index + 0 index)
            watch(x, y, dir);
            watch(x, y, dir + 2);




        }
        else if (board[x][y] == 3) {// 3번 cctv: up + right (1 index + 0 index)
            watch(x, y, dir);
            watch(x, y, dir + 1);
        }
        else if (board[x][y] == 4) {// 4번 cctv: left + up + right (2 index + 1 index + 0 index)
            watch(x, y, dir);
            watch(x, y, dir + 1);
            watch(x, y, dir + 2);

        }
        else if (board[x][y] == 5) {// 5번 cctv: down + left + up + right (3 index + 2 index + 1 index + 0 index)
            watch(x, y, dir);
            watch(x, y, dir + 1);
            watch(x, y, dir + 2);
            watch(x, y, dir + 3);
        }

        dfs(idx + 1); // BACKTRACK: 다음 board 회전시키기

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = backup[i][j]; // 다시 복사 ..?
            }
        }
    }
}



int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 5) {
                cctv.push_back({ i, j });
            }
        }
    }
    dfs(0);
    cout << mn;
}