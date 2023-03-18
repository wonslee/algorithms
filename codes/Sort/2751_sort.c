/*
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는
수가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는
중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

O(NlogN)으로 풀어야 한다.

# 문제 재정의와 추상화
문제가 깔끔해서 재정의가 쉽다.
N개의 수를 오름차순으로 정렬한 결과를 출력한다.

# 문제 접근
정렬의 방법은 여러가지지만, 시간복잡도 때문에 병합정렬을 쓰자.

## 병합 정렬
1. 길이 n의 배열을 n개의 단일 원소 집합으로 분할
2. 2개의 쪼개진 배열을 매번 병합(merge)하면서 정렬한다.
merge에서 왼쪽과 오른쪽을 나누는 index가 중요하다.


## 로직
1. 입력 : n
2. loop(n) : 입력받아서 arr 생성
3. merge_sort(arr, 0, n-1)
*/
#include <stdio.h>
#define SIZE 1000000

int arr[SIZE];
int sorted[SIZE];

void printList(int list[], int left, int right) {
  for (int i = left; i < right; i++)
    printf("%i ", list[i]);
}

void merge(int arr[], int left, int mid, int right) {
  int i = left, j = mid + 1, k = left;

  // 정렬용 배열에다 두 배열중 가장 작은 값을 넣어간다.
  while (i <= mid && j <= right)
    if (arr[i] < arr[j])
      sorted[k++] = arr[i++];
    else
      sorted[k++] = arr[j++];

  // 남아있는 원소들 일괄 복사
  if (i > mid)
    while (j <= right)
      sorted[k++] = arr[j++];
  else
    while (i <= mid)
      sorted[k++] = arr[i++];

  // 똑같이 만들기
  for (int l = left; l <= right; l++)
    arr[l] = sorted[l];
}

void merge_sort(int arr[], int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

int main() {
  int n;
  scanf("%i", &n);
  // make array
  for (int i = 0; i < n; i++) 
    scanf("%i", &arr[i]);
  
  merge_sort(arr, 0, n - 1);

  // print
    for (int i = 0; i < n; i++)
        printf("%i\n", arr[i]);
}
