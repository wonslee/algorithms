/*
# 문제 재정의
 스티커를 직사각형 board에 놓은 후에 채워진 칸의 개수를 구하는 문제.
 백트래킹도 아니고 그냥 DIR과 반복문의 문제 아닌가?

 우선 스티커를 붙일 수 있는 위치를 구하고, 없다면 회전해서 붙일 수 있는지를 구한다.
 그렇게 차례대로 모든 스티커에 대해 순회한 후 채워진 칸의 개수를 구한다.
# 계획
 노트북 board와 모눈종이 paper은 2차원 배열.
 board 각 칸의 상태를 저장하자. 0이면 공백, 1이면 채워진 칸.

 LOOP(4방향):
    LOOP(0~n-r):  
        LOOP(0~m-c):
            pastable(x,y): 붙일 수 있는지 없는지 여부 반환. 있으면 바로 스티커 붙임
    rotate(): 회전

# 복잡도 검증
# 회고
 - 90도 회전시의 각 좌표간의 수학적인 패턴을 보는게 중요했다.
 - 정말 시뮬레이션은 빡구현이구나

*/

// http://boj.kr/6a7f35306b1446b1b01b057263879295
#include <bits/stdc++.h>
using namespace std;

int n, m, k, r, c;
bool note[42][42];
bool paper[12][12];

// rotate: paper를 90도 회전
void rotate(){
    int tmp[12][12];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            tmp[i][j] = paper[i][j]; // paper 복사

    for(int i = 0; i < c; i++) // 90도 회전하므로 행과 열이 서로 바뀜
        for(int j = 0; j < r; j++)
            paper[i][j] = tmp[r-1-j][i];

    swap(r, c);
}

// pastable: note의 (x,y)에 모눈종이의 (0,0)이 올라가게 스티커를 붙일 수 있는지 판단하는 함수. 가능할 경우 note를 갱신한 후 true를 반환.
bool pastable(int x, int y){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(note[x+i][y+j] == 1 && paper[i][j] == 1) // 두 칸 모두 있을 경우, false반환하면서 함수 종료
                return false;
        }
    }
    // true인 상태
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(paper[i][j] == 1)// 스티커의 각 칸에 대해 (x,y)를 축으로 해서 채워나가기
                note[x+i][y+j] = 1;
        }
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    while(k--){
        cin >> r >> c;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> paper[i][j];

        for(int rot = 0; rot < 4; rot++){// 4방향에 대해
            bool is_paste = false; // 해당 스티커를 붙였는가?
            for(int x = 0; x <= n-r; x++){
                if(is_paste) break;
                for(int y = 0; y <= m-c; y++){
                    if(pastable(x, y)){
                        is_paste = true;
                        break;
                    }
                }
            }
            if(is_paste) break;
            rotate(); // 회전
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cnt += note[i][j];
    cout << cnt << '\n';
}