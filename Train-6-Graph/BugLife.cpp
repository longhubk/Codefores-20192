#include <bits/stdc++.h>
using namespace std;
const long N = 100000 + 7;
 
int n, m;
int color[N];
vector<int> a[N];
 
bool DFS(int u){
	bool ret = true;
	for(auto v : a[u]){
		if(color[v] && color[v] != 3-color[u] ) //_if color[v] == 1 and color[v] != 2 
			ret &= false;
		
		if(!color[v]){ //_if color[v] == 0 --> color[v] = 3
			color[v] = 3-color[u];
			ret &= DFS(v);
		}
	}
	return ret;
}
 
int main(){
	// ios_base::sync_with_stdio(false); cin.tie(0);
	
	int T; cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n >> m;
		// for(int i = 1; i <= n; i++) 
		// 	a[i].clear();
 
		for (int i = 0; i < m; i++){
			int u, v; cin >> u >> v;
			a[u].push_back(v); a[v].push_back(u);
		}
 
		memset(color, 0, sizeof color);
 
		auto ok = true;
 
		for (int i = 1; i <= n; i++)
			if ( !color[i] ){ //_if color[i] = 0
				color[i] = 1;
				ok &= DFS(i);
			}
 
		if(!ok) 
			printf("Scenario #%d:\nSuspicious bugs found!\n", t);
		else 
			printf("Scenario #%d:\nNo suspicious bugs found!\n", t);
	}
 
	return 0;
}