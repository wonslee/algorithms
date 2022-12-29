/* 25501 재귀의 귀재
팰린드롬 : 기러기 토마토 스위스 우영우같이, 앞뒤 읽었을 때 같은 문자열.
문자열은 홀수 짝수 상관없음.

입력 :
첫째 줄에 테스트케이스의 개수 T가 주어진다. (1<=T<=1000)
둘째 줄부터 T개의 줄에 알파벳 대문자로 구성된 문자열 S가 주어진다.
(1<=|S|<=1000)

출력 :
각 테스트케이스(S)마다 isPalindrome 함수의 반환값과 recursion 함수의 호출 횟수를
한 줄에 공백으로 구분하여 출력한다.
*/

#include <stdio.h>
#include <string.h>

int count;

/* recursion :
parameter. 인자로 char array(s), 맨왼쪽의 인덱스, 맨오른쪽의 인덱스를 받는다.
1. 왼쪽 index가 오른쪽 index보다 크거나 같을 경우 1 반환
재귀의 마지막 단계에 해당. 이때까지 2번의 조건에 해당하지 않았으므로 성공인 셈?
2. 양쪽 index에 대한 s의 요소(char)가 다를 경우 0 반환
다를 경우, 팰린드롬의 정의에 반하므로 실패.
3. 나머지 경우, 자기자신을 재귀호출. 인자는 s, l+1, r-1
이런 식으로 왼쪽 index와 오른쪽 index를 맨끝에서부터 1씩 좁혀나간다. */
int recursion(const char *s, int l, int r) {
  count++;
  if (l >= r)
    return 1;
  else if (s[l] != s[r])
    return 0;
  else
    return recursion(s, l + 1, r - 1);
}

/* isPalindrome :
string(char pointer)을 받고 recursion을 호출.
인자값으로 해당 string, 0 (맨 왼쪽 index), strlen(s)-1 (마지막 index)를 전달.

이 부분은 main 함수로 옮겨도 될 듯.*/
int isPalindrome(const char *s) {
  // initialize count to 0
  count = 0;
  return recursion(s, 0, strlen(s) - 1);
}

int main() {
  unsigned int T;
    scanf("%i", &T);

// for (int i=0; i<T; i++){
//     // 이 길이가 맞나..?
//       int a;
//       scanf("%i", &a);
//         printf("a=%i\n", a);
//     }
    
  for (int i=0; i<T; i++){
    // 이 길이가 맞나..?
      char S[1000];
     
      scanf("%s", S);
      printf("%d ", isPalindrome(S));
      printf("%d\n", count);
  }
    return 0;
}
