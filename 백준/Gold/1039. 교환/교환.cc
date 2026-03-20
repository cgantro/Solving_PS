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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cout << solution();
}   