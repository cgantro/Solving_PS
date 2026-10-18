#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> clothes_map;
int solution(vector<vector<string>> clothes) {
    // {옷 종류, 개수}
     for (const auto& cloth : clothes) {
        string type = cloth[1]; 
        clothes_map[type]++;
    }
    
    // 3가지
    // A + B + C + AB + BC + CA + ABC
    // (A + 1)(B + 1)(C + 1) =  A + B + C + AB + BC + CA + ABC + 1
    int answer = 1;
    for(const auto& pair : clothes_map){
        answer *= (pair.second+1);
    }
    
    return answer - 1;
}