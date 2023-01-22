/*
# 문제 재정의
 deque을 구현하는 문제.
 c++ STL deque에 대부분의 메서드가 있는 것 같다.
 중요한건 입력값에 대한 분기처리. 특히 공백이 포함된 string을 어떻게 처리하고 숫자를 삽입할지가 관건.
# 계획
# 계획 검증
 조건문이 아무리 복잡해도 어디까지나 O(n).
 n의 최대값이 10000이므로 0.01초
# 회고
 */

#include <bits/stdc++.h>
using namespace std;

int n, num;
string cmd;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--){
        cin >> cmd;

        // CONDITION.
        if (cmd=="front")
            cout << (dq.empty() ? -1 : dq.front()) << '\n';
        else if (cmd=="back")
            cout << (dq.empty() ? -1 : dq.back()) << '\n';
        else if (cmd=="size")
            cout << dq.size() << '\n';
        else if (cmd=="empty")
            cout << dq.empty() << '\n';
        else if (cmd=="push_front"){
            cin >> num;
            dq.push_front(num);
        }
        else if (cmd=="push_back"){
            cin >> num;
            dq.push_back(num);
        }
        else if (cmd=="pop_front"){
            if (dq.empty()) cout << -1 << '\n';
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (cmd=="pop_back"){
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
    }
}
