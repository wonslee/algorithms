/*
# 문제 재정의
 경우의 수 문제 같은데. 완전탐색?
 DFS 혹은 DP 유형으로 보임.

 이동할 수 없을 경우를 어떻게 찾을지 모르겠다. 그냥 값이 0이면 되는건가?
# 계획
 BFS.

 우선 모든 층에 대한 횟수를 저장할 배열을 만든다. -1로 초기화
 dist[s]=0으로 시작해, enqueue하고 BFS시작.


# 복잡도 검증
# 회고
 - 처음에 DP로 짜봤더니 분기가 쪼개지는 문제였다. 그리고 순서대로 진행하기가 어려움. 그래서 DFS로 진행
 - 그런데 메모리초과가 나왔다. 답안 보고 BFS로 바꿨다.
 - BFS가 그래프 탐색 외에도 쓰일 수 있다니....! BFS를 다시 생각해봐야겠다.
 - 움직인 횟수를 '거리'라고 생각하는 패러다임을 배웠다.
 https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x09/solutions/5014.cpp
*/

#include <bits/stdc++.h>
using namespace std;

int f,s,g,u,d;
int dist[1000002];  // 각 층의 거리(버튼 눌러 움직인 횟수)
queue<int> Q;       // BFS Queue

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> f >> s >> g >> u >> d;

    // INITIAL
    fill(dist + 1, dist + f + 1, -1); // -1로 초기화
    dist[s] = 0;// 현재 s층에 대한 거리는 0
    Q.push(s);  // s층 enqueue

    // BFS
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();   // dequeue
//        cout << "cur=" << cur << '\n';
        // 핵심 LOOP : 현재 층에서 2가지 경우의 수. +U 혹은 -D
        for (auto nxt: {cur + u, cur - d}) {
            // CONDITION: nxt 층이 유효한 범위가 아니거나, 이미 방문된 층일 경우
            if (nxt > f || nxt <= 0 || dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1; // 방문, enqueue
//            cout << "\tnxt=" << nxt << " dist[nxt]=" << dist[nxt] <<  '\n';
            Q.push(nxt);
        }
    }

    if(dist[g]==-1) cout << "use the stairs";
    else cout << dist[g];

}