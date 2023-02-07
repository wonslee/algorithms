/*
# 문제 재정의
 BFS인데, 인접한 그룹의 수와 그 칸 수를 COUNT하는 문제.

# 계획
 모든 칸을 순회하면서 Queue에 들어있는 칸을 BFS하면 되겠다.
 vector COUNT를 써서 각 그룹의 칸 카운트를 구하고, 마지막에 오름차순 정렬을 해서 size와 각 count를 출력하자.

# 복잡도 검증
결국 모든 칸을 순회하므로 O(n^2)
# 회고
*/


#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
char input;
int visited[26][26]; // -1: 앞으로 갈 칸 0:못 가는 칸 1: 방문한 칸
queue<pair<int,int>> Q; // 좌표를 저장할 BFS 큐
int group_cnt;
vector<int> groups; // 각 그룹에 대한 칸 COUNT
int dx[4] = {1,0,-1,0}; // DIR 4방면 배열
int dy[4] = {0,1,0,-1};


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> input;
            if (input == '1')
                visited[i][j] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {// 모든 칸 순회
            if (visited[i][j] >= 0) continue; // 못가는 칸이거나 방문한 칸인 경우 continue

            Q.push({i, j});// 그룹의 첫번째 칸 enqueue
            visited[i][j] = 1;
            groups.push_back(1); // 해당 그룹의 칸 COUNT 시작
            group_cnt++; // 그룹 개수 COUNT

            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop(); // dequeue

                for (int dir = 0; dir < 4; ++dir) {// 4 DIR
                    int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
                    // CONDITION: 범위내이고 아직 방문하지 않은 유효한 칸만 방문
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny] >= 0) continue;

                    Q.push({nx, ny});
                    visited[nx][ny] = 1;
                    groups[group_cnt - 1] ++; // 해당 그룹의 칸 COUNT +1
                }
            }
        }
    }

    cout << groups.size() << '\n';

    sort(groups.begin(), groups.end()); // 오름차순 정렬
    for (int g : groups)
        cout << g << '\n';
}