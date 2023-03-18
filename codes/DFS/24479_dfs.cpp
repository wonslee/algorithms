#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_VERTEX 100001

using namespace std;

vector<int> graph[MAX_VERTEX];
int visited[MAX_VERTEX] = { 0, };
int cnt = 0;

void dfs(int v) {
    if (visited[v] != 0)  // 방문 한 곳이면 return
        return;
	
	visited[v] = ++cnt; 

    for (int i = 0; i < graph[v].size(); i++) 
            dfs(graph[v][i]); 
    

}

int main() {
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);

    // 양방향 간선 생성 
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b); 
		graph[b].push_back(a);	
	}
    // ?
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(r);
	
    for (int i = 1; i <= n; i++) {
		printf("%d\n", visited[i]);
	}
	
}
