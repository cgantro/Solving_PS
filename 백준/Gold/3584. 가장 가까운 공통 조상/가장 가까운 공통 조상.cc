#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int N;

const int ROOT = 0;
vector<int> parent;
unordered_set<int> _parents;
int main(){	
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","r",stdin);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T; cin >> T;
	while(T--){
		cin >> N; parent.assign(N+1,0);
		for(int i=0; i<N-1; i++){
			int A,B; cin >> A >> B;
			parent[B] = A;
		}
		int n1,n2; // node1, node2
		cin >> n1 >> n2;
		_parents.clear();
		int ans = 0;
		while(true){
			_parents.insert(n1);
			int pr = parent[n1];
			if(pr == 0) break;
			n1 = pr;
		}

		while(true){
			if(_parents.count(n2)) {
				ans = n2;
				break;
			}
			int pr = parent[n2];
			n2 = pr;
		}

		cout << ans << '\n';
	}
}
