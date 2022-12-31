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
 두번째. 애초에 set을 써서 삽입한 뒤에, vector로 변환 한 후 sort.
 세번째. 정렬된 이후엔 어차피 인접해서 나타나니까, 똑같다면 무시하면 된다.

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
 - 처음 생각했던 방식에서 조금만 더 생각해보면 다른 인사이트가 나올 수 있다. 이번엔 'sort된 이후에 같은 단어끼리는 인접'하다는 포인트를 놓쳤다. 단순히 index 한칸씩만 확인하면 되는 일을, 전체에 대한 O(N) 검사로 만들었다.
 - unique() 함수도 있다..
 */

#include <bits/stdc++.h>
using namespace std;

string arr[20000];

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

    // 입력값들을 set에 삽입
    for (int i=0; i<n; i++)
        cin >> arr[i];
    

    // sort
    sort(arr, arr+n, compare);

    for (int i=0; i < n; i++){
        // 인접하고 같은 string이 있다면 무시
        if (i >0 && arr[i] == arr[i-1])
            continue;
        else
            cout << arr[i] << "\n";
    }
}