#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    // {우선 순위, 원래 인덱스}
    queue<pair<int,int>> q;
    for(int i = 0; i<priorities.size(); i++){
        q.push({priorities[i],i});
    }
    
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    // 가장 높은 우선순위 idx
    int idx = 0;
    while(!q.empty()){
        auto& [cur_prior,cur_idx] = q.front(); q.pop();
        // 1. 우선순위 
        if(cur_prior == priorities[idx]){
            answer++;
            // 다음 우선순위 
            idx++;
            if(cur_idx == location) return answer;
        }else{
            // 더 높은 우선순위를 가진게 있을 때
            q.push({cur_prior,cur_idx});
        }
    }
    return answer;
}