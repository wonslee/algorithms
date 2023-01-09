/* 1018. 체스판
 보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8×8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다.
 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.
 당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

 # 문제 재정의
 모든 경우의 수를 구하는 브루트포스 문제.
 8*8단위에서 어디에 색칠할지 여부를 구하는 것과, 8*8 단위를 어디서 시작할지를 고르는 문제.

 # 계획
 조각1. BWBW..순으로 한칸씩 체크하면서 count++
 조각2. 조각1을 8*8단위로 실행
 조각 2를 (M-7)(N-7)회 실행. 8*8 사각형을 만들 수 있는 모든 경우의 수를 뒤져야 한다.
 회로에서 카르노맵의 최소항을 구하는 과정과 비슷하다!

 조각1이 가장 어렵다. 기존에 주어진 보드를 맨 위쪽 왼칸을 B부터 시작할지 W부터 시작할지도 정해야 한다.
 2가지 경우에 대해, 아닌 칸은 count++ 해가면서 한칸씩 나아가면 된다.

 # 계획 검증
 
 ## 시간 복잡도
 M,N에 비례하는 4중 반복문이므로 대략 O(N^4).
 M과 N은 50보다 작거나 같으므로, 1초안에 충분히 실행된다.

 ## 공간 복잡도
 50*50의 char 배열이므로 2500byte.

 # 회고
 -
 */

#include <bits/stdc++.h>
using namespace std;

char board[50][50];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,M, smallest = 99999999;
    cin >> N >> M;

    // input
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }

    // 첫번째 loop( [0][0] ~ [M-8][N-8] )
    for (int I=0; I<N-7; I++)
        for (int J=0; J<M-7; J++){
            int b_count =0, w_count=0;
            // 두번째 loop( [i][j]부터 8*8칸 )
            for (int i=I; i<I+8; i++)
                for (int j=J; j<J+8; j++) {
                    // 짝수칸
                    if ( (i+j)%2 == 0 )
                        // b_count: 짝수칸인데 W이거나, 홀수칸인데 B인 경우 +1
                        // w_count: 짝수칸인데 B이거나, 홀수칸인데 W인 경우 +1
                        if (board[i][j] == 'W' ) b_count ++;
                        else w_count++;
                    // 홀수칸
                    if ( (i+j)%2 == 1 )
                        if (board[i][j] == 'B') b_count++;
                        else w_count++;
                }
            int min_count = min(w_count, b_count);
            // 최소값 갱신
            if (min_count < smallest) smallest = min_count;
        }
    cout << smallest;
}
