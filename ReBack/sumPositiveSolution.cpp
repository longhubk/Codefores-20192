#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int N,
	M,
	T,
	X[MAX];

bool check(int v, int k){
	if(k < N) 
		return true;
	else
		return T + v == M;
}
void solution(){
	for(int i = 1; i <= N; i++){
		cout << X[i] << " ";
	}
	cout << " 0 "<< endl;
}
void Try(int k){
	for(int v = 1; v <= M-T-N+k; v++){
		if(check(v, k)){
			X[k] = v;
			T += X[k];
			if(k == N) 
				solution();
			else 
				Try(k+1);
			T -= X[k];
		}
	}
}

int main(){
	cin >> M >> N;
	T = 0;
	Try(1);
	return 0;
}