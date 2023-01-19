/* 
# 문제 재정의
 스도쿠의 성질에 따라 스도쿠 판을 남는 숫자로 채워나가는 조합의 문제다.
 같은 입력이라도 다양한 경우의 수가 있고, 빈칸 하나를 채울 때마다 스도쿠의 성질에 위배되는지 여부를 확인하고, 위배된다면 BACKTRACK해야 한다.
 스도쿠에 수학적인 성질이 있을거다. idx-Queen문제 체스판의 성질처럼.

 행,열,3*3칸의 다른 모든 수를 더한 값을 45에서 뺀 값으로 구할 수 있지는 않을까?

# 계획
 입력값을 어떻게 저장하고 이용하느냐가 중요하다.
 우선 2차원 배열에 저장하면, board[i][] board[j]로 각 row와 column에 대해서 값들을 확인할 수 있다.
 그리고 0의 갯수를 변수 n에 저장한다.
 문제는 3*3칸들. 체스의 대각선칸처럼 공식이 한눈에 보이지 않네. 그냥 9가지를 다 switch문으로 거는 방법도 있다.

 BACKTRACKING 함수
 기저사례 : idx==n일 경우
# 계획 검증


# 회고
- 입력이 너무 모호해서 안 좋은 문제라고 생각. 이럴땐 처음부터 반례를 찾아보자. 그게 빠르다.
- 3*3칸 구분과정에서 '사분면'개념으로 나누는 법을 배웠다. 배열을 0부터 시작했다면 캐치할 수 있었을 것 같다.
- 백트래킹 함수 속 반복문 로직이 이해 안 된 상태다. N과M 문제와는 확실히 다름.
- https://cryptosalamander.tistory.com/59
 */

#include <bits/stdc++.h>
using namespace std;

pair<int, int> point;
vector<pair<int, int>> points;
int board[9][9];
int zero_count=0;
bool isfound=false;

bool check(pair<int,int> p){
    // 3*3칸 나누기
    int square_x = p.first/3;
    int square_y = p.second/3;

    for (int i=0;i<9;i++){
        // 같은 행에 같은 숫자가 있는 경우
        if(i != p.second && board[p.first][p.second] == board[p.first][i])
            return false;
        // 같은 열에 같은 숫자가 있는 경우
        if(i!= p.first && board[p.first][p.second] == board[i][p.second])
            return false;
    }
    // 같은 3*3칸에 같은 숫자가 있는 경우
    for (int i=square_x*3; i<square_x*3+3; i++)
        for (int j=square_y*3; j<square_y*3+3; j++)
            if(board[i][j] == board[p.first][p.second])
                if(i != p.first && j != p.second)
                    return false;

    return true;
}

void func(int idx){
    // BASE CONDITION : 0자리가 모두 채워진 경우 출력 후 아예 종료
    if (idx==zero_count){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++)
                cout <<  board[i][j] << ' ';
            cout << '\n';
            }
        isfound = true;
        return;
    }

    for (int num=1; num<=9; num++){
        board[points[idx].first][points[idx].second] = num; // 1~9 넣어봄
        // CONDITION : 스도쿠의 성질에 따라
        if(check(points[idx]))
            func(idx+1);
        if (isfound)
            return;
    }
    board[points[idx].first][points[idx].second] = 0;// 최적해를 못찾았을 경우 값 비워주기
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++){
            cin >> board[i][j];
            if (board[i][j] == 0){
                zero_count++;   // 0의 개수
                point.first = i;
                point.second = j;
                points.push_back(point);
            }
        }

    func(0);
}