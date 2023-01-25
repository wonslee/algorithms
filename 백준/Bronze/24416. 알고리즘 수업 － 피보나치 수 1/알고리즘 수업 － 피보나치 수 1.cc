#include <bits/stdc++.h>
using namespace std;

int N, count_1=1, count_2=0;
int f[41];

int fib_1(int n){// RECURSIVE
    if (n==1 || n==2)
        return 1;
    else{
        count_1++;
        return ( fib_1(n-1) + fib_1(n-2) ); // 5 -> 4
    }
}

int fib_2(int n){// DP
    f[1] = f[2] = 1;
    for (int i=3; i<=n; i++, count_2++)
        f[i] = f[i-1] + f[i-2];
    return f[n];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    fib_1(N);
    fib_2(N);
    cout << count_1 << ' ' << count_2;
}