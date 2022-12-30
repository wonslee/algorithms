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