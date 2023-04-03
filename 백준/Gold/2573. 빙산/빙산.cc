/*
# 문제 재정의
BFS문제.
 두 덩어리라는걸 인식하는 것과, 그렇게 분리되는 시간을 구하는게 중요
# 계획
 while(빙산이 한 덩어리일 때)
    year++
    cnt=0
    for i
        for j
            cnt++
            if (cnt > 1) :  답 찾음. 여기서 year 출력후 return
            while(!Q.empty()):
                BFS.
# 복잡도 검증
# 회고
 - 음.. 반복문이 많아서 복잡하긴 했는데, 본질저긍로 평범한 BFS였다.
 - visited를 초기화해줘야 했는데 놓쳤다.
*/

#include <bits/stdc++.h>
using namespace std;

int n,m,year=-1;
int graph[302][302]; // 빙산 인접 매트릭스
bool visited[302][302]; // 방문 여부
queue<pair<int,int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> graph[i][j];
        }
    }

    while(true){
        year++;
        // initialize
        int cnt=0;
        for(int i = 0; i < n; i++)
            fill(visited[i], visited[i] + m, 0);

        // LOOP : n,m
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // CONDITION: 방문 불가능한 노드들은 패스
                if (graph[i][j] == 0 || visited[i][j]) continue;

                // start point 찾아야 함
                Q.push({i, j});
                visited[i][j] = true;
                cnt ++ ;

                if (cnt > 1) {// cnt가 2개. 즉 빙산이 두 덩어리로 쪼개질 때 끝
                    cout << year;
                    return 0;
                }

                while (!Q.empty()) {
                    auto cur= Q.front(); // dequeue
                    Q.pop();

                    // DIR LOOP
                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = cur.first + dx[dir], ny = cur.second + dy[dir];

                        // CONDITION : 유효한 애들만
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (visited[nx][ny]) continue;
                        if (graph[nx][ny] == 0) {// 상하좌우 0이 나올때마다 1씩 감소시키기
                            if (graph[cur.first][cur.second] > 0)
                                graph[cur.first][cur.second] --;
                            continue;
                        }

                        Q.push({nx, ny});
                        visited[nx][ny] = true;
                    }

                }
            }
        }

        // 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력
        if (cnt == 0) {// 모두 다 0인 경우
            cout << 0;
            return 0;
        }



    }

}