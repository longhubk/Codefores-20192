#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int N,
    X[MAX],
    C[2*MAX+1][2*MAX+1],
    visited[MAX];
long long Res;

bool check(int k, int v){
  return visited[v] == 0;
}

void solution(){
  long long cost = C[0][X[1]];
  // cout << "0";
  for(int i = 1; i <=N; i++){
    cost += C[X[i]][X[i]+N] ;
    if(i < N) cost += C[X[i]+N][X[i+1]];
    else cost += C[X[i]+N][0];
    // cout << "->" << X[i] << "->" << X[i]+N ;
    
  } 
  // cout << "->0\n";
  if(Res > cost) Res = cost;

}

void Try(int k){
  ios::sync_with_stdio(0); 
  cin.tie(0);
  for(int v = 1; v <= N; v++ ){
    if(check(k, v)){
      X[k] = v;
      visited[v] = 1;
      if(k == N) solution();
      else Try(k+1);
      visited[v] = 0;
    }
  }
}
int main(){
  cin >> N;
  
  for(int i = 0; i < 2*N+1; i++)
    for(int j = 0; j < 2*N+1; j++)
      cin >> C[i][j];


  Res = 100000000;
  for(int i = 1; i <= N; i++) visited[i] = 0;

  Try(1);
  cout << Res;
  
  return 0;
}