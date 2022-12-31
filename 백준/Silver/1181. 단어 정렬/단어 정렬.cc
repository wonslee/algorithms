/*
 단어 정렬
 1. 길이가 짧은 것부터
 2. 길이가 같으면 사전 순으로

 조건 :  같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.

 # 문제 재정의와 추상화
 string간의 sort.
 조건에 따라 확인을 하거나 집합을 쓰는 등 중복을 방지해야 한다.

 # 문제 접근
 첫번째. 조건 때문에 중복된 단어에 대한 검사 실행.. O(N^2)여서 시간초과
 두번쨰. 애초에 set을 써서 삽입한 뒤에, vector로 변환 한 후 sort.

 1. 입력
 2. loop(n) : 중복 검사 후 vector에 삽입
 3. sort. 여기서 compare은 string에 대한 문제 조건에 따라서.
 4. loop(n) : 출력

 # 계획 검증
 첫번째 loop에서 중복 검사(find)를 하는 과정이 걸린다. N^2이 되는 것 같은데..

 ## 입력값 다시보기
 N은 최대 20000. 문자열의 길이는 최대 50.

 ## 시간 복잡도
 생각해보니, N * 최대 길이 = 1000000. O(N log N) 알고리즘으로 풀어야 가능.

 ## 공간 복잡도
 모든 string 입력값이 50길이 일때 50byte, 최대 20000개이므로 1000000byte = 1MB.
 # 배운 점
 */

#include <bits/stdc++.h>
using namespace std;

set<string> s;
vector<string> v;

bool compare(string x, string y){
    // 1. 길이 비교
    if (x.length() < y.length()) return true;
    // 2. ascii값 비교
    else if (x.length() == y.length() && x < y) return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    string input;

    // 입력값들을 set에 삽입
    while (n--){
        cin >> input;
        s.insert(input);
    }

    // vector로 옮기기
    for (string element : s)
        v.push_back(element);

    // sort
    sort(v.begin(), v.end(), compare);

    for (string element : v)
        cout << element << endl;
}