/*
# 문제 재정의
 완전탐색문제. 모든 경우의 수를 다 따져봐야 한다.
 => DFS를 쓰되 가능하면 DP를 사용

 이거 BFS로는 할 수 없음. 기본적으로 BFS의 목적은 그래프 순회 자체. '딱 1번안에 다 돈다'
 상태공간트리를 생각해볼까?
 DFS로 한다면 ... 4방향 각 분기점마다 계속 쪼개지게 된다.
 DP까지 쓰는 문제...!
# 계획
- dp 배열 약속.  초기값 -1 : 아직 탐색하지 않은 곳, 0 : 탐색한 경우, 1 이상 : 탐색했고, 목적지까지 도달할 수 있는 경우.
 1 이상일 경우, 그 값은 도달할 경우의 수 개수를 나타낸다.
- dp값이 0이라면 탐색한 곳이지만 그 후에 탐색할 곳이 없는 칸이 된다.
- dp값이 0 이상의 값이라면, 이전에 방문한 값이므로 dp값을 리턴 받아 다시는 그 경로를 탐색하지 않게 한다.

# 복잡도 검증
# 회고
 - https://fre2-dom.tistory.com/251
   https://www.youtube.com/watch?v=x4XpprJMMIY
 - 무턱대고 쫄지 말고, 탐색하는 과정을 머릿속으로 그려보자. 경우의 수가 있을 때 일단 완전탐색을 생각해보자. 처음엔 무식하게.
 - 그래프, 보드 모양이라고 곧장 BFS를 꺼내들면 안 된다. '경우의 수'가 나오는 순간 BFS는 경계해야 함.
 - DP까지 써야하는지는 몰랐다. 조금만 응용되어도 바로 못 푸네..
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int board[505][505];        // graph
int d[505][505];            // DP
int dx[4] = {1, 0, -1, 0};  // DIR
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y) {
    // 마지막 칸에 도착했을 경우, 1을 반환
    if (x == n-1 && y == m-1) return 1;
    // 이미 방문된 경우, 해당 값을 바로 반환
    if (d[x][y] != -1) return d[x][y];

    d[x][y] = 0; // 방문 표시.

    for (int dir = 0; dir < 4; ++dir) {     // DIR 4방향
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[x][y] > board[nx][ny])    // DFS 호출
            d[x][y] += dfs(nx, ny);
    }
    return d[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            d[i][j] = -1;
        }

    cout << dfs(0, 0);

}