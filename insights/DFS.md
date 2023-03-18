# DFS 그래프 이론

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

# 백트래킹(BackTracking)
## 백트래킹이란?
“A technique for **listing all possible solutions for a combinatorial** algorithm problem.”

백트래킹이란 어떤 **조합** 문제에 대해 모든 가능한 해를 나열하는 기술이다.  
조합이 잘 생각나지 않는다면, 한 반의 친구들 N명을 M명씩 짝지어주기위해 **선택**하는 경우의 수를 떠올려보면 된다.

![image](https://ibpublicimages.s3-us-west-2.amazonaws.com/tutorial/backtracking1.png)

백트래킹은 **모든 조합의 수**를 살펴보는 것인데, 단 조건이 만족할 때 만이다. 모든 경우의 수를 모두 찾는 것보다 ‘경우에 따라' 훨씬 빠를 수 있다.


## 깊이 우선 탐색(DFS)과 백트래킹

DFS는 가능한 모든 경로(후보)를 탐색한다.  
따라서, 불필요할 것 같은 경로를 사전에 차단하거나 하는 등의 행동이 없으므로 경우의 수를 줄이지 못한다.

주로 문제 풀이에서는 DFS 등으로 모든 경우의 수를 탐색하는 과정에서, 조건문 등을 걸어 답이 절대로 될 수 없는 상황을 정의하고,  
그런 경우엔 탐색을 중지시킨 뒤 그 이전으로 돌아가서(BackTrack) 다음 경우를 탐색하게끔 구현할 수 있다.

👍 백트래킹 기법의 유망성 판단
어떤 노드의 유망성, 즉 해가 될 만한지 판단한 후 유망하지 않다고 결정되면 그 노드의 **이전(부모)로 돌아가(Backtracking) 다음 자식 노드로** 갑니다.

해가 될 가능성이 있으면 **유망하다**(promising)고 표현하며, 유망하지 않은 노드에 가지 않는 것을 **가지치기**(pruning) 한다고 표현한다.

## 백트래킹 구현하기
대표적으로 N과M , N-Queen 문제가 있다.(푼 다음에 보기를 추천)

![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbFQg5D%2FbtqFmuIYVJb%2Fo2ilY8jSBYMyHgRH1bhLhk%2Fimg.png)
![image](https://user-images.githubusercontent.com/72124326/213847205-5f026b8a-bf58-4dc6-9fd4-cc91b486a377.png)

두 문제 모두 재귀함수 속의 반복문, 방문 여부를 저장하는 isused 배열을 쓴다.
그러나 매몰되지 말자. 배열과 반복문은 도구이지, 백트래킹의 필수요소가 아니다.

중요한건 조합이고 **상태공간트리**다. 순열,조합의 연장선으로써 상태공간트리를 만들 수 있다면 모두 백트래킹으로 해결할 수 있다.

부분수열의 합 문제에서는 오로지 재귀함수만 쓰인다. 그럼에도, 철저하게 상태공간트리를 채우기 위한 코드이기 때문에 백트래킹이다.

![Screenshot from 2023-01-21 15-08-23](https://user-images.githubusercontent.com/72124326/213846692-7f149f20-d624-43cd-bbac-2ff55f6c578e.png)


## 참조
- https://blog.encrypted.gg/945
- https://jeongdowon.medium.com/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-backtracking-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0-13492b18bfa1
- https://chanhuiseok.github.io/posts/algo-23/


