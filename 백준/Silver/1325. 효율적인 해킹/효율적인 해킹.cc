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

#define MAX_N 10100
#define MAX_M 100100

int N, M, a, b;
int mx = -1;
vector<int> adj_list[MAX_N]; // 인접 리스트
queue<int> Q; // BFS 큐
bool visited[MAX_N];// 방문 여부
int vis_rank[MAX_N];


// BFS
void bfs(int initial_node) {
    Q.push(initial_node);
    fill(visited, visited + MAX_N, false);  // visited 초기화
    visited[initial_node] = true;

    while (!Q.empty()) {// BFS
        int node = Q.front(); Q.pop(); // dequeue

        for (int adj: adj_list[node]) {
            // CONDITION: 방문 안 된 경우
            if (!visited[adj]) {
                visited[adj] = true;// 방문 표시
                vis_rank[initial_node]++;
                Q.push(adj);// enqueue
            }
        }
    }

    if (vis_rank[initial_node] > mx) {
        mx = vis_rank[initial_node];    // 최대값 갱신
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {// 입력: 단방향 그래프에 대한 간선 M개
        cin >> a >> b;
        adj_list[b].push_back(a);
    }


    for (int i = 1; i <= N + 1; i++) {
        bfs(i);
    }

    for (int i = 1; i <= N + 1; i++) {
        if (vis_rank[i] == mx) {
            cout << i << " ";
        }
    }

}