/*
# 문제 재정의
 정수론 문제. 소수를 구해야 함.
# 계획
 - 무식하게 O(n^2)으로 하나하나 나눠보면서 COUNT해보기.
# 복잡도 검증
# 회고
*/

#include <bits/stdc++.h>
using namespace std;

int n, input, cnt;
bool flag;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> input;

        if (input != 1)
            for (int j=2; j <= 1000; j++){
                if(input==j){//
                    cnt ++;
                    break;
                }
                else if(input % j == 0) {
                    break;
                }// 어떤 자연수로 나누어 떨어질 때
            }
    }
    cout << cnt;
}