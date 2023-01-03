/*
 # 문제 재정의와 추상화
X보다 작은 값의 개수 혹은 정렬된 집합일 때 X가 몇번째인지를 구하는 문제.

 # 계획
 unique, lower_bound 방법.

1. 원본 벡터를 입력 받고 원본벡터를 복사한 벡터를 만든다.
2. 복사 벡터를 정렬한 후 unique함수로 중복 값을 제거해준다.
3. 반복문으로 원본 벡터를 순서대로 확인한다.
4. lower_bound 함수를 통해 원본 벡터의 i 번째 원소가 복사본 벡터에서 몇번째에 위치 하는지 확인한다(이때 lower_bound는 주소값을 반환).
5. lower_bound의 반환 값에 시작 주소값을 빼준 값이 답이다.

 사실 값은 중요치 않은게 아닐까? X의 prime 값, 즉 X보다 작은 값이 몇개인지가 중요하다.

 # 계획 검증
 ## 시간 제한
 N <= 1000000 이므로 O(N log N)이하만 가능.
 O(N log N) + O(N) * 3 --> O(N log N)

 ## 메모리 제한
 512MB.
 struct는 int 3개를 담으므로 하나당 12byte, 1000000짜리 array가 있으므로 12000000byte = 12MB

 # 배운 점

 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    // original vector
    vector<int> v(n);
    // input
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // copied vector.
    vector<int> cv(v);

    // sort : increasing order
    sort(cv.begin(), cv.end());

    // 핵심 : unique, erase. 중복 제거
    cv.erase(unique(cv.begin(), cv.end()), cv.end());

    for (int i = 0; i < n; i++){
        // lower_bound. 원래 vector v의 i번째 원소와 같은 놈이 중복 제거된 복사 vector의 어디에 위치하는지
        auto it = lower_bound(cv.begin(), cv.end(), v[i]);
        // it에서 복사된 vector의 시작 주소값을 빼준 값이 답
        cout << it - cv.begin() << ' ';
    }

}
