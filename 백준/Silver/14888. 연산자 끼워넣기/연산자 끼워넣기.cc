/*
# 문제 재정의
 숫자 수열은 고정되어 있고, 연산자들을 어디에 넣을지 선택하는 조합 문제.
 가능한 모든 조합을 구하면서 그 결과의 최대값과 최소값을 갱신해나가면 된다.

# 계획
 상태공간트리를 따져보자!
 첫번째 숫자에서 시작 -> op[4]에 있는 연산자만큼 서브트리가 갈라진다. 다음 숫자는 고정적이기 때문에 변수가 되지 않는다.
 FUNCTION(idx,tot):
    BASE CONDITION:
        idx==n-1일 때 조합 완성. tot의 값에 따라 최대값 혹은 최소값 갱신 후 종료
    BACKTRACK:
        op[]에 존재하는 연산자별로 싹 다 BACKTRACK.
        FUNCTION(idx+1, tot +(- * /) v[idx+1])
# 계획 검증
연산횟수는 대충 3^(n-1).
n은 최대 11이므로 ...59049?
 2초를 준것 치고는 너무 적은데.

# 회고
 - 이번엔 상태공간트리를 잘 썼다.
 - 이 문제는 반복문 필요없이 재귀만으로 구현됐다. 왜 반복문이 있을거라고 생각한거지? '수열'이라는 단어에 낚여서 배열을 순회해야한다고 생각했나보다.
 */


#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n, input, max_value=-987654321, min_value=987654321;
int op[4]; // 각 연산자의 개수 count 배열

void func(int idx, int tot){
    // BASE CONDITION: 조합 완성된 경우, tot의 값에 따라 최대값 최소값 갱신 후 종료
    if (idx == n-1){
        if(tot > max_value) max_value = tot;
        if (tot < min_value) min_value = tot;
        return;
    }

    // CONDITION: op[]에 존재하는 + - * / 연산자별로, 연산자 개수 줄이면서 BACKTRACK
    if (op[0] > 0){
        op[0]--;
        func(idx+1, tot + v[idx+1]);
        op[0]++;
    }
    if (op[1] > 0){
        op[1]--;
        func(idx+1, tot - v[idx+1]);
        op[1]++;
    }
    if (op[2] > 0){
        op[2]--;
        func(idx+1, tot * v[idx+1]);
        op[2]++;
    }
    if (op[3] > 0){
        op[3]--;
        func(idx+1, tot / v[idx+1]);
        op[3]++;
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> input;
        v.push_back(input);
    }
    for (int i=0; i<4; i++){
        cin >> op[i];
    }

    func(0, v[0]);
    cout << max_value << '\n' << min_value;
}