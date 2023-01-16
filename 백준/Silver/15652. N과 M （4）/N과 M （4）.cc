/* 15652. N과 M (4)

# 문제 재정의
 N과 M 문제에서 '같은 수를 여러번 선택 가능', '비내림차순' 조건이 붙어있다.
 visited는 필요없고, start 변수를 써서 비내림차순 조건문을 구현해야 한다.
# 계획
 func(idx):
    기저사례. if(idx==m): 수열 출력, return
    for (i=1 ~ n; i >= v.end()): 핵심 백트래킹 반복문.
        배열에 push
        func(idx+1)
        배열 pop

# 계획 검증

## 시간 복잡도
 8Cm. 8*7*6*5 정도.
 push, pop연산은 O(1)이므로 시간 차지 별로 안 함.

## 공간 복잡도
# 회고
 */

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

void func(int idx){
    // 기저사례. idx==m일 경우 m개를 모두 고른 것
    if (idx==m){
        for (int num : v) cout << num << ' ';
        cout << '\n';
        return;
    }

    // 핵심 백트래킹 반복문
    for (int i=1; i<=n; i++){
        // 조건문: 비내림차순
        if (v.empty() || i >= v.back() ){
            v.push_back(i);
            func(idx+1);
            v.pop_back();
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}