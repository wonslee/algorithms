/*
# 문제 재정의
 BFS, BOARD 4방면(DIR)을 움직이는 문제.
 시작점은 2개로, J와 F이다.
 J의 순회는 인접정점으로 갈 때마다 DIST +1을 갱신해나간다.

# 계획
 DIR을 위한 dx,dy 4방면 배열
 입력에 따른 board[][]
 지훈이의 이동거리를 저장할 dist[][]
 DFS를 위해 좌표x,y와 구별키 tuple을 저장할 Queue

 갈수 있냐 없냐만 따졌을 때, 불이 붙은 곳은 벽과 본질이 같다.
 단순화시켜서 앞으로 갈 칸(-1), 못 가는 칸(0), 이미 방문한 칸(1~)로 칸의 상태를 다루자.

 1. 입력에서 시작지점 J와 F를 넣고 시작
 Q.push('J', J.X, J.Y)
 Q.push('F', F.X, F.Y)
 DIST 값
 '.' : -1
 'J' : 1
 'F', '#' : 0

 2. DFS
 WHILE(Q가 공백이 아닌동안):
    dequeue -> cur
    cur의 정체가 지훈일 경우와 불일 경우를 나누기.
    DIR LOOP(4방면):
        IF(범위를 벗어남 || DIST값이 0보다 크거나 같음): continue

# 복잡도 검증
# 회고
 - board 매트릭스는 쓸 필요 없었네
 - 53%에서 틀렸다.
 - 불을 먼저 이동시켜야 한다!! 지훈이가 있는 순간에 불이 번지면 그것도 죽는거니까
*/


#include <bits/stdc++.h>
using namespace std;

int r,c;
char input;
int dist[1000][1000]; // DIST
queue<tuple<char, int, int>> Q; // BFS Queue
tuple<char,int,int> geek;
int dx[4] = {1,0,-1, 0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            cin >> input;
            // SWITCH: 입력값 case에 따라 dist값 할당, F와J의 경우 미리 enqueue
            switch (input) {
                case '.':
                    dist[i][j] = -1;
                    break;
                case 'J':
                    dist[i][j] = 1;
                    geek= make_tuple('J',i,j);
                    break;
                case '#':
                    dist[i][j]=0;
                    break;
                case 'F':
                    Q.push({'F', i, j});
                    break;
            }
        }

    Q.push(geek); // 맨 마지막에 넣기

    while (!Q.empty()) {// DFS LOOP
        auto cur = Q.front(); Q.pop(); // dequeue

        char id; int curX, curY;
        tie(id, curX, curY) = cur;

        if (id=='J' && (  curX == 0 || curY == 0 || curX == r-1 || curY == c-1) ){// CONDITION : 만약 지훈이가 가장자리 칸에 있는 경우
            cout << dist[curX][curY];
            return 0;
        }

        for (int dir = 0; dir < 4; ++dir) {// DIR LOOP
            int nx = curX + dx[dir], ny = curY + dy[dir];
            // CONDITION : 범위내, 아직 방문되지 않은 곳만 방문
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (dist[nx][ny] >= 0) continue;

            Q.push({id,nx,ny}); // enqueue
            if (id == 'J')
                dist[nx][ny] = dist[curX][curY] + 1;
            else if (id == 'F')
                dist[nx][ny] = 0;
        }
    }
    cout << "IMPOSSIBLE"; // 탈출 불가능한 경우
}