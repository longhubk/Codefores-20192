#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int N,
	X[MAX];
void solution(){
	for(int i = 1; i <= N; i++){
		cout << X[i] << " ";
	}
	cout << endl;
}
void Try(int k){
	for(int v = 0; v <= 1; v++){
		X[k] = v;
		if(k == N) solution();
		else 
			Try(k+1);
		
	}
}
int main(){
	N = 3;
	Try(1);
}