/* M-이동평균
 *
 * N개의 측정치와 M이 주어질 때,
 * 매달 M달 간의 이동 평균을 계산해라. */

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> weight;
int execute_count = 0;

vector<double> movingAverage1(vector<double> &A, int M) {
  vector<double> ret;

  // 각 i마다 A[i]까지의 이동 평균 값 구하기
  for (int i = M - 1; i < A.size(); i++) {
    double sum = 0;
    cout << "i=" << i << endl;
    for (int j = 0; j < M; j++) {
      cout << "\tj=" << j << "\tA[" << i - j << "]=" << A[i - j] << endl;
      sum += A[i - j];
      execute_count++;
    }

    ret.push_back(sum / M);
  }
  return ret;
}

vector<double> movingAverage2(vector<double> &A, int M) {
  vector<double> ret;

  double sum = 0;
  int M_th_index = M - 1;
  // 일단 0~M-1 더하기
  for (int i = 0; i < M_th_index; i++)
    sum += A[i];

  // 중복되는 연산 줄이기
  // 일단 M개가 되어야 M-이동평균을 구할 수 있으므로, M-1부터 끝까지 반복
  for (int i = M_th_index; i < A.size(); i++) {
    cout << "sum=" << sum << "\tA[" << i << "]=" << A[i] << "\tA[" << i - M + 1
         << "]=" << A[i - M + 1] << endl;
    // 맨 앞의 값은 빼고, 맨 뒤 값을 더한다.
    sum += A[i];
    ret.push_back(sum / M);
    sum -= A[i - M_th_index];

    execute_count++;
  }
  return ret;
}

int main() {
  int n = 10, m = 5;
  srand(time(NULL));
  while (n--)
    weight.push_back(n * 10);

  vector<double> result = movingAverage2(weight, m);

  for (double element : result)
    cout << element << endl;

  cout << "execute_count = " << execute_count << endl;
}
