/* N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

 입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 단, N은 홀수이다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

출력
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

둘째 줄에는 중앙값을 출력한다.

셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

넷째 줄에는 범위를 출력한다.*/
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
산술평균은 입력값들을 모두 더한 이후에 N으로 나눈 값을 출력. 산술평균은 입력값이 들어올 때 합을 계산하는 식으로.
최빈값은 모든 입력값에 대해 count...하기에는 범위가 넓은데? 그리고 조건이 걸린다. 두번째로 작은 값..
정렬되었으니, 같은 값들끼리는 옆 index에 옹기종기 있을것. 그러면 연산이 복잡할 것 같지는 않다.

일반적인 sort를 쓸 경우, 최빈값에서 막힐 것 같다. 
counting sort를 쓸 경우는..

## quick sort
합병 정렬과 마찬가지로 분할정복 알고리즘.
특정 원칙에 정한 pivot을 기준으로 왼쪽, 오른쪽으로 나누는 partition 과정이 핵심.  

# 계획 검증
최빈값..
*/
#include <cmath>
#include <iostream>
using namespace std;

#define MAX_SIZE 500000

int arr[MAX_SIZE];

// partition
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low -1;
    for (int j=low; j<=high-1; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);

    swap(arr[i+1], arr[high]);
    return i+1;
}

// quick sort
void quick_sort(int arr[], int low, int high){
    if (high > low){
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

int main(){
    int n;
    cin >> n;

        float sum = 0; 
    for (int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    // 산술평균. 첫째자리 반올림..
    float average = round (sum / n);
    cout << ( abs(round(average)) > 0.5 ? round(average) : 0) << endl;

    quick_sort(arr, 0, n-1);
    
    // 중앙값
    cout << arr[n/2] << endl;
    // 최빈값
    // TODO count의 배열을 만들어서 최빈수들의 리스트를 만들어보기.
    int mode_count = 0, count=0, temp = arr[0], mode = 5000 ;
    for ( int i=0; i<n; i++){
        // 다음 원소일 때
        if (arr[i] != temp){
            temp = arr[i];
            count = 0;
        }

        count ++;

        // 지금까지 가장 많은 놈일 때
        if (count >= mode_count){
            mode = arr[i];
            mode_count = count;
        }
        // ?? 두번째로 작은 값
    }
            cout << mode << endl;

    // 범위
    cout  << abs(arr[0] - arr[n-1]) << endl;
}
