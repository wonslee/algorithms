/*
# 문제 재정의
 dfs,bfs문제.
 한번의 Hi(0,0은 H0)을 거칠 때마다 count +1 하면서 그래프를 순회하다가, (n,m)에 도착했을 때 종료.
 다차원 배열의 거리측정. 최단 경로를 찾아야 하고, 이중에서 BFS의 성질을 사용한다.
# 계획
 BFS:
 (1,1)을 discover, enqueue하면서 시작
 while(!Q.empty):
    dequeue -> 좌표
    DIR(해당 좌표에 대한 4방면):
        IF(미방문 && 값이 1):
            discovered 표시, enqueue
            count ++
            IF( 좌표가 (n,m) ):
                break
 Hi를 어떻게 구분하지?
    구분하는게 아니라, 거리(nx+ny)가 1씩 변하는 보드의 성질을 이용해서 맨 끝칸까지의 거리를 재자.
    이 배열의 값을 -1로 초기화해두면 vis배열을 쓰지 않아도 된다.
# 복잡도 검증
# 회고
 - 백트래킹이 필요 없는건가? 어떤게 최단거리인지 조합을 따져보지 않고도 구할 수 있는건가
 - board에서 출발지와 도착지가 양끝으로 정해져있으면,
 BFS로 했을 때 어차피 최소칸이 나온다!! 목적지까지 가는데 필요한 Hi의 i가 그 거리가 된다.
 그래서 이 문제는 백트래킹 등 다른 방법으로도 풀 수는 있지만, BFS로 자연스럽게 풀리는 문제가 되는듯.
 - 거리를 재는 방법 (dist[][])를 배웠다.
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

