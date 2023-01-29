/*
# 문제 재정의
 BFS문제. 2178 미로탐색 문제와 비슷한 점이 보인다.

 vis[][] 대신, 각 칸의 거리를 저장할 2차원 배열을 써서 순회할 때마다 Hi를 표현하도록 1씩 증가시킨다.
 그렇게 각 칸의 최소값을 갱신하고, 끝나면 전체 보드에서 가장 큰 값을 찾는다.
 dx,dy를 사용해서 인접 4방면을 효율적으로 돌 수 있도록 한다.

# 계획
 BFS는 1에서만 시작해야 하고, 0인 정점들만을 인접정점으로 취급해야 한다.
 한번 옮을 때마다 Hi에 대한 count를 증가시키고, 각 칸의 거리 h[][]의 (최소)값을 갱신한다.
 그렇게 여러 1에서 시작한 BFS의 결과로 나온 h[][]에서 최대값과 최소값을 구한다.
 만약 최소값이 0이라면 -1을 출력하고, 최대값이 1이라면 0을 출력. 그 외엔 최대값을 출력한다.

 입력받을 때, 처음부터 1인 곳의 좌표(pair)를 배열로 저장하자.


 BFS
 start[0]을 enqueue
 h[][] = 1
 WHILE( !Q.empty() ):
    dequeue -> cur

    DIR LOOP( 인접 4방면 ):
        CONDITION: 범위를 초과하지 않고, 인접칸의 순서 dist[nx][ny]가 0이거나 현재 칸보다 클 경우에만 방문
            enqueue({nx,ny})
            h[nx][ny] = h[cur.X][cur.Y] + 1

 최대값-1 출력

# 복잡도 검증
# 회고
 - 얼떨결에 때려맞춘듯한 느낌이 든다. 코드를 쓰면서 추측을 다듬었다. 출력을 보기도 했고
 - 메모리 초과... 왤까?
 - 시작점이 여러개더라도, 그냥 enqueue 하면 된다??
*/


#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n,m;
int board[1002][1002];
int dist[1002][1002];  // 거리(H0~Hi)를 담을 2차원 배열
int dx[4] = {1,0,-1,0}; // DIR
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    queue<pair<int,int>> Q; // BFS 큐

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j){
            cin >> board[i][j];
            if (board[i][j] == 1)
                Q.push({i,j}); // 여기서 미리 enqueue
            else if (board[i][j] == 0)
                dist[i][j] = -1;
        }

        while (!Q.empty()) {// BFS LOOP
            pair<int,int> cur = Q.front(); Q.pop(); // dequeue

            for (int dir=0; dir<4; dir++){// DIR LOOP: 인접 4방면
                int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
                // CONDITION : 범위 내 AND 칸(board, dist)의 값이 0 AND 칸(dist)이 현재 칸(dist)보다 클 경우에만 방문.
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (dist[nx][ny] >= 0) continue;

                Q.push({nx,ny}); // enqueue
                dist[nx][ny] = dist[cur.X][cur.Y] + 1; // ORDER +1
            }
        }

    int mx = -100;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == -1){// 하나라도 -1이 있을 경우, 안 익은 토마토가 존재하므로 -1 출력후 아예 종료
                cout << -1;
                return 0;
            }else if (dist[i][j] > mx) mx = dist[i][j]; // MAX
        }

    cout << mx;
}