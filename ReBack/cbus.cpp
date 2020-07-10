#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100
#define MAX_Q 100

int N,
	Q,
	X[2*MAX_N+1],
	visited[2*MAX_N+1],
	q,
	cnt;

void solution(){
	cnt++;
	cout << "solution " << cnt << " :start at 0 ->";
	for(int i = 1; i <= 2*N; i++){
		cout << X[i] << " -> " ;
	}
	cout << endl;
}

bool check(int v, int k){
	if(visited[v]) return false;
	if( v <= N){
		if(q >= Q) return false; //if over load of bus then don't take more client.
	}
	if(v > N){
		if(!visited[v-N]) return false; //if the bus wasn't took client
	}
	return true;
	
}

void Try(int k){
	for(int v = 1; v <= 2*N; v++){
		if(check(v,k)){
			X[k] = v;
			visited[v] = true;
			if(v < N) q++; else q--;
			if(k == 2*N)
				solution();
			else
				Try(k+1);
			visited[v] = false;
			if(v < N) q--; else q++;
		}
	}
}

int main(){
	cin >> N >> Q;
	for(int i = 1; i <= 2*N; i++) visited[i] = false;
	q = 0;
	cnt = 0;
	Try(1);
	
}