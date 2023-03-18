/* BOGGLE (난이도 하)
 https://algospot.com/judge/problem/read/BOGGLE

 상하좌우 혹은 대각선으로 인접한 칸의 알파벳들을 이어서 특정 단어를 찾아내는 게임.
 까다로운 점은, 다음 글자가 될 수 있는 칸이 여러 개 있을 때 이 중 어느 글자를 선택해야 할지 미리 알 수 없다는 점.
 -> 완전탐색을 이용 -> target을 찾아낼 때까지 매순간의 (x,y)와 인접한 칸들을 모두 하나씩 시도
 가능한 후보수가 8이므로 O(8^n) 알고리즘.

# 문제의 분할
hasWord가 하는 일을 조각내보면, 각 글자를 하나의 조각으로 쪼개면 된다.

 # 기저 사례 선택
 더 이상의 과정 없이 간단히 답을 낼 수 있는 경우들을 기저사례로 선택한다.
 1. (x,y)에 있는 글자가 target의 첫글자가 아닌 경우 항상 실패
 2. 1에 해당하지 않고, target이 한 글자일 경우 항상 성공

 */
#include <bits/stdc++.h>
using namespace std;

const int board[5][5] = {
        {'U', 'R', 'L', 'P', 'M'},
        {'X', 'P', 'R', 'E', 'T'},
        {'G', 'I', 'A', 'E', 'T'},
        {'X', 'T', 'N', 'Z', 'Y'},
        {'X', 'O', 'Q', 'R', 'S'}
};

// (2,2)라고 할 때 인접한 8칸은 (1,1) (1,2) (1,3) (2,1) (2,3) (3,1) (3,2) (3,3)
const int dx[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
const int dy[8] = {-1, -1, -1, 1, 1, 1, 0, 0};

// hasWord(x,y,word) : 5 x 5 보글 게임판에서 (x,y)에서 시작하는 단어 word의 존재를 반환한다.
// 완전탐색이고 가능한 후보수가 8이므로 O(8^n) 알고리즘.
bool hasWord( int x, int y, const string &word){
    cout << "(" << x << "," << y << ")" << " " << (char)board[x][y]  << " " << word << endl;
    // 기저사례. 좌표가 범위에 있지 않으면 false 반환.
    if (x < 0 || x > 4 || y < 0 || y > 4)
        return false;
    // 기저사례. 단어 시작이 틀리면 false 반환
    if (board[x][y] != word[0])
        return false;
    // 기저사례. 단어 시작이 맞고 1글자짜리 단어면 true
    if (word.size() == 1)
        return true;
    // 핵심. 주위 8방향 모두 탐색하고, true면 재귀 호출
    for (int direction = 0; direction < 8; ++direction){
        int  nextX = x + dx[direction], nextY = y + dy[direction];
        // recursion : word에서 글자(단계) 하나를 빼서 인자로 전달
        if (hasWord(nextX, nextY, word.substr(1)))
            return true;
    }
    // 8방향 모두 false면 false
    return false;
}

int main(){
    int x,y;
    string input;
    cin >> x >> y >> input;

    cout << (hasWord(x,y,input) ? "found!" : "not found!") << endl;

}
