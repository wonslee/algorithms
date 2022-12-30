/*
문제접근
배열을 쓰자. 지금까지 총총이 혹은 전염자를 만난 사람들을 저장하기 위함.
탐색하는 로직을 만들자.
만약 춤추는중인 사람을 만났다면, 배열에 삽입.
그런데 그 사람 또한 춤추는중이라면, 무시.
배열은 총총이가 들어가있는 상태로 initialize

data:
int N, 배열의 길이 sizeof(people) / sizeof(people[0])
char* people[1000], input1, input2

1. loop: N만큼 반복.
    1-1. scanf: input1, input2
    1-2. loop: 배열에 input1, input2가 있는지 탐색.
    1-3. if 둘중 한명만 춤추는중: 나머지 한명을 배열에 삽입
    1-4. if 아무도 춤추지 않거나 둘 다 춤추는중: pass
2. printf: 배열의 길이


문제점
- 반복문의 3번째부터, 원래 있던 이전의 원소들 값이 바뀌었다.
이상한건, 삽입 로직 이전에 바뀌어있다는 점.

string array 기본기를 모르고 있었음!
char *arr[20]은 string이 아닌 char pointer가 20개 있는 배열...
-> char arr[20][70]으로 해야 길이 70인 string을 담는 배열이 된다.
https://stackoverflow.com/questions/7251307/using-strcpy-with-a-string-array-in-c

- c 언어 string의 특성 : 맨 끝에 \0 이 들어갈 자리를 줘야 함.
비교를 위해 strcmp, 복사를 위해 strcpy를 썼어야 함.
*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
  // data
  int N, number = 1;
  scanf("%i", &N);
  char people[1000][21] = {"ChongChong"};

  for (int i = 0; i < N; i++) {
    // 각각의 사람 데이터
    char x[21], y[21];
    bool is_x = false, is_y = false;
    scanf("%s %s", x, y);

    // 배열상에 x, y가 있는지 탐색
    for (int j = 0; j < number; j++) {
      // x가 이미 춤추고 있을 경우
      if (strcmp(people[j], x) == 0)
        is_x = true;
      // y가 이미 춤추고 있을 경우
      else if (strcmp(people[j], y) == 0)
        is_y = true;
    }

    // 분기처리. 둘중 한명만 춤추는 경우 해당 인원 삽입
    if (is_x && is_y) continue;
    else if (is_x)
      strcpy(people[number++], y);
    else if (is_y)
      strcpy(people[number++], x);

    /*  printf("[ "); */
    /* for (int j = 0; j < number; j++) printf("%s ", people[j]); */
    /* printf("]\n"); */
  }
  printf("%i", number);
}