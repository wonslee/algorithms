
/* 병합 정렬

입력
첫째 줄에 배열 A의 크기 N(5 ≤ N ≤ 500,000), 저장 횟수 K(1 ≤ K ≤ 10^8)
다음 줄에 서로 다른 배열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 10^9)

출력
배열 A에 K 번째 저장 되는 수를 출력한다.
저장 횟수가 K 보다 작으면 -1을 출력한다.

문제접근
1. 데이터 : 배열 A, 저장횟수 K, A의 원소들
2. scanf
3. merge_sort 호출.

TODO 병합정렬 공부
https://www.programiz.com/dsa/merge-sort
*/

#include <stdio.h>

// 전역 변수
int N, K, count = 0, result = -1;

void merge(int A[], int p, int q, int r);
void merge_sort(int A[], int p, int r);

int main() {
  // 데이터 입력
  scanf("%d %d", &N, &K);
  int A[N];
  for (int i = 0; i < N; i++)
    scanf("%d", &A[i]);

  // merge_sort 호출
  merge_sort(A, 0, N - 1);
  // 출력
  printf("%i\n", result);
}

/* merge
 A는 배열. p,q,r은 index.
 A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
 A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
*/
void merge(int A[], int p, int q, int r) {
  int i = p;
  int j = q + 1;
  int t = 1;
  int tmp[500000];

  while (i <= q && j <= r) {
    if (A[i] <= A[j])
      tmp[t++] = A[i++];
    else
      tmp[t++] = A[j++];
  }
  // 왼쪽 배열 부분이 남은 경우
  while (i <= q)
    tmp[t++] = A[i++];
  // 오른쪽 배열 부분이 남은 경우
  while (j <= r)
    tmp[t++] = A[j++];
  // i, t 초기화
  i = p;
  t = 1;
  // 결과를 A[p..r]에 저장
  while (i <= r) {
    A[i++] = tmp[t++];
    if (++count == K)
      result = A[i - 1];
    /*    printf("A[%i]=%i\n",i-1 , A[i-1]); */
    /* for (int k = 0; k < 5; k++) { */
    /* if (k+1==i) printf("*"); */
    /* printf("%i ", A[k]); */
    /* } */
    /* printf("\n"); */
  }
}

void merge_sort(int A[], int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;     // q는 p, r의 중간 지점
    merge_sort(A, p, q);     // 전반부 정렬
    merge_sort(A, q + 1, r); // 후반부 정렬
    merge(A, p, q, r);       // 병합
  }
}
