## 식을 통째로 받기 (백준 1541)

식을 받았을 때, string을 전혀 쓰지 않고도 식을 숫자로 바꿀 수 있다.


```c++
int tmp, ans;
int sign = 1; // boolean, -연산 필요없도록 int로 만듬..!

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    for (char c: input){
        if (c == '+' || c == '-'){
            ans += tmp * sign; // sign에 맞게 더해주기
            
            // 한번이라도 '-'가 나온다면 앞으로 sign은 쭉 -1 (음수)
            if (c == '-') sign = -1; 
            // 만약 문제와 달리 정상적인 식이었다면 아래의 조건문 하나만 붙여주면 끝! 
            //  else if (c == '+') sign = 1;
            
            tmp = 0; // tmp 초기화
        }
        else{// 숫자인 경우
            tmp *= 10; // 이전의 숫자들을 한자리씩 올림
            tmp += c - '0'; // char을 숫자로 변환 -> 해당 자리의 숫자를 더해줌 
        }
    }
    ans += tmp * sign;
    cout << ans;
}
```
