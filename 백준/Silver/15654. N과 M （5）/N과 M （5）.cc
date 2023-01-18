/* 15654. N과 M(5)

# 문제 재정의
 조합 (백트래킹) 문제. 이거..그냥 기존의 N과 M에서 값들만 입력되는 문제다. 배열에 저장한 후에 반복문 돌리자.
 사전순으로 증가하는 순서... 미리 정렬해둬야 함. 이전의 N과M문제는 애초에 1부터 증가하는 숫자였음.

# 계획
 0. v[10000]
 1. loop(n) : input 배열(v)에 저장
 2. func(idx): idx번째 선택
        // 기저사례. idx==m일 경우 출력 후 종료
        loop(num in v): 배열에 대해서
            // visited가 아닐 경우
            v.push(num)
            isused[num]=true
            func(idx+1)
            v.pop()
            isused[num]=false
# 계획 검증


# 회고

 */

#include <bits/stdc++.h>
using namespace std;

int n,m, input;
vector<int> inputs;
vector<int> v;
bool isused[10001];

void func(int idx){
    // BASE CONDITION : 조합 하나 완성된 경우
    if (idx==m){
        for (int num : v) cout << num << ' ';
        cout << '\n';
        return;
    }

    for (int num : inputs){
        if (!isused[num]){ // 아직 선택 안 된 경우
            v.push_back(num);
            isused[num]=true;
            func(idx+1);    // BACKTRACK
            v.pop_back();
            isused[num]=false;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> input;
        inputs.push_back(input);
    }

    sort(inputs.begin(), inputs.end());

    func(0);
}