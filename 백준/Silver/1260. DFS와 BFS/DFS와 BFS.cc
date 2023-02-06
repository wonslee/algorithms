/*
# 문제 재정의
 양방향 무가중치 그래프에 대한 BFS, DFS 구현.
 오름차순으로 방문, 연결그래프 하나씩만.

# 계획
 adj_list
 BFS를 위한 order[1001], DFS를 위한 order[1000].



# 복잡도 검증
 인접그래프로 구현할 경우 O(V+E) => 대략 11000회
 BFS, DFS 모두 복잡도가 같으므로 2번씩.

# 회고
 Q. 정점 사이에 여러개의 간선이 있을 수 있다..? 인접 매트릭스로는 해결하지 말라는 의미인건가?
*/


#include <bits/stdc++.h>
using namespace std;

int n,m,v,a,b;
vector<int> adj_list[1001]; // 인접 리스트
vector<int> dfs_order;// 방문 ORDER
vector<int> bfs_order;
bool visited[1001];// 방문 여부
queue<int> Q; // BFS 큐

void dfs(int node){// DFS
    for (int adj : adj_list[node]) {// LOOP: 인접한 정점들에 대해
        if (!visited[adj]) {// CONDITION: 아직 방문 안 된 경우
            visited[adj] = true; // 방문 표시
            dfs_order.push_back(adj); // 방문 순서
            dfs(adj);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> v;

    for (int i = 0; i < m; ++i) {// 입력: 그래프에 대한 인접 리스트
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    // 오름차순 정렬
    for (int i =  1; i <= n; ++i) {
        sort(adj_list[i].begin(), adj_list[i].end());
    }

    visited[v] = true; // 첫번째 방문 표시
    dfs_order.push_back(v);
    dfs(v);

    for (int o : dfs_order) 
        cout << o << " ";
    cout << '\n';

    fill(visited, visited+1001, false);

    visited[v] = true;
    bfs_order.push_back(v);
    Q.push(v);
    while (!Q.empty()) {// BFS
        int cur = Q.front();
        Q.pop(); // dequeue

        for (int adj : adj_list[cur]) {
            // CONDITION: 방문 안 된 경우
            if (!visited[adj]) {
                visited[adj] = true;// 방문 표시
                bfs_order.push_back(adj);
                Q.push(adj);// enqueue
            }
        }
    }

    for (int o : bfs_order) 
        cout << o << ' ';
    cout << '\n';
}