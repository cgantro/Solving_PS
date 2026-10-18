#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    int size = 1;
    for(int i = 1; i < arr.size(); i++){
        if(answer[size - 1] == arr[i]) continue;
        answer.push_back(arr[i]);
        size++;
    }
    

    return answer;
}