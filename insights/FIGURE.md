# 경우의 수 & 조합

## 반례를 꼼꼼히 찾아야 문제 유형을 제대로 파악할 수 있다  (18511)
https://www.acmicpc.net/problem/18511  https://codecollector.tistory.com/1512

얼핏 보면 첫번째 자리를 제외한 모든 자릿수에 대해선 K 집합에서 제일 큰걸 넣으면 되는걸로 보인다.  
**'그리디네!'라고 생각했다간 틀려버린다.**  

반례 : N=10, K={1} 일 때 답은 11이 아니라 1이다.  
      N=100, K={1,3}일 때 답은 133이 아니라 33이다.

즉, 자릿수에 대해 딱 이쁘게 떨어지는 구조가 아니며, 꽤 많은 경우의 수끼리 비교해봐야 한다는걸 알 수 있다.

처음부터 그리디하게 '답이 나오는 고정적인 방법'을 찾았다가는 큰일 난다.  
이건 그냥 모든 경우의 수를 뒤지는 완전탐색 문제.  
그리고 'K의 원소의 개수 <= 3'에 주목하자. n의 자릿수가 15을 넘어가지 않는 이상 안정적으로 모든 경우의 수를 탐색할 수 있다.  

=> 백트래킹을 쓰면 된다.  
함

# 2차원 공간

> 왠만하면 그려보자. 머릿속으로 생각해봤자 풀이 떠올리기 어렵다.

## DP는 경우의 수에서만 쓰는게 아니다 (1915)

https://www.acmicpc.net/problem/1915
https://breakcoding.tistory.com/366

사실 이 문제는 감도 못 잡았다.  

딱 '정사각형을 어떻게 인식하지? BFS로는 어려울텐데...'라는 생각까지만 했다.  
이전에 방문한 칸들로부터 점화식을 구할 수 있다는 생각을 해야 한다. 

# 힙(priority queue)의 응용

## 중간값은 최대힙, 최소힙으로 구할 수 있다 (1655)

https://www.acmicpc.net/problem/1655 https://www.youtube.com/watch?v=yPuow6aACvE  https://www.crocus.co.kr/625

문제 파악 : 단순하다. 그냥 매번 중간값을 구해야 하는 문제
그러나 시간복잡도는 단순하지 않다.  
'정렬과 중간값을 떼어서 보는 순간' 이 문제는 틀린다.
정렬을 하는 동시에 중간값을 구하는 구조가 힙에선 가능하다.

주어진 시간=0.1초, N=100000인 상황. 허용되는 연산은 천만번까지만 된다.
정렬과 중간값을 평범하게 (sort) 구하려고 하면 시간초과가 된다.  
STL sort는 O(n * logn)인데, log2(100000)=17 * 100000
 문제는 이게 매 숫자마다 생긴다는거.    
대략 O(n * n * log n) 이므로 절대 불가능.

시간 초과된 케이스.
```c++
int n, input;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        v.push_back(input);
        sort(v.begin(), v.end()); // 정렬 : O(log n)
        cout << v[i / 2] << '\n'; // 중간값 출력
    }
}
```

# DFS

## DFS와 그래프 사이클 : 9466
https://www.acmicpc.net/problem/9466 https://blog.encrypted.gg/499  https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x09/solutions/9466.cpp
사실 그래프(DFS)를 쓰는거라는건 쉽게 파악할 수 있었다.  
그러나 이 문제는 내가 알던 문제들과 핀트가 달랐다.  

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbPFqZW%2Fbtq91M7sfRQ%2FcIMpPdtuMz4adAKy6r3NUk%2Fimg.png)
각 노드들이 **사이클** 을 이루냐 아니냐의 문제였다.

또 어려웠던 점은 구현.  
기존에 알고 있던, stack을 쓰는 DFS와는 많이 달랐고 어찌 보면 DFS 형태를 가져와 쓰기만 하는 느낌이었다.  
왜냐면 adj_matrix(그래프를 위한 2차원 배열)을 쓰지도 않았고 백트래킹처럼 경우의 수 문제도 아니기 때문.  

여기선 visited 배열에 추가해서 **`done` 배열** 이 쓰였다.  
방문되었고, 사이클을 형성한다는게 확실해졌을 때에만 쓰이는 boolean 배열이다.  


DFS는 백트래킹에만 쓰이는게 아니다.   
자꾸 재귀와 base condition에 집착하지 말자

그래프라고해서 꼭 adj_matrix를 쓰지 않아도 된다.
이 문제처럼 공간복잡도에 한계가 있을 경우, 1차원 배열로 풀 수 있음.

# BFS
## 그래프 순회 코드에는 정답(정석적인 구현)이 있다

https://www.acmicpc.net/problem/2667

https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x09/BFS.cpp
```c++

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장

int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<pair<int,int> > Q;
  vis[0][0] = 1; // (0, 0)을 방문했다고 명시
  Q.push({0,0}); // 큐에 시작점인 (0, 0)을 삽입.
  
  while(!Q.empty()){
    pair<int,int> cur = Q.front(); Q.pop();
    cout << '(' << cur.X << ", " << cur.Y << ") -> ";
    for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
      if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
      vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
      Q.push({nx,ny});
    }
  }
}

```