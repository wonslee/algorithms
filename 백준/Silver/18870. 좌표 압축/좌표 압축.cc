/*
 # 문제 재정의와 추상화
X보다 작은 값의 개수 혹은 정렬된 집합일 때 X가 몇번째인지를 구하는 문제.

 # 계획
 모든 다른 원소에 대해서 값을 비교하자니 시간 복잡도가 너무 높다.
 counting sort를 하자니 10GB가 필요...

 값과 순서에 대해 c++ sort를 쓰자.
 
 일단 값과 순서를 함께 배열에 저장한 다음,
 값에 대해 O(N log N) 정렬 알고리즘을 쓰고,
 다시 반복문을 통해 순서에 맞게 배열에 저장 후 출력...

 1. 입력되는 순서대로 배열 생성 : O(N)
 2. X 값에 대해 sort : O(N log N)
 3. 각 자리의 prime 값을 할당 : O(N)
 4. 처음의 순서대로 sort : O(N log N)
 5. 처음에 입력된 순서대로 prime 값을 출력 : O(N)

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

typedef struct {
    int value, sequence, prime;
}Point;
// 좌표의 값, 순서 pair을 담는 counting 배열
Point p[1000000];

// compare_value : 값에 대한 오름차순 비교
bool compare_value(Point p1, Point p2){
    return (p1.value < p2.value);
}
bool compare_sequence(Point p1, Point p2){
    return (p1.sequence < p2.sequence);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // input
    int n; cin>>n;
    for (int i=0; i<n; i++){
        cin >> p[i].value ;     // 값
        p[i].sequence = i;        // 순서
    }

    // sort by value
    sort(p, p+n, compare_value);

    // 각 자리에 해당 값의 prime값을 할당. value에 따라 sort된 이후에 가능
    for (int i=0, s=0; i<n;i++ ){
        // 정렬되어있는 상태에선 같은 값들끼리 인접해있다는 성질 이용. 단, index > 0 이어야 함.
        if (i>0 && p[i].value != p[i-1].value)
            s++;
        p[i].prime = s;
    }

    // sort by sequence
    sort(p,p+n, compare_sequence);

    // output (by original sequence)
    for (int i=0; i<n; i++)
        cout << p[i].prime << " " ;
}