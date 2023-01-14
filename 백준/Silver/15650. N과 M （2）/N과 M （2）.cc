/* 15650. N과 M (2)

# 문제 재정의
 15649와 백트래킹이라는 점에서 본질적으로 같다.
 '오름차순'이라는 조건이 붙었다. 따라서 여기서는 낮은 숫자에 대해선 visit을 하지 않는다.

# 계획
 func(idx):
    기저사례. idx==m일 경우 하나의 조합이 완성된 것이므로 출력 후 종료.
    loop(num=1 ~ N) : 핵심 백트래킹 반복문
        if(i가 아직 방문되지 않았고 && i가 v의 마지막 원소보다 클 경우):
            v.push(num)
            visited[num] = true
            func(idx+1)
            v.pop()
            visited[num] = false



# 계획 검증



## 시간 복잡도
## 공간 복잡도
# 회고
 - vector의 back() 메소드는 empty와 같이 쓰이는게 좋다. 길이 0일 때 쓰면 에러.
 - 반복문 방식으로는 8개의 중첩 반복문을 써서 꽤나 더럽게 구현되는데, 백트래킹에서는 N의 크기에 따라 실행횟수가 결정된다는게 새삼 신기하다.
 - N이 고정되어 있는 경우엔 반복문 방식이 편할거다. 그냥 N개의 중첩 반복문을 써서 i=1 j=i+1 k=j+1 ... 식으로 구현하면 되니까. 
 그러나 'N(몇개를 선택할지)이 여러가지'인 경우에, 즉 조합의 경우에 백트래킹만한게 없다!
 */

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
bool visited[10];

void func(int idx){
    // 기저사례. idx == m일 경우 하나의 조합이 완성된 것이므로 출력 후 종료.
    if (idx==m){
        for (int num : v) cout << num << ' ';
        cout << '\n';
        return;
    }

    // 핵심. 백트래킹 반복문
    for (int num=1; num<=n; num++){
        // 아직 방문되지 않았고 && 오름차순 조건을 만족할 때.
        if (!visited[num] && ( v.empty() || num > v.back() ) ){
            v.push_back(num); // push
            visited[num]=true;
            func(idx+1);    // recursion
            v.pop_back();
            visited[num]=false;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}
