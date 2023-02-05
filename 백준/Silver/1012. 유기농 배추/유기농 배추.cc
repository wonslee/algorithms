/*
# 문제 재정의
 2차원 공간(board)에 인접 4방면으로 붙어있는 섹션이 몇개인지 구하는 문제.

# 계획
 board의 칸들을 모두 돌면서 visited 여부에 따라 BFS를 실행. 4방면 DIR 사용.
 여기서 이 반복의 횟수에 따라 COUNT.
 같은 섹션의 칸들은 먼저 한 칸이 BFS실행된 이후에는 모두 방문됐을 것이므로 카운트는 올라가지 않음

# 복잡도 검증
# 회고
 - fill을 배웠다. 배열 초기화에 유용
 - 왜 BFS가 인접한 칸들을 모두 방문하질 않지?? x,y 가로 세로 때문에 헷갈리는건가?
*/


#include <bits/stdc++.h>
using namespace std;

int t,n,m,k,x,y;
int visited[52][52]; // 방문 여부
queue<pair<int,int>> Q; // BFS 큐
int dx[4] = {1,0,-1,0}; // DIR 4방면
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int cnt = 0; // COUNT
        cin >> m >> n >> k;

        // 보드 방문여부 초기화
        fill(&visited[0][0], &visited[51][51], 0);

        for (int i = 0; i < k; ++i) {
            cin >> x >> y;
            visited[x][y] = -1;// -1은 앞으로 방문할 칸들. 0은 없는 칸, 1은 이미 방문된 칸.
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {// LOOP: 보드의 모든 칸 순회
                if (visited[i][j] != -1) continue;
                // 해당 칸과 붙어있는 하나의 섹션에 대해 BFS
                cnt ++; // COUNT+1

                Q.push({i, j}); // enqueue
                visited[i][j] = 1;

                while (!Q.empty()) {// BFS LOOP
                    auto cur = Q.front();
                    Q.pop(); // dequeue

                    for (int dir = 0; dir < 4; ++dir) {// DIR: 4방면
                        int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
                        // CONDITION: 범위 내이고 방문 가능한 칸만 방문
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(visited[nx][ny] >= 0) continue;

                        Q.push({nx, ny});  // enqueue, 방문표시
                        visited[nx][ny] = 1;
                    }
                }

            }
        }
        cout << cnt << '\n';
    }
}