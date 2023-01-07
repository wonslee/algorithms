/* 2798.블랙잭
카드의 합이 M을 넘지 않는 한도 내에서, 3장의 카드의 합을 최대한 크게 만드는 게임
N(3 ≤ N ≤ 100) M(10 ≤ M ≤ 300,000)

 # 문제 재정의와 추상화
M에 최대한 가깝게 만든다는 점에서 본질적으로 블랙잭과 같다.
 결국 모든 경우의 수를 뒤져봐야 한다.
 경우의 수를 찾는 문제가 아니라, 가능한 경우의 수들 중에서 가장 M과 가까운 수를 구하는 문제.

# 문제 접근 과정
  e.g. n=5, m=21, 카드=5,6,7,8,9
 => (5,7,9) (6,7,8) 2가지 경우로 21이 나온다.

 # 계획
  closest 변수가 필요하다.
 모든 경우를 뒤지면서, closest < x <= M 조건을 만족할 때마다 계속해서 재할당해준다.
 loop (i=0 ~ n):
    loop(j=i+1 ~ n):
        loop(k=j+1 ~ n):
            if(closest < [i] + [j] + [k] <= M):
                closest = [i] + [j] + [k]

 # 계획 검증
 ## 시간 복잡도
 O(N^3)알고리즘에 N<=100이므로, 실행횟수는 1000000. 0.1초 안에 실행될것이나 10배 차이생각해야 하니까 1초.

 ## 공간 복잡도
 100짜리 배열이니까 400byte.ㅋㅋ

 # 회고
 - 브루트포스에 대해 더 알 수 있었다.
 - 2562 최댓값 문제랑 비슷하다는 생각이 든다. 그 문제와 차이점은 경우의 수나 조건문이 조금 더 복잡하다는 건데, 그럼 최댓값 문제도 브루트포스인건가?
 */

#include <bits/stdc++.h>
using namespace std;
vector<int> card;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, input;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> input;
        card.push_back(input);
    }

    int closest = -1;
    for (int i=0; i<n ; i++)
        for (int j=i+1; j<n; j++)
            for (int k=j+1; k<n; k++){
                int value = card[i] + card[j] + card[k];
                if (value > closest && value <= m)
                    closest = value;
                // Q. 실행횟수를 줄이기 위해 만약 m과 같다면 break를 거는건 어떨까?
            }
    cout << closest;
}
