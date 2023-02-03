/*
# 문제 재정의
 bfs 문제.
 정점 i의 방문순서를 저장하고 있어야 하고, 방문에 대한 count를 사용해야 한다.

# 계획
 방문 여부를 담는 boolean 배열(vis[]) 대신에 1~N까지의 방문 순서를 담을 int 배열(order[])을 쓰자. 0으로 초기화.
 BFS:
    시작 정점 R을 discover, enqueue하면서 시작
    LOOP(!queue.empty()):
        v = dequeue()
        COUNT: 방문했으므로 +1 -> order[v]에 할당
        LOOP( i in adj[v] ):
            IF(order[p] == 0 && adj[v][i] == 1 ):
                discovered[p][i] = true
                enqueue()

# 복잡도 검증
 - sort 부분이 좀 걸린다. O(u log u)이라서 시간초과될 것 같다.
 - 공간 복잡도에서 N*M = 200억.. 20GB. 그래서 동적 배열 (vector)로 구현한다
# 회고
*/


#include <bits/stdc++.h>
using namespace std;

int n,m,r,u,v;
int cnt;
queue<int> Q; // 큐
int order[100001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r;

    vector<vector<int>> adj_list(n+1); // 인접 리스트 표현

    for (int i=0; i<m; i++){
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        sort(adj_list[i].begin(), adj_list[i].end());

    // BFS
    Q.push(r);
    order[r] = ++cnt;

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();// dequeue

        for (int adj : adj_list[cur])// LOOP: 정점의 리스트에 있는 인접 정점들에 대해
            if (order[adj]==0){// 아직 방문되지 않은 경우
                order[adj] = ++cnt; // 방문 순서 COUNT +1
                Q.push(adj); // enqueue
            }
    }

    for (int i=1; i<=n; i++)
        cout << order[i] << '\n';
}