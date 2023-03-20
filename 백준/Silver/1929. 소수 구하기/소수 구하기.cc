/*
# 문제 재정의
 - 말 그대로 소수를 찾는 문
# 계획
# 복잡도 검증
 m-n은 최대 100000.
 is_prime은 root(n) => 0.1초안에 가능
# 회고
*/


#include <bits/stdc++.h>
using namespace std;

int n,m;

bool is_prime(int num) {
    if (num == 1) return false;
    for (int i = 2; i * i <= num; ++i) { // 2 ~ 제곱까지만
        if (num % i == 0)// 나눠지면 소수가 아니므로 0
            return false;
    }
    return true;
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = n; i <= m; ++i) {
        if(is_prime(i))
            cout << i << '\n';
    }

}