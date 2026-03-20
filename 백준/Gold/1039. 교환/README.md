# [Gold II] 교환 - 1039 

[문제 링크](https://www.acmicpc.net/problem/1039) 

### 성능 요약

메모리: 12768 KB, 시간: 0 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색

### 제출 일자

2026년 3월 20일 14:24:36

### 문제 설명

<p>0으로 시작하지 않는 정수 N이 주어진다. 이때, M을 정수 N의 자릿수라고 했을 때, 다음과 같은 연산을 K번 수행한다.</p>

<blockquote>
<p>1 ≤ i < j ≤ M인 i와 j를 고른다. 그 다음, i번 위치의 숫자와 j번 위치의 숫자를 바꾼다. 이때, 바꾼 수가 0으로 시작하면 안 된다.</p>
</blockquote>

<p>위의 연산을 K번 했을 때, 나올 수 있는 수의 최댓값을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 정수 N과 K가 주어진다. N은 1,000,000보다 작거나 같은 자연수이고, K는 10보다 작거나 같은 자연수이다.</p>

### 출력 

 <p>첫째 줄에 문제에 주어진 연산을 K번 했을 때, 만들 수 있는 가장 큰 수를 출력한다. 만약 연산을 K번 할 수 없으면 -1을 출력한다.</p>

## AI 코드 리뷰

<template>

### 코드 리뷰
```cpp
#include <bits/stdc++.h>

using namespace std;

int N, K;
const int MAX_N = 1000000;
const int MAX_K = 10;
bool visited[MAX_N+1][MAX_K+1];
string num;

struct State{
    int num;
    int cnt;
};

void init(){
    cin >> N >> K;
    num = to_string(N);
}
```
이 코드 블록은 필요한 라이브러리를 포함하고, 전역 변수를 정의하며, 초기화 함수 `init()`를 구현하여 사용자로부터 두 개의 입력값(N, K)을 받습니다. N은 최대 1,000,000까지의 자연수이고, K는 최대 10입니다. 또한, `visited` 배열은 특정 숫자와 카운트 조합이 이미 방문되었는지를 기록합니다.

```cpp
int solution(){
    int len = num.size();
    queue<State> q;
    q.push({N, 0});
    visited[N][0] = true;

    int ret = -1;
    while(!q.empty()){
        State cur = q.front();
        q.pop();

        if(cur.cnt > K) continue;
        if(cur.cnt == K){
            ret = max(ret, cur.num);
            continue;
        }

        string curNum = to_string(cur.num);
        for(int i=0; i<len-1; i++){
            for(int j=i+1; j<len; j++){
                swap(curNum[i], curNum[j]);
                int nextNum;
                if(curNum[0] != '0' && !visited[nextNum = stoi(curNum)][cur.cnt+1]){
                    visited[nextNum][cur.cnt+1] = true;
                    q.push({nextNum, cur.cnt+1});
                }
                swap(curNum[i], curNum[j]);
            }
        }
    }
    return ret; 
}
```
이 블록은 BFS를 사용하여 K번의 교환 연산을 수행하고 가능한 최대 숫자를 찾습니다. 큐에 현재 숫자와 교환 횟수를 저장하는 `State` 구조체를 사용합니다. 숫자를 문자열로 변환하여 각 자릿수의 숫자를 교환한 후, 새로 생성된 숫자가 유효한지 확인하고 방문 기록을 업데이트합니다. K번의 교환 후 가능한 최대 숫자를 `ret`에 저장합니다.

```cpp
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cout << solution();
}
```
`main` 함수에서는 입력을 초기화하고 `solution` 함수를 호출하여 결과를 출력합니다. `ios_base::sync_with_stdio(false)`와 `cin.tie(0)`는 입출력 성능을 향상시키기 위한 설정입니다.

### 시간/공간 복잡도 분석
- **시간 복잡도**: 최악의 경우, BFS를 통해 모든 가능한 조합을 탐색해야 하므로, O(K * (M^2) * (N * K))입니다. M은 숫자의 자릿수, N은 최대 숫자입니다. K는 교환 횟수이며, 각 상태에서 두 자리의 스왑을 고려하는 데 M^2의 연산이 필요합니다.
- **공간 복잡도**: `visited` 배열은 (MAX_N+1) x (MAX_K+1) 크기로, O(N*K)입니다. 큐 또한 최악의 경우 이러한 상태를 저장하므로 추가적인 O(N*K) 공간이 필요할 수 있습니다.

### 코드 최적화 가능성 및 개선 제안
1. **방문 체크 최적화**: `visited` 배열을 사용하여 상태를 추적하는 대신, 숫자의 조합이 중복되지 않도록 추가적인 해시셋을 사용할 수 있습니다. 이는 메모리 사용을 줄일 수 있습니다.
2. **입력 처리 최적화**: 현재 `init` 함수에서 입력을 처리하는 부분은 괜찮지만, 입력이 많아질 경우 추가적인 최적화를 고려할 수 있습니다.
3. **큐 대신 스택**: BFS 대신 DFS를 사용할 수도 있으며, 이는 상태 공간을 더 깊이 탐색할 수 있으며, 메모리 사용량을 줄일 수 있습니다. 그러나 이는 전략에 따라 다릅니다.
4. **가독성 향상**: 코드의 가독성을 높이기 위해 명확한 변수 이름 사용과 주석을 추가하면 유지보수성이 향상됩니다.

이 코드는 문제를 해결하는 데 효과적이지만, 위의 개선 사항을 고려하여 성능을 더욱 향상시킬 수 있습니다.

</template>

