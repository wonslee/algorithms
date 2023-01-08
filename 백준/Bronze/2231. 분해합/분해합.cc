/* 2231. 분해합

 # 문제 재정의와 추상화
 생성자에 대한 공식은 모른다. 브루트포스외에 방법이 없다.
 각 자릿수를 더하는 문제도 있다.

 # 계획
 분해합을 구하는 과정은 입력값 i를 계속 10으로 나누면서 10에 대한 나머지를 더해나간다. 마지막에 i를 더하면 끝.

 pseuodo code.

 int smallest = 정수 최대값
 loop(N-1 ~ 0):
    sum = i에 대한 분해합
    if ( == N && sum < smallest)
        smallest = sum

 if (smallest == 정수최대값):
    0 출력
 else:
    smallest 출력

 # 계획 검증

 ## 시간 복잡도
 기본적으로 n에 비례하는 반복문 한번이므로 O(target).
 변수가 있다면 각 자릿수를 더하는 과정에서 걸리는 시간. 여기서 O(K)가 걸릴 것 같다. K는 i의 자릿수.
 대충 O(KN)이 걸린다.

 ## 공간 복잡도

 # 회고

 */

#include <bits/stdc++.h>
using namespace std;

// summ : num의 분해합을 구한다.
int summ(int n){
    int result = n;
    // 정수 n의 자릿수를 어떻게 구하지?
    for (;n;n/=10)
        result += n%10;

    return result;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    const int INF = 99999999;
    int target, smallest = INF;
    cin >> target;

    // loop(N-1 부터 0까지): 가장 작은 생성자 구하기
    for (int i=target-1; i>=0; i--){
        // 정수의 분해합이 n과 같고, 현재 나온 생성자들중 가장 작을 경우 --> 갱신
        if (summ(i) == target && i < smallest)
            smallest = i;
    }

    if (smallest == INF)
        cout << 0;
    else
        cout << smallest;
}
