/* C++ implementation of QuickSort
 * https://www.geeksforgeeks.org/quick-sort */
#include <stdio.h>
#include <stdlib.h>

// swap : swap two elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
void printArray(int arr[], int size){
    printf("[ ");
    for (int i=0; i<size; i++)
        printf("%i ", arr[i]);
    printf("]\n");
}

/* partition : This function takes last element as pivot */
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // pivot
  int i = (low - 1);     // Index of smaller element and indicates

  for (int j = low; j <= high - 1; j++) {
    // If current element is smaller than the pivot
    if (arr[j] < pivot) 
      swap(&arr[++i], &arr[j]);
    printArray(arr, 5);
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

/* QuickSort */
void quickSort(int arr[], int low, int high) {
  if (high - low > 0) {
    /* partitioning index*/
    int pi = partition(arr, low, high);

    // Separately sort elements before partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main() {
    int n, k;
    scanf("%i %i", &n, &k);

    int *arr = calloc(n, sizeof(int));

    // 성적 배열 생성
    for (int i=0; i<n;i++)
        scanf("%i", &arr[i]);
    
  /* quickSort(arr, 0, n- 1); */
  qsort(arr, n, sizeof(int), compare);

  printf("%i", arr[n-k]);
  return 0;
}
