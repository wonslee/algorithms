/*
# 문제 재정의
 bfs dfs 문제.
 인접한 칸들을 순회하면서, 1로 연결되어있는 칸이 몇개인지 count, 그림이 몇개인지 count.

# 계획
 bfs로 풀자. vis[], queue를 쓰고 그림과 칸의 count를 저장한다.
 시작 지점 여러개 있는데 어떻게 정하지?

 LOOP( (0,0) ~ (n-1,m-1) ): 모든 칸 돌아보면서 방문표시
    값이 1이라면 시작 지점을 enqueue하면서 bfs 시작.
    LOOP(queue가 공백이 아닌동안):
        dequeue->해당 좌표에 대해 아래 로직 실행
        LOOP(좌표의 상하좌우에 대해):
            CONDITION(범위 밖이거나, 이미 방문되었거나, 값이 1이 아니라면)
                continue
            방문 표시
            값이 1이라면 enqueue


# 계획 검증
# 회고
*/


#include <bits/stdc++.h>
using namespace std;

int n, m;
int picture_count=0, pixel_count=0;
int board[500][500];
bool vis[500][500]; // 각 칸의 방문 여부
int dx[4] = {1,0,-1,0}; // 상하좌우 4방면
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q; // BFS에 쓰일 queue

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }

    for (int i=0; i<n; i++)
        for (int j = 0; j < m; ++j) {// 좌표 (0,0) ~ (n-1,m-1)
            if (!vis[i][j])// 방문 안된 칸만 고려
                if (board[i][j] == 0) {
                    vis[i][j] = true;
                    continue;
                }else if (board[i][j] == 1){
                    vis[i][j] = true;// 시작지점
                    Q.push({i,j});
                    picture_count++;
                    int cnt = 1; // 픽셀 카운트
                    while (!Q.empty()){// BFS
                        pair<int,int> p = Q.front();
                        Q.pop();
                        for (int dir=0; dir<4; dir++){// 상하좌우
                            int x = p.first + dx[dir], y = p.second + dy[dir];
                            if (x < 0 || x>= n || y <0 || y>=m )// 범위 밖
                                continue;
                            if (vis[x][y] || board[x][y] != 1)
                                continue;

                            vis[x][y] = true;
                            Q.push({x,y});
                            cnt++;
                        }
                        if (cnt > pixel_count)
                            pixel_count = cnt;
                    }
                }
        }
    cout << picture_count << '\n' << pixel_count;
}