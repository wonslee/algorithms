/*
# 문제 재정의
 DFS 연습문제.

# 계획
 adj_list
 dist[] 배열.
 DFS 함수 실행. R부터

 1. 배열 내림차순 정렬
 2. DFS(R)
 3. dist[] 순서대로 출력

# 복잡도 검증
# 회고
 - 백트래킹처럼 idx를 넣는 요상한 로직을 짰다가 전역 count로 수정했다.
*/


#include <bits/stdc++.h>
using namespace std;

int n,m,r,u,v;
vector<int> adj_list[100001]; // 인접 리스트
int dist[100001];   // 1~100000 노드의 거리. 모두 0으로 초기화된 상태
int cnt; // COUNT

void dfs(int node){
    dist[node] = ++cnt; // DIST +1
    for (int adj : adj_list[node]) {
        if (dist[adj] == 0) // CONDITION: 인접 정점은 아직 방문되지 않아야 한다.
            dfs(adj);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) // 내림차순 SORT
        sort(adj_list[i].begin(), adj_list[i].end(), greater<>());

    dfs(r);

    for (int i = 1; i <= n; ++i)
        cout << dist[i] << '\n';
}