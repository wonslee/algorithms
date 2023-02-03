
# BFS
## BFS란?
너비 우선 탐색(Breadth First Search)는 시작점에서 **가까운** 정점부터 순서대로 방문하는 탐색 알고리즘이다.  
간선을 i개 지나야 도착할 수 있는 정점의 집합을 Hi 라고 부르자.  

BFS에서는 H0에 속한 a를 가장 먼저 방문하고, H1, H2, H3 순으로 방문해 나간다.  
그래서 a를 방문하고 나면 b,d,e,h가 목록에 가추되고, c,f,g,i는 절대 이들보다 먼저 방문되서는 안 된다.  

이러한 BFS의 성질을 만족시키기 위해 **목록에 먼저 넣은 정점을 항상 먼저 꺼내는** 방법을 쓴다.  
즉, FIFO를 만족하는 자료구조인 **큐**를 쓴다.  

![](https://mblogthumb-phinf.pstatic.net/MjAxODA3MjFfOTUg/MDAxNTMyMTA3NDUxMzc4._7T0MhYqk1pMNFllzdyZjxYiPFqTfdkZCuC1DQTCxGcg.8cqFiVSk08Vu2fdEUVP8jHTCGkrrTrVh729cjhAPtFgg.PNG.cottory/image.png?type=w800)  

## 정점의 3가지 상태
깊이우선탐색(DFS)과는 달리, BFS에서는 발견과 방문이 동시에 이뤄지지 않는다.  
정점은 3가지 상태를 갖는다:  
1. 아직 발견되지 않은 상태
2. 발견되어서 목록에 있지만 아직 방문되지는 않은 상태(enqueue)
3. 방문된 상태(dequeue)

<details>

```c++

vector<vector<int>> adj; // adjacent list 표현

vector<int> bfs(int start){//BFS : start를 시작 정점으로
vector<bool> discovered(adj.size(), false);// 각 정점의 방문 여부
queue<int> Q; // 방문할 정점 목록을 저장할 큐
vector<int> order;//정점의 방문 순서 (필수 아님)

    discovered[start] = true;
    Q.push(start);

    while(!Q.empty()){
        int here = Q.front(); Q.pop(); // 큐의 front에 있는 정점부터 방문
        order.push_back(here);
        for (int i=0; i<adj[here].size(); ++i){
            int there = adj[here][i];
            cout << there << '\n';

            if (!discovered[there]){// 처음 보는 정점일 경우
                Q.push(there); // enqueue
                discovered[there] = true; // 방문 표시
            }
        }
    }
    return order;
}
```

</details>

## 시간 복잡도
모든 정점을 한번씩 방문하고, 방문할때마다 인접한 모든 간선을 검사한다.   
표현에 따라서 다른데, 인접 리스트 표현의 경우에는 O(V+E),  
인접 행렬 표현의 경우에는 O(V^2) 복잡도를 갖는다.  

DFS와 시간복잡도가 같다.  

## BFS의 응용(BOJ 1926. 그림)
1. 시작하는 칸을 큐에 넣고 방문 표시(enqueue)
2. dequeue -> 해당 원소에 인접한 칸에 대해 3번을 진행
3. 해당 칸을 이전에 방문했다면 아무것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 enqueue
4. 큐가 빌 때까지 2번을 반복.

모든 칸이 큐에 1번씩 들어가므로 칸이 n개일 때 O(n)

`pair<int,int>`를 써서 좌표를 저장한다

# DFS

BFS에서 유용하게 썼던. "현재 칸의 인접한 칸의 거리는 현재 칸보다 1만큼 더 떨어져있다"는 성질이  
DFS에서는 성립하지 않는다.  

애초에 BFS는 H1, H2, ... 식으로 시작점을 기준으로 거리순으로 나아가는 반면 DFS는 그렇지 않기 때문.
이 결정적인 차이의 원인은 큐와 스택 구조의 차이에서 온다.  

그래서 다차원 보드에서 순회, 거리 재는 문제들에서 DFS는 쓸 수 없다.  
Flood fill까지는 상관 없음.  

DFS는 나중에 그래프와 트리 관련 알고리즘에서 주로 쓰이게 됨.   


## DFS 응용 (flood fill)
1. 시작하는 칸을 스택에 넣고, 방문 표시
2. 스택에서 pop -> 해당 칸과 상하좌우 인접한 칸에 대해 3번을 2ㅣㄴ행
3. 해당 칸을 이전에 방문했을 경우 아무것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 스택에 push
4. 스택이 빌 때까지 2번을 방복.

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FdP24nD%2FbtqEq8G4txS%2FktigB4Qf2eTekZ3MUTF9E1%2Fimg.png)


모든 칸이 스택에 1번씩 들어가므로 시간복잡도는 칸이 n개일 때 O(n)

# TODO
BFS와 최단거리, MST 알고리즘 연결
