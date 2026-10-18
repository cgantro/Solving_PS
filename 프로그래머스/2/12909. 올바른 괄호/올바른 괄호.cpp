#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    char open = '('; char close = ')';
    stack<char> st;
    for(const char& c : s){
        if(c == open) st.push(open);
        else{
            if(st.empty()) return false;
            st.pop();
        }
    }
    return st.empty() ? true : false;
}