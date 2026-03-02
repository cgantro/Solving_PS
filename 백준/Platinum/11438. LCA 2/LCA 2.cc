#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX_N = 100000;
const int LOG = 17;

vector<int> tree[MAX_N + 1];
int parent[LOG + 1][MAX_N + 1]; // parent[k][v] = v의 2^k번째 조상
int depth[MAX_N + 1];
int N;

/**
 * DFS: depth, parent[0] 계산
 */
void dfs(int cur, int par) {
    parent[0][cur] = par;

    for (int nxt : tree[cur]) {
        if (nxt == par) continue;
        depth[nxt] = depth[cur] + 1;
        dfs(nxt, cur);
    }
}

void buildParent() {
    for(int k = 1; k<=LOG; k++){
		for(int v=1; v<=N; v++){
			parent[k][v] = parent[k-1][parent[k-1][v]];
		}
	}
}


int lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);
	
	// 높이 맞추기
	for(int k = LOG; k>=0; k--){
		if(depth[a] - (1<<k) >= depth[b]){
			a = parent[k][a];
		}
	}
	if(a == b) return a;
	for(int k=LOG; k>=0; k--){

		if(parent[k][a] != parent[k][b]){
			a = parent[k][a];
			b = parent[k][b];
		}
	}

	return parent[0][a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	//freopen("input.txt","r",stdin);
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // 루트 = 1
    depth[1] = 0;
    dfs(1, 0);
    buildParent();

    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}