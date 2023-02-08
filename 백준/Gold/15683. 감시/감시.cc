/*
# 문제 재정의
 CCTV들의 방향에 대한 조합 문제. 상태공간트리를 정의하고 백트래킹(DFS)을 쓰거나 바킹독의 방법으로..

 기본적으로 2차원 보드와 방향의 문제이므로 DIR을 이용
# 계획
https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0D/solutions/15683.cpp

 1. 각 cctv의 방향 정하기. 4진법을 이용해서 각 자릿수를 나머지 연산으로 구해나가 3자릿수를 구함.
 2. 정한 방향에 대해서 사각 지대의 크기 구하기
    upd함수에서 쭉 지나가면서 마크(7)를 남긴다.
 3. 최소 사각지대 크기를 갱신해나간다.

# 복잡도 검증
 - upd함수의 호출 횟수: 4*cctv의 개수(8)*0인지확인하는연산(8)*방향의개수(4^8) = 20971520
# 회고
 - 4진법...엄청난걸 배웠다.
 이 문제와 같이 변수들이 가질 수 있는 값이 여러개이고,
 모든 조합을 다 확인해보고 싶은데 변수들끼린 서로 독립적일땐 진법을 사용해보자.
 가령 1번 카메라가 3개일 땐 0~63까지의 수를 4진법으로 나타내면 000, 001, ... , 333. 각각의 자리를 방향 3개에 대응시키는 것.

*/


#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n,m,mn;
int board[9][9];
int watched[9][9]; // cctv의 감시 영역에 걸리는 칸을 저장하는 배열
vector<pair<int,int>> cctv; // CCTV 좌표 배열
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool OOB(int a, int b){// out of bounds 확인
    return (a < 0 || a >= n || b < 0 || b >= m);
}

void upd(int x, int y, int dir){// (x,y)에서 dir방향으로 진행하면서 벽을 만날때까지 모든 빈칸을 7로 바꿈
    dir %= 4; // 나머지 연산!
    while(1){
        x += dx[dir];
        y += dy[dir];
        if(OOB(x,y) || board[x][y] == 6) return;// 범위밖이거나 벽을 만나면 함수 종료
        if (board[x][y] != 0) continue;// cctv가 있는 경우 넘어감
        watched[x][y] = 7; // 봤다는 표시
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != 6) // CCTV인 경우
                cctv.push_back({i, j});
            else if (board[i][j] == 0) mn++;// 일단 빈칸을 다 더하고 시작
        }
    }

    // tmp는 4^cctv.size() 번 돌아야 한다. 1 << (2 * cctv.size())는 4^cctv.size()임. for loop으로 4를 여러번 곱해도 상관 없음.
    int times = 1;
    for (int i = 0; i < cctv.size(); ++i) times *= 4; //

    // POINT: tmp를 4진법으로 뒀을 때 각 자리수를 cctv의 방향으로 생각할 것이다.
    for(int tmp = 0; tmp < times; tmp++){ // LOOP: 모든 경우의 수에 대해 4진법으로
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                watched[i][j] = board[i][j];// 보드 복사
        int brute = tmp;


        for(int i = 0; i < cctv.size(); i++){// LOOP: 각 cctv에 대해
            int dir = brute % 4;// DIR: brute를 4로 나눈 나머지
            brute /= 4;

            int x,y;
            tie(x,y) = cctv[i]; // 해당 cctv의 좌표(x,y)

            // SWITCH: 각 cctv 종류에 맞게 upd 실행
            upd(x, y, dir);
            switch (board[x][y]) {
                case 1:break;
                case 2:
                    upd(x,y,dir+2);break;
                case 3:
                    upd(x,y,dir+1);break;
                case 4:
                    upd(x,y,dir+1);
                    upd(x,y,dir+2);break;
                case 5:
                    upd(x,y,dir+1);
                    upd(x,y,dir+2);
                    upd(x,y,dir+3);break;
            }

        }
        int val = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                val += (watched[i][j]==0);
        mn = min(mn, val); // MIN: 사각지대 최소값 갱신
    }
    cout << mn;

}