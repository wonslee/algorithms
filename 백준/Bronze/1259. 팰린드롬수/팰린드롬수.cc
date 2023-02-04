/*
# 문제 재정의
 팰린드롬수..
 문자열(배열)의 양쪽 끝을 확인해나가는 문제.

# 계획
# 복잡도 검증
# 회고
*/

#include <bits/stdc++.h>
using namespace std;

string s;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> s;
        if (s == "0") return 0;
        bool is_pel=true;

        for (int i=0; i<s.size() / 2 ; i++){
            if (s[i] != s[s.size()-1-i]){// CONDITION: 각 자릿수가 펠린드롬수인지 여부
                is_pel = false;
                break;
            }
        }

        if (is_pel)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}