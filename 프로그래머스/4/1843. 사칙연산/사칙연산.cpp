#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> nums;   // 숫자만 모아둔 배열 (ex:)
vector<char> ops;   // 연산자만 모아둔 배열 (ex: ['-', '+', '-'])
// 숫자의 개수는 최대 101개
int memo_max[105][105];
int memo_min[105][105];
bool visited[105][105];

// type -> 1: 최댓값 구하기, 0: 최솟값 구하기
int backtracking(int start, int end, int type) {
    // 기저 조건: 숫자가 하나만 남은 경우 (더 이상 쪼갤 연산자가 없음)
    // 그 숫자 자체가 최댓값이자 최솟값입니다.
    if (start == end) {
        return nums[start];
    }
    
     // 이미 계산한 적이 있다면 메모리 반환
    if (visited[start][end]) {
        return (type == 1) ? memo_max[start][end] : memo_min[start][end];
    }

    int max_val = INT_MIN;
    int min_val = INT_MAX;

    // start번째 숫자부터 end번째 숫자 사이에 있는 연산자(mid)를 하나씩 기준으로 잡고 쪼갭니다.
    for (int mid = start; mid < end; mid++) {
        // 기준 연산자(mid)를 중심으로 왼쪽 구간과 오른쪽 구간을 재귀 호출합니다.
        int left_max  = backtracking(start, mid, 1);
        int left_min  = backtracking(start, mid, 0);
        int right_max = backtracking(mid + 1, end, 1);
        int right_min = backtracking(mid + 1, end, 0);

        // 현재 기준 연산자가 더하기 일 때
        if (ops[mid] == '+') {
            max_val = max(max_val, left_max + right_max); // 최대 + 최대 = 최대
            min_val = min(min_val, left_min + right_min); // 최소 + 최소 = 최소
        } 
        // 현재 기준 연산자가 빼기 일 때 (★핵심)
        else if (ops[mid] == '-') {
            max_val = max(max_val, left_max - right_min); // 최대 - 최소 = 최대
            min_val = min(min_val, left_min - right_max); // 최소 - 최대 = 최소
        }
    }
    
    memo_max[start][end] = max_val;
    memo_min[start][end] = min_val;
    visited[start][end] = true;
    
    // 요청받은 타입(최대 또는 최소)에 따라 연산 결과를 반환합니다.
    if (type == 1) return max_val;
    else return min_val;
}

int solution(vector<string> arr) {
    nums.clear();
    ops.clear();

    // 1. 입력받은 문자열 배열에서 숫자와 연산자를 분리합니다.
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            nums.push_back(stoi(arr[i])); // 0, 2, 4... 인덱스는 숫자
        } else {
            ops.push_back(arr[i][0]);     // 1, 3, 5... 인덱스는 연산자
        }
    }
    return backtracking(0, nums.size() - 1, 1);
}
