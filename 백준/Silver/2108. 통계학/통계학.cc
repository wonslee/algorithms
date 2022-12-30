/*
# 문제 재정의와 추상화
중앙값, 범위의 경우 입력값들을 정렬해야 함.
산술평균과 최빈값은 정렬과는 관계 없고, 몇가지 기본적인 연산을 필요로 한다.

# 문제 접근
입력값의 범위는 그렇게 크지 않다. counting sort를 써도 될 것 같기는 하지만, 
메모리 제한이 256mb로 많은 편이므로 그냥 일반적인 sort를 쓰도록 하자.
정렬한 후, 
중앙값은 N이 홀수이므로 N/2 위치의 원소를 출력.
범위는 0, N-1 위치의 원소간의 차이 (절댓값) 출력. 
산술평균은 입력값들을 모두 더한 이후에 N으로 나눈 값을 출력. 입력값이 들어올 때 합을 계산하는 식으로.
최빈값은 모든 입력값에 대해 count...하기에는 범위가 넓은데? 그리고 조건이 걸린다. 두번째로 작은 값..
정렬되었으니, 같은 값들끼리는 옆 index에 옹기종기 있을것. 그러면 연산이 복잡할 것 같지는 않다.

최빈값을 위해, counting sort를 이용하자.

 1. loop(n) : 입력값을 배열에 할당, sum에다 더해나감
 2. 산술평균 출력
 3. 중앙값 출력 (indexing)
 4. 최빈값 과정.. counting sort를 한 다음, 최빈 횟수와 동일한 값이 있는 index+4000을 출력
 5. 범위 출력 (indexing)
*/
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_SIZE 500000

vector<int> arr; // 2MB
int counts[8001] = {0, }; // 정수들의 범위 : -4000 ~ 4000

int partition(vector<int> arr, int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates

    for (int j = low; j <= high - 1; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);

    return (i + 1);
}

void quick_sort(vector<int> arr, int low, int high) {
    if (high - low > 0) {
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition(arr, low, high);
        // Separately sort elements before partition and after partition
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main(){
    int n, input, mode_count = 0;
    int sum = 0;

    scanf("%i", &n);

    // 1. 입력값 처리
    for (int i=0; i<n; i++){
        scanf("%i", &input);
        arr.push_back(input);
        sum += input;
        // counting sort
        counts[input+4000] ++;
        // 최빈 횟수를 구하는 과정
        if (counts[input+4000] > mode_count)
            mode_count = counts[input +4000]; // 최빈값 count 갱신
    }

    sort(arr.begin(), arr.end());

    // 2. 산술평균. 첫째자리 반올림 야매로 성공
    float average = round ((float)sum / n);
    cout << (abs(average) > 0.5 ? average : 0) << endl;

    // 3. 중앙값
    cout << arr[n/2] << endl;

    // 4. 최빈값
    int mode = 5000;

    // mode_count에 따라, counting sort 배열에서 결과값을 출력
    bool is_second=  false;
    for (int i=0; i<8001; i++)
        if (counts[i]==mode_count){
            mode = i-4000;
            // 최빈값이 하나일 경우, 아래의 문장들은 의미 없음.
            if (is_second)
                break;
            is_second = true;
        }
    cout << mode << endl;

    // 5. 범위
    int range = abs(arr[0] - arr[n-1]);
    cout << range << endl;
}
