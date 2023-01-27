/*
백준에서 제출 인식이 안 되나? 테스트
*/


#include <bits/stdc++.h>
using namespace std;

int n,m;
string board[102];
int dist[102][102];
queue<pair<int,int>> Q; // 좌표 저장할 큐
int dx[4] = {1,0,-1,0}; // DIR
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
            cin >> board[i];
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; ++j)
            dist[i][j] = -1; // -1로 초기화

    Q.push({0,0}); // (0,0) 넣고 시작
    dist[0][0] = 0; // H0
    while (!Q.empty()){// BFS
        auto cur = Q.front(); Q.pop(); // dequeue

        for(int dir=0; dir<4; dir++){// DIR LOOP
            int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 벗어나는 경우
            if(dist[nx][ny] >= 0 || board[nx][ny] != '1') continue; //

            dist[nx][ny] = dist[cur.first][cur.second]+1; // 해당 칸까지의 거리 Hi+1

            Q.push({nx,ny});
        }
    }

    cout << dist[n-1][m-1]+1;
}

