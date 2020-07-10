#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int N,
	X[MAX],
	visited[MAX],
	cnt;

void solution(){
	cnt ++;
	cout << "solution " << cnt << ": 0 -> ";
	for(int i = 1; i <= N; i++){
		cout << X[i] << " -> ";
	}
	cout << " 0 " <<endl;
}
bool check(int v, int k){
	if(visited[v]) return false;
	return true;
}
void Try(int k){
	for(int v = 1; v <= N; v++){
		if(check(v,k)){
			X[k] = v;
			visited[v] = true;
			if(k == N) solution();
			else Try(k+1);
			visited[v] = false;
		}
	}
}

int main(){
	cin >> N;
	memset(X, 0, sizeof(X));
	Try(1);
}