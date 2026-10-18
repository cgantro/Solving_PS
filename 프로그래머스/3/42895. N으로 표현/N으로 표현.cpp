#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 9; // 최솟값을 찾기 위해 최대 기준인 8보다 큰 9로 초기화

// count: 현재까지 N을 사용한 횟수, current: 현재까지 계산된 결과값
void backtracking(int N, int number, int count, int current) {
    // 1. 기저 조건: N 사용 횟수가 8을 넘어가면 실패
    if (count > 8) return;

    // 2. 목표 숫자를 찾은 경우 최솟값 갱신
    if (current == number) {
        answer = min(answer, count);
        return;
    }

    // 3. N을 이어 붙인 숫자 만들기 (N, NN, NNN, NNNN ...)
    int operand = 0;
    for (int i = 1; i <= 8 - count; i++) {
        operand = operand * 10 + N;

        // 사칙연산 4가지를 각각 재귀 호출
        backtracking(N, number, count + i, current + operand); // 더하기
        backtracking(N, number, count + i, current - operand); // 빼기
        backtracking(N, number, count + i, current * operand); // 곱하기
        if (operand != 0) {
            backtracking(N, number, count + i, current / operand); // 나누기
        }
    }
}

int solution(int N, int number) {
    backtracking(N, number, 0, 0);
    
    // 최솟값이 8보다 크면 (갱신되지 않고 9 그대로라면) -1 반환
    return (answer > 8) ? -1 : answer;
}
