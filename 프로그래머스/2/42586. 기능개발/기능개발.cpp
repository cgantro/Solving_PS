#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

int calculate_date(const int& prog,const int& speed){
    return ceil(float(100 - prog) / float(speed));
}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    // 현재의 날짜
    int cur_day = calculate_date(progresses[0],speeds[0]);
    vector<int> answer = {1}; 
    for(int i=1; i<progresses.size(); i++){
        // 완료되는 날짜
        int need_day = calculate_date(progresses[i],speeds[i]);
        if(cur_day >= need_day) answer[answer.size() - 1]++;
        else{
            answer.push_back(1);
            cur_day = need_day;
        }
    }
    
    return answer;
}