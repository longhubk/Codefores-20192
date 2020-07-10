#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int N,
	X[MAX],
	Visited[MAX],
	Don[MAX],
	Tra[MAX],
	cnt;
void solution(){
	cnt ++;
	cout << "solution " << cnt << ": 0 -> ";
	for(int i = 1; i <= N; i++){
		cout << X[i] << " tra " << X[i] + N << " -> ";
	}
	cout << " 0 " <<endl;
}
bool check(int v, int k){
	if(Visited[v]) return false;
	if(v < N){
		if(Don[v] == true) return false;
	}
	else{
		if(Tra[v] == true) return false;
	}
	return true;
}
void Try(int k){
	for(int v = 1; v <= N; v++){
		if(check(v, k)){
			X[k] = v;
			Visited[v] = true;
			if(k == N) solution();
			else Try(k+1);
			Visited[v] = false;
		
			
		}
	} 
}
int main(){
	cin >> N;
	cnt = 0;
	Try(1);
}