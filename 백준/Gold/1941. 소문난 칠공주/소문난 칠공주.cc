/*
# 문제 재정의
모든 조합을 따져보는 문제 + 그래프 순회

25명 중에서 7공주가 배치될 수 있는 모든 조합을 시도.
25_C_7 = 480700 이므로 시간복잡도 통과

 BFS를 사용해 가로세로 인접 여부를 확인해나감


# 계획
1. 일단 7칸을 뽑아 놓기. 연결 그래프일지 단절 그래프일지 모르는 상태!
2. 그래프를 순회(BFS) : 단절 그래프는 거르고, 'S'가 4칸 미만인 경우도 거름.
    즉, 아무렇게나 뽑은 그래프 25개를 BFS 순회하는데,
# 복잡도 검증
# 회고
 - 애초에 그래프(2차원 보드)에서 특정 원소들이 배치되는 조합을 뽑아낼 생각은 해본 적이 없다.
 - 백트래킹 문제이지만, 순열 조합(next_permutation)을 이용해 풀 수 있구나!
 - x,y 좌표를 1차원 반복문 안에서 구하는 방법을 배웠다. /,%.

*/

#include <bits/stdc++.h>
using namespace std;

bool perm[25];      // 25명중 7공주 조합을 뽑기 위한 permutation
string board[5];    // 2차원 공간
int ans;            // COUNT
int dx[4] = {1, 0, -1, 0};  // 4 방향
int dy[4] = {0, 1, 0, -1};
int x, y;
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 5; ++i) cin >> board[i];

    fill(perm, perm + 7, true); // 7개만 true로
    sort(perm, perm + 25);  // sort 쓰지 않고 prev_permutation을 써도 되지만 00000...111 인게 더 이해하기 편하다.

    // 25_C_7
    do {
        queue<pair<int, int>> Q;    // BFS queue
        int dasom = 0, adj = 0;     // 구성원 중 이다솜파의 수, 인접한 사람의 수
        bool comb[5][5] = {false}, vis[5][5] = {false};   // comb : 7개를 뽑은 조합

        for (int i = 0; i < 25; ++i)    // LOOP : 7개의 true를 가진 perm에 대해
            if (perm[i]) {
                x = i / 5, y = i % 5;   // WOW. x,y좌표를 / %로 구할 수 있다.
                comb[x][y] = true;      // 조합 (7칸)

                if (Q.empty()) {
                    Q.push({x, y}); // 맨 첫번째 원소 enqueue
                    vis[x][y] = true;
                }
            }

        // BFS
        while (!Q.empty()) {
            tie(x, y) = Q.front();  // dequeue
            Q.pop();

            adj++;  // 인접한 사람 수 COUNT
            dasom += (board[x][y] == 'S');    // 이다솜파 COUNT

            for (int dir = 0; dir < 4; ++dir) {// DIR LOOP
                int nx = x + dx[dir], ny = y + dy[dir];
                // CONTINUE : 유효한 칸이 아니거나, 이미 방문되었거나, 이번에 뽑은 칸이 아닌 경우
                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if (vis[nx][ny] || !comb[nx][ny]) continue;

                Q.push({nx, ny});   // enqueue
                vis[nx][ny] = true;
            }
        }

        // 완성된 7공주 COUNT.
        // 만약 방문되지 않은칸이 있다면 adj < 7 일 것
        ans += (adj >= 7 && dasom >= 4);

    } while (next_permutation(perm, perm + 25));

    cout << ans;
}