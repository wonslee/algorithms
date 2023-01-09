#include <bits/stdc++.h>
using namespace std;

int alphabet[26];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string input;
    cin >> input;

    // counting sort처럼 각 알파벳에 각 index를 대응시켜서 횟수 저장. ascii 성질 활용
    for (char c : input)
        alphabet[c-'a'] ++;
    
    for (int count : alphabet)
        cout << count << " ";
}
