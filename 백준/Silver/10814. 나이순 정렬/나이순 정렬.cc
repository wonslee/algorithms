/*


 # 문제 재정의와 추상화
 중요한 데이터는 나이와 기존의 순서.
 sort를 하되, stable sort여야 한다...?


 # 계획
stable sort가 되어야 하므로, 삽입 혹은 병합 정렬을 해보자.
 첫번째. c++ sort (?). introsort를 쓰고, unstable sort이지만 한 번 시도.
 1. loop(n) : input 배열
 2. sort
 2. 출력

 두번째. counting sort
 나이의 범위가 1~200으로 작으므로 배열로 저장하기 적합하기 때문.
 대신 배열은 count가 아니라 string(이름)값을 담아야 할 거 같다.
 1. loop(n) : input의 나이에 따라 counting 배열의 index에 이름을 넣는다.
 2. loop(200) : counting 배열을 0번째부터 순회하면서 출력.

 # 계획 검증
 ## 시간 제한
 N <= 100000, 시간제한은 3초.
 삽입 정렬은 O(N^2) 이므로 시간초과.
 카운팅 정렬은 O(N+K)이므로 적합.
 병합 정렬은 O(N log N)이므로 적합.
 c++ sort도 O(N log N)이므로 적합.

 ## 메모리 제한
 메모리 제한은 256MB.
 카운팅 정렬은 vector[200]에 100000개 string 들어가니까 20000000 = 20MB
 병합 정렬은 100000개 string 배열을 2개 쓰므로 200000 = 0.2MB

 # 배운 점
- stable sort란 : 중복된 키를 순서대로 정렬하는 정렬 알고리즘
- 대표적인 Stable Sorting 알고리즘 : 삽입, 병합, 버블, 카운팅
 Unstable Soring 알고리즘: 선택, 힙, 쉘, 퀵
 - vector at() method
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,string> Person;
// 회원들의 나이, 이름 pair을 담는 counting 배열
vector<Person> v;

bool compare(Person p1, Person p2){
    return (p1.first < p2.first);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, age;
    string name;
    cin>>n;

    // counting sort : O(N+K)
    while(n--){
        cin >> age >> name;
        v.push_back({age,name});
    }

    stable_sort(v.begin(), v.end(), compare);

    // 출력 : 대략 O(N). 최대 실행 횟수 20,000,000
    for (int i=0; i<v.size(); i++)
        cout << v[i].first << " " << v[i].second << "\n";
}