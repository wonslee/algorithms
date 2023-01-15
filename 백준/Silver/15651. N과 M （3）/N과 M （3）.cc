/* 15651. N과 M (3)

# 문제 재정의
 N과 M 문제에서 '같은 수를 여러번 골라도 된다' 조건이 있음.
 기본적으로 조합을 구하는, 백트래킹 문제다.
# 계획
 visited[] 여부는 필요없다. 그냥 loop의 증가에 따라 계속 재귀호출.
 func(idx)
    기저사례. if(idx==m) 출력 후 종료

    loop(i=1 ~ n):
        현재 조합에 i 추가
        func(idx+1)
        현재 조합에서 i 제거

# 계획 검증

## 시간 복잡도
## 공간 복잡도
# 회고
 - 이 문제가 백트래킹의 가장 기본적인 틀이라는 생각이 든다. 여기서 조건에 따라 핵심 반복문에서 조건문 처리가 된다.
 가령 이 문제의 요구조건은 '중복되지 않는 조합들을 구해라'이다. '같은 수를 여러번 골라야 한다'라는건 사실상 조건이 없다는 거.
 N과 M(1)에선 '같은 수를 한번만 골라야 한다'였기 때문에 visited 변수(배열)를 써서 각 숫자의 중복 여부를 체크했고
 N과 M(2)에선 (1)의 조건에 더해서 '조합 내의 원소들은 오름차순이어야 한다'였기 때문에 start 변수를 써서 시작점을 높여나갔다.

 */

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

void func(int idx){
    // 기저사례. idx==m
    if(idx==m){
        for (int num : v) cout << num << ' ';
        cout << '\n';
        return;
    }

    for (int i=1; i<=n; i++){
        v.push_back(i);
        func(idx+1);
        v.pop_back();
    }
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}
