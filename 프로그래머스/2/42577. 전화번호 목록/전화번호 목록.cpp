#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    // 길이 순 정렬로 짧은 문자부터 오게 만든다.
    unordered_set<string> phones;
    phones.reserve(1000000L);
    for(const string& num : phone_book){
        phones.insert(num);
    }
    
    for(auto it = phones.begin(); it != phones.end(); it++){
        string prefix = "";
        // 본인과 겹치는 경우 방지 i-1까지만 
        string number = *it;
        for(int i = 0; i< number.length() - 1; i++){
            prefix.push_back(number[i]);
            if(phones.find(prefix) != phones.end()) return false;
            
        }
    }
    return true;
}