/*
# 문제 재정의
 - '-'이후에 오는 수를 최대한 크게 만들어서 최소값을 만들어야 한다. '+'가 나오는한 다 포함시키면 됨
 - 욕심많은 명제 : '-'가 나오는 순간 뒤의 모든 식들은 '-'가 된다. 왜냐하면 '+'도 거기안에 묶으면 되고 '-'는 또다른 '-'니까.
    가령 10-20+30-40+50-60은 10 -(20+30) - (40+50) - (60) 이 된다. 이건 즉, 맨 처음 '-'가 나온 순간 뒤에 뭐가 오든지간에 빼기가 된다.
# 계획
 입력 받는것도 문제다.. 일단 string으로 싹다 받은 다음에, - 뒤의 문자들을 하나로 묶어 계산을 처리하면 될 듯.

 1. LOOP : string의 각 char에 대해
 2. 각 연산자에 대한 CONDITION : '+'라면 그냥 진행. '-'라면, 또다른 '-'가 나오거나 식의 끝이 나올때까지 포함시킨다.
# 복잡도 검증
 - O(n). n은 string의 길이
# 회고
 - 그리디 알고리즘은 뭐랄까.. 그리디한 명제가 나올 수 있을 때만 쓸 수 있는 제한적인 알고리즘인듯하다.
 - stoi를 복습했다.
*/


#include <bits/stdc++.h>
using namespace std;

string s;
string tmp;
int ans;
bool is_minus;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;

    for (int i=0; i <= s.size(); i++) {
        // 숫자 : s[i]가 숫자일 경우, tmp에 하나하나 담는다. 나중에 숫자로 변환
        if (s[i] <= 57 && s[i] >= 48){
            tmp.push_back(s[i]);
        }else {// 숫자가 아닐 경우, 지금까지 '-'가 나온 적 있다면 쌓아놓은 tmp를 빼고, 아직 나온적 없다면 tmp를 더한다.
            if (is_minus)
                ans -= stoi(tmp);
            else
                ans += stoi(tmp);

            tmp.clear(); // tmp 초기화

            if (s[i] == '-')// - : is_minus를 참으로 한다.
                is_minus = true;
        }
    }
    cout << ans;
}