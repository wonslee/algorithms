// arr을 vector로 바꿔서, push&pop을 써서 구현

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
bool visited[10];

void func(int idx){
    if(idx==m){
        for(int num : v) 
            cout<<num<<" ";
        cout<<"\n";
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            v.push_back(i); // 핵심. vector에 push.
            visited[i]=true;
            func(idx+1); // 재귀호출.
            v.pop_back();
            visited[i]=false;
        } 
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0);
}
