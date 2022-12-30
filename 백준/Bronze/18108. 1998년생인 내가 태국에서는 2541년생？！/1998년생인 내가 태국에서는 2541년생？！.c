#include <stdio.h>

/*  1998 -> 2541 이므로 불기는 서기 543년.
=> 불기 연도 - 543년 = 서기 연도 */
int main(){
  int buddhaYear;
  scanf("%d", &buddhaYear);
  int jesusYear = buddhaYear - 543;
  printf("%d", jesusYear);
  return 0;
}