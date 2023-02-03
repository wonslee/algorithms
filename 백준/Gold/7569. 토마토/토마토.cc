/*
# 문제 재정의
 7576. 토마토와 본질은 같지만 3차원 공간이라는게 다름. BFS.
 3차원을 어떻게 구현하고 순회할지가 중요
# 계획
 입력값들을 3차원 배열에 담고, dx,dy,dz (DIR) 배열을 이용해서 순회하자.
 값이 1인건 모두 시작점이므로 미리 enqueue하고 시작.

 WHILE(큐가 공백이 아닌동안): BFS
    dequeue -> cur

    DIR LOOP(cur의 상하좌우 위아래):
        CONDITION(범위 내이고, 아직 방문 안 된 경우):
            enqueue
            dist[][][] = cur칸의 값 + 1

 LOOP(전체 배열):
    최대값 갱신
    만약 -1일 경우 -1출력 후 종료

 최대값 출력

# 복잡도 검증
# 회고
 - STL tuple을 배웠다. pair가 확장된 데이터 타입.
*/


#include <bits/stdc++.h>
using namespace std;

int n,m,h;
int board[100][100][100]; // 3차원 배열 [z][y][x]
int dist[100][100][100]; // 방문순서
queue<tuple<int,int,int>> Q; // BFS queue
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;

    for (int k = 0; k < h; ++k)
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i) {
                cin >> board[k][j][i];
                if (board[k][j][i] == 1){
                    Q.push({k, j, i}); // enqueue
                }else if (board[k][j][i] == 0)
                    dist[k][j][i] = -1; // -1: 익지 않음  0: 빈칸 혹은 시작점
            }

    while (!Q.empty()) { // BFS LOOP
        auto cur = Q.front();
        Q.pop(); // dequeue

        for (int dir = 0; dir < 6; ++dir) {
            int nx= get<1>(cur) + dx[dir], ny= get<2>(cur) + dy[dir], nz= get<0>(cur) + dz[dir];
            // CONDITION : 범위 초과 혹은 이미 방문됐거나 아예 빈칸인 경우
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (dist[nz][nx][ny] >= 0) continue;

            Q.push({nz,nx,ny}); // enqueue
            dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] +1; // DIST +1
        }
    }

    int mx=-100;
    for (int k = 0; k < h; ++k)
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i) {
                if (dist[k][j][i] == -1){
                    cout << -1;
                    return 0;
                }else if (dist[k][j][i] > mx)
                    mx = dist[k][j][i];
            }

    cout << mx;

}