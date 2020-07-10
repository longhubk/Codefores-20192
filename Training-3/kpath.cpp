#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int N,
    M,
    Res,
    mark[MAX],
    X[MAX],
    C[MAX][MAX];

bool check(int k, int v){
  if(mark[v]) {
    cout << "false\n";
    return false;
  }
  else{
    cout << "true\n";

  }
  if(!C[v][X[k-1]] || !C[X[k-1]][v]) return false;

  return true;
}

void solution(){
  Res++;
}

void Try(int k){
  for(int v = 1; v <= N; v++){
    if(check(k, v)){
      X[k] = v;
      mark[v] = 1;
      if(k == M) solution();
      else Try(k+1);
      mark[v] = 0;
    }
  }

}
int main(){
  memset(C,0, sizeof C);
  cin >> N >> M;
  int K; cin >> K;

  for(int i = 0; i < K; i++){
    int u, v; cin >> u >> v;
    C[u][v] = 1;
    C[v][u] = 1;
  }
  Res = 0;
  memset(mark, 0, sizeof mark);
  Try(1);
  cout << Res;

  return 0;
}