#include "bits/stdc++.h"
#define MAX_N 100001
using namespace std;

vector<int> A[MAX_N];

char color[MAX_N];
int d[MAX_N], 
		f[MAX_N],
		p[MAX_N];

int N,	 //so dinh
		M,
		t; //thu tu xet.



void printRes(){
	cout << "Node  1  2  3  4  5  6  7 " << endl << "d     ";


	for(int i = 1; i <= N; i++){
		cout << d[i];
		if(d[i] > 9){
			cout << " "  ;
		}
		else
			cout << "  "  ;

	}
	cout << endl << "f     ";

	for(int i = 1; i <= N; i++){
		cout << f[i];

		if(f[i] > 9){
			cout << " "  ;
		}
		else
			cout << "  "  ;

	}

	cout << endl << "p     ";

	for(int i = 1; i <= N; i++){
		cout << p[i] ;
		if(p[i] > 9){
			cout << " "  ;
		}
		else
			cout << "  "  ;

	}
	cout << endl << "color ";

	for(int i = 1; i <= N; i++)
		cout << color[i] << "  ";
	cout << endl << endl;
}

void DFS(int u){
	t = t+1;
	d[u] = t;
	color[u] = 'G';
	printRes();
	for(int i = 0; i < A[u].size(); i++){
		int v = A[u][i];
		if(color[v] == 'W'){
			p[v] = u;
			DFS(v);
		}
	}
	t = t+1;
	f[u] = t;
	color[u] = 'B';
	printRes();
	
}

int main(){

	cin >> N >> M; //example N = 7, M = 10	
	for(int i = 0; i < M; i++){
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
	}
	for(int i = 1; i <= N; i++){
		color[i] = 'W';
	}	
  
	t = 0;
	DFS(1);

	


}