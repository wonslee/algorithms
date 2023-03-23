# 구현 방법 (직접 구현보단 STL)

```c++
int binarysearch(int target){
  int st = 0;
  int en = n-1;
  while(st <= en){
    int mid = (st+en)/2;
    if(a[mid] < target)
      st = mid+1;
    else if(a[mid] > target)
      en = mid-1;
    else
      return 1;
  }
  return 0; // st > en일 경우 while문을 탈출
}
```

```c++
binary_search(arr, arr+n, target)
```

## 매개변수 탐색 (parametric search 백준 1654)

> 99% 확률로 풀이방법을 못 찾을거다. 
    애초에 문제가 parametric search라는걸 눈치채기가 어렵다.  
    DP나 그리디와 결합되어 나오는 경우도 빈번함.
    전략적으로 이 유형은 배제하는 것도 좋은 방법일 수 있음.

: 조건을 만족하는 최소/최대값을 구하는 문제(**최적화 문제**)
-> **결정 문제**로 변환
-> 이분탐색 수행

- 최적화 문제 : N개를 만들 수 있는 랜선의 최대 길이
- 결정 문제 : 랜선의 길이가 X일 때 랜선이 N개 이상인가 아닌가?

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F8n21S%2Fbtrao6cwfSK%2Fw3bpu3tUTzlT8xFuRqHYf1%2Fimg.png)

개수가 N개 이상인 지점들중에서 가장 길이가 긴 곳.   
> 여기서 이분탐색이 가능하다!!

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FJG8Zd%2FbtraoOJv5DA%2FxHiB7kUbJkOH4wELaNi5hK%2Fimg.png)

랜선의 길이가 X일 때 조건을 만족하는지 탐색해나가는 과정.  
조각의 개수를 구하는건 N, 범위는 2^31. 
=> O(log(2^31) * N) = O(31N)  
와..미쳤다. 

> 주의점. 다루려는 함수 그래프가 감소 혹은 증가 함수여야만 한다.  

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FMY70I%2Fbtram989Ktg%2F3EOimN0OdPCf58XJBz3SqK%2Fimg.png)


> 문제에 최소, 최대 얘기가 나오고 범위가 무지막지하게 크거나, 뭔가 이분탐색 (log)으로 잘 떨구면 되겠다 싶은거