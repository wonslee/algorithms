/* 합병 정렬
 * 분할 정복 기법에 바탕을 둔 정렬 방법.
 * 기본적으로 분할 과정에서 재귀 호출을 쓴다.
 * 
 * 분할 정복이라는 점에서 퀵 정렬과 비슷하고, 속도도 더 빠르다.
 * 그러나 합병 정렬은 추가적인 배열이 필요하다. (여기선 sorted[])
 *
 * 1. 분할: 입력 배열을 같은 크기의 2개 부분 배열로 분할
 * 2. 정복: 부분 배열을 정렬. 부분 배열의 크기가 충분히 작지 않으면, 순환호출을
 * 이용해 다시
 * 3. 결합: 정렬된 부분 배열들을 하나의 배열에 통합.
 *
 * 과정을 살펴보자.
 * 배열의 길이가 n이라고 할 때,
 * 1. 분할 단계: 최소 원소의 부분집합이 될 떄까지
 * 분할 작업을 반복--> 1개의 원소를 가진 부분집합 n개를 만든다.
 * 2. 합병 단계: 실제로 정렬이 이뤄지는 시점.
 * n개의 부분집합이 1개로 합병될 때까지 반복
 * --> 매번 두 개의 부분집합을 정렬하는 동시에 하나의 집합으로 합친다.
 *
 *  *
 * TODO 연결리스트로 구현해보기. 가장 효율적일 수 있다.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8

int myList[SIZE];
int sorted[SIZE];

void randomize() {
  srand(time(NULL));
  for (int i = 0; i < SIZE; i++)
    myList[i] = rand() % 100;
}
void printList(int list[], int left, int right) {
  printf("[ ");
  for (int i = left; i < right; i++)
    printf("%i ", list[i]);
  printf("]\n");
}

/* merge
 * */
// 2개의 인접한 배열 list[left...mid], list[mid+1...right]를 합병
void merge(int list[], int left, int mid, int right) {

// indexes
  int i = left, j = mid + 1, k = left;

  // 핵심: 분할 정렬된 list의 합병
  // 왼쪽(left~mid)과 오른쪽(mid+1 ~ right) 중에 더 작은 값을 계속해서 sorted
  // 배열에 넣는다.
  // &&(AND) 이어야 한다. ||(OR)로 했다간, i가 계속 늘어나서 생뚱맞은 배열의 값이 들어가게 되고 끝도 없다. 
  while (i <= mid && j <= right) {
    if (list[i] <= list[j])
      sorted[k++] = list[i++];
    else
    sorted[k++] = list[j++];
  }

  // 남아있는 레코드의 일괄 복사
  if (i > mid)
    while (j <= right)
      sorted[k++] = list[j++];
  else
    while  (i <= mid)
      sorted[k++] = list[i++];

  // 배열 sorted[] 리스트를 배열 list[]로 다시 복사
  for (int l = left; l <= right; l++)
    list[l] = sorted[l];

  printf("=== merge ===\n");
  printList(list, left, right + 1);
}

/* merge_sort
 * 1. 만약 나눠진 구간의 크기가 1 이상이어야 실행한다.
 * 2. 중간 index를 계산한다
 * 3. 앞쪽 파트를 정렬 (순환 호출)
 * 4. 뒤쪽 파트를 정렬 (순환 호출)
 * 5. 정렬된 2개의 파트 통합 (merge 호출)
 */
void merge_sort(int list[], int left, int right) {
  printf("\nmerge_sort--left=%i\tright=%i\n", left, right);
  printList(list, left, right + 1);
  // 반으로 쪼개기
  if (left < right) {

    int mid = (left + right) / 2;
    merge_sort(list, left, mid);
    merge_sort(list, mid + 1, right);
    // 실제로 정렬이 이루어지는 시점
    merge(list, left, mid, right);
  }
}

int main() {
  randomize();

  merge_sort(myList, 0, SIZE - 1);

}
