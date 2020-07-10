#include <bits/stdc++.h>
using namespace std;
using I2 = pair<int,int>;
const long MAX = 5000 + 5;
const long INF = 1000000000 + 5;

int N, K, C[MAX], D[MAX], F[MAX], Visited[MAX], Cal[MAX], Dist[MAX][MAX];
vector<int> A[MAX];

void Dijkstra(){
	for(int i = 0; i <= N; i++) F[i] = INF, Cal[i] = 0;
	F[1] = 0;
	while(1){
		int u = -1, fu = INF;
		for(int i = 1; i <= N; i++) 
			if(F[i] < fu && !Cal[i]) fu = F[i], u = i;
		if(u == -1) break;
		Cal[u] = 1;
		for(int v = 1; v <= N; v++) 
			if(Dist[u][v] <= D[u]) F[v] = min(F[v], F[u] + C[u]);
	}
}

int main(){
	cin >> N >> K;
	for(int i = 1; i <= N; i++) cin >> C[i] >> D[i];
	for(int i = 1; i <= K; i++){ int u, v; cin >> u >> v, A[u].push_back(v), A[v].push_back(u);}
	for(int i = 1; i <= N; i++) 
		for(int j = 1; j <= N; j++) Dist[i][j] = INF;
	for(int i = 1; i <= N; i++){
		queue<I2> Q; Q.push(I2(i, 0)), Dist[i][i] = 0;
		while(!Q.empty()){
			auto u = Q.front().first, distU = Q.front().second; Q.pop();
			for(auto v : A[u]) if(Dist[i][v] > distU+1) Dist[i][v] = distU + 1, Q.push(I2(v, Dist[i][v]));
		}
	}

	Dijkstra(), cout << F[N];
	return 0;
}