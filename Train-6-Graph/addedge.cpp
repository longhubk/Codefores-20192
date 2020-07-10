#include <bits/stdc++.h>
#define ll long long
using namespace std;
const long MAX = 1000001;

int N, M;
ll ans; 
int visited[MAX],
	par[MAX],  //_ par[u] parent of u
	jump[MAX],
	deep[MAX];

vector<int> a[MAX]; //_matrix graph
map<ll, int> u_map; 

auto idx(int u,int v){
	return 1ll*u * N + v;
}

void remove_cycle_edges(int u, int p, int d){
	if(visited[u] == 2) return;

	if(visited[u] == 1){
		auto x = p;
		u_map[idx(u,p)] = u_map[idx(p,u)] = 0;

		while(x != u){ 
			if(jump[x] != 0) 
				if(deep[jump[x]] >= deep[u]){
					x = jump[x]; 
					continue;
				}
				else break;
			
			if(!u_map[idx(x, par[x])]) break;

			u_map[idx(x, par[x])] = 0;
			u_map[idx(par[x], x)] = 0;
			jump[x] = u, 
			x = par[x]; 
    } 
    return; 
	}

	visited[u] = 1;
	deep[u] = d;
	par[u] = p;

	for(auto v : a[u]) { 
		if(v == p) continue; 
		remove_cycle_edges(v, u, d+1); 
  } 
	visited[u] = 2;
}

int dfs(int u){
	int res = 1;
	visited[u] = 1;
	for(auto v : a[u])
		if(u_map[idx(u,v)] && !visited[v])
			res += dfs(v);

	return res;
}

void input(){
	cin >> N >> M;
	for (auto i = 0; i < M; i++){
		int u, v; cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
		u_map[idx(u,v)] = u_map[idx(v,u)] = 1;
	}

}

void init(){
	memset(visited, 0, sizeof visited);
	memset(par, 0, sizeof par);
}

void solve(){
	init();
	for (int i = 1; i <= N; i++) 
		if ( visited[i] == 0 )
			remove_cycle_edges(i, 0, 0);


	ll ans = 0;
	memset(visited, 0, sizeof visited);
	for(int i = 1; i <= N; i++) 
		if(!visited[i]){
			int x = dfs(i); //_x = cardinality
			ans = ans + 1ll*x*(x-1)/2 - (x-1); 
		}

	cout << ans;

}

int main(){
	input();
	solve();
	return 0;
}
