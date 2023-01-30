/*
# 문제 재정의
 BFS 구현 문제.
 이런 입력에는 adjacent list 표현이 유리할 듯.
 방문 전에 각 리스트를 내림차순으로 정렬한다는게 다름.

# 계획
 adjacent list 표현.
 BFS
    COUNT를 올려가면서 카운팅 배열 order[]에 각 정점의 방문 순서를 저장

# 복잡도 검증
# 회고
 - 입력, 출력 신경쓰자.. 여기선 M개 줄을 받을걸 N개 받았다.
*/


#include <bits/stdc++.h>
using namespace std;

int n,m,r,u,v;
int cnt=0;
vector<int> adj_list[100001];
int order[100001] = {0,}; // 방문 순서
queue<int> Q;   // BFS 큐

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj_list[u].push_back(v);// adjacent list 간선 생성
        adj_list[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) // SORT
        sort(adj_list[i].begin(), adj_list[i].end(), greater<>());

    Q.push(r); // 시작 정점 enqueue
    order[r] = ++cnt; // COUNT: 방문 순서

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop(); // dequeue

        for (int adj : adj_list[cur]){// LOOP: 정점 cur의 인접 정점들
            if (order[adj] == 0){// CONDITION: 아직 방문 안 한 경우
                Q.push(adj);
                order[adj] = ++cnt;
            }
        }
    }

    for (int i=1; i<=n; i++)
        cout << order[i] << '\n';
}