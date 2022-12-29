#include <stdio.h>

void printList(int list[]) {
  printf("[ ");
  for (int i = 0; i < 11; i++) {
    printf("%i ", list[i]);
  }
  printf("]\n");
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

/* shellsort : sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n) {
    int gap = n;
  // 1. length를 gap에 할당. gap이 0이 되기 전까지, gap을 2로 나누면서 반복
  while (gap /= 2)
    // 2. i가 length안에서 gap index부터 끝 index까지 반복
    for (int i = gap; i < n; i++) {
      printf("gap=%i\t i=%i\n", gap, i);
      // 3. j index의 element가 gap만큼 뒤 index의 element보다 클 때 반복
      for (int j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap){
          printf("\tj=%i\t%i %i\n", j, v[j], v[j+gap]);
        swap(&v[j], &v[j + gap]); // 두 값을 swap.
      }
      printList(v);
    }
}

int main() {

  int arr[] = {10,8,6,20,4,3,22,1,0,15,16};

  printList(arr);

  shellsort(arr, sizeof arr / sizeof arr[0]);
}
