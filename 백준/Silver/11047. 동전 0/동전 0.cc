/*
# 문제 재정의
 - 신호진 교수가 그리디를 설명하면서 얘기했던 동전 문제 ㅋㅋㅋ
 - 경우의 수 문제. K원을 충족하면서 동전 개수를 최소값으로 하는 경우를 찾아야 한다. DP, 백트래킹이 생각난다.
# 계획
 DP로 푼다면, d[i] = min(d[i-A1], d[i-A2], ...) + 1. 초기값은 각 D[Ai] 마다 1을 할당해주는것.
 이 방식은 O(N*K)로, 10억번의 연산을 하기 때문에 1초안에 통과될 수 없다.

 증명하자.

 - 보조 정리 1.
    동전을 최소로 소모하면서 물건값을 지불하려면 10/100원 동전은 4개 이하, 50원 동전은 1개 이하로 사용해야 한다.
    증명 : 10/100원 동전을 5개 이상 사용 -> 50/500원 동전으로 대체, 50원 동전을 2개 이상 사용 -> 100원 동전으로 대체
 - 핵심 명제.
    동전을 최소로 소모하면서 물건값을 지불하려면 500원 동전을 최대한 많이 써야 한다.
    10,50,100원 동전으로는 물건값을 최대 10*4 + 50*1 + 100*4 = 490원만 감당 가능. 500원을 다 사용하지 않을 경우 너무 많아짐.
    500, 100, 50, 10 순서로 많이 사용할수록 좋다. 그리디!
# 복잡도 검증
# 회고
 - DP 방법도 생각해내지 못했다... 문제 있는데 이거?
 - https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x11/solutions/11047.cpp
 - 그러면 이게 옳은 풀이인가? 1,9,10원이 있고 18원을 구해야 할 때의 답도 틀리게 알아내는 이상한 알고리즘인거 아닌가?
 - 아니었다...!!! 특이한 조건이 하나 있어서 그리디 알고리즘을 적용 할 수 있다.
    " i ≥ 2인 경우에 Ai는 Ai-1의 배수 "
*/


#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[15]; // 동전 배열

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n-1; i >= 0; i--){
        ans += k / a[i]; // 각 a[i]로 k를 나눈 몫을 더해준다. 이렇게 되면 가장 효율적으로 구할 수 있게 된다.
        k %= a[i]; // k를 a[i]로 나눈 나머지로 만든다.
    }
    cout << ans;
}