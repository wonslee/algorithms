## 백트래킹이란?
“A technique for listing all possible solutions for a **combinatorial** algorithm problem.”

좀 더 이해하기 쉽다. 백트래킹은 어떤 테크닉인데 ‘조합 알고리즘 문제’에 대해 모든 가능한 해를 나열하는 것이다.
![image](https://user-images.githubusercontent.com/72124326/212021858-e3b7c7b6-14d0-4120-a21d-4ac4536af35c.png)

백트래킹은 **모든 조합의 수**를 살펴보는 것인데 단 조건이 만족할 때 만이다. 모든 경우의 수를 모두 찾는 것보다 ‘경우에 따라' 훨씬 빠를 수 있다. 

## 깊이 우선 탐색(DFS)과 백트래킹

DFS는 가능한 모든 경로(후보)를 탐색합니다. 따라서, 불필요할 것 같은 경로를 사전에 차단하거나 하는 등의 행동이 없으므로 경우의 수를 줄이지 못합니다.
주로 문제 풀이에서는 DFS 등으로 모든 경우의 수를 탐색하는 과정에서, 조건문 등을 걸어 답이 절대로 될 수 없는 상황을 정의하고,  
그러한 상황일 경우에는 탐색을 중지시킨 뒤 그 이전으로 돌아가서 다시 다른 경우를 탐색하게끔 구현할 수 있습니다.

👍 백트래킹 기법의 유망성 판단
어떤 노드의 유망성, 즉 해가 될 만한지 판단한 후 유망하지 않다고 결정되면 그 노드의 **이전(부모)로 돌아가(Backtracking) 다음 자식 노드로** 갑니다.

해가 될 가능성이 있으면 **유망하다**(promising)고 하며, 유망하지 않은 노드에 가지 않는 것을 **가지치기**(pruning) 한다고 하는 것입니다.

## 참조
- https://jeongdowon.medium.com/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-backtracking-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0-13492b18bfa1  
- https://chanhuiseok.github.io/posts/algo-23/
