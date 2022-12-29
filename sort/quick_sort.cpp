/* quick_sort
 *
 * 퀵 소트는 분할 정복 알고리즘이다.
 * 핵심 과정은 partition과 재귀.
 *
 * partition은 말 그대로 배열을 어떤 수를 기준으로 반으로 쪼개는 것.
 * partition의 기준으로 쓰일 index을 pivot이라고 부르자.
 *
 * pivot을 정하는 방법은 다양하다.
 * 랜덤으로 정해도 되고, 마지막 혹은 첫번째로 정해도 된다.
 *
 * # quick_sort의 pseudo code
 * quickSort(arr[], low, high) {
    if (low >= high) return; // 배열의 길이가 2 이상이어야 한다.

    pi = partition(arr, low, high);
    quickSort(arr, low, pi – 1);  // Before pi
    quickSort(arr, pi + 1, high); // After pi
}

*/

/* C++ implementation of QuickSort
 * https://www.geeksforgeeks.org/quick-sort */
#include <iostream>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int low, int high) {
  int i;
  cout << "[ ";
  for (i = low; i <= high; i++)
    cout << arr[i] << " ";
  cout << "]" << endl;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // pivot
  int i = (low - 1);     // Index of smaller element and indicates
                         // the right position of pivot found so far

  cout << low << " ~ "<< high  << "\t\tpivot=" << pivot << endl<< endl;
  for (int j = low; j <= high - 1; j++) {
    // If current element is smaller than the pivot
    if (arr[j] < pivot) {
      i++; // increment index of smaller element
      cout << arr[i] << " <-> "<< arr[j] << endl;

      swap(arr[i], arr[j]);
    }
    printArray(arr, low, high);
  }
  cout << "swap... " << arr[i+1] << " <-> " << arr[high];
  swap(arr[i + 1], arr[high]);
      printArray(arr, low, high);
      cout << endl;

  return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high) {
  if (high - low > 0) {
    /* pi is partitioning index, arr[p] is now
    at right place */
    int pi = partition(arr, low, high);

    // Separately sort elements before
    // partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}


// Driver Code
int main() {
  int arr[] = {5,2,3,1,4,2,3,5,1,7};
  int size = sizeof(arr) / sizeof(arr[0]);
  quickSort(arr, 0, size - 1);
  cout << "Sorted array: \n";
  printArray(arr, 0, size-1);
  return 0;
}

// This code is contributed by rathbhupendra
