#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int N, M, t, icc[MAX], ncc, x[MAX], idx, f[MAX];
vector<int> A[MAX], B[MAX];
char color[MAX];

void INIT(){
  for(int i = 1; i <= N; i++)
    color[i] = 'W';
  t = 0;
}

void build_residual_graph(){
  for(int u = 1; u <= N; u++){
    for(int j = 0; j < A[u].size(); j++){
      int v = A[u][j];
      B[v].push_back(u);
    }
  }
}

void dfsA(int v){
  t++;
  color[v] = 'G';
  for(int j = 0; j < A[v].size(); j++){
    int u = A[v][j];
    if(color[u] == 'W')
      dfsA(u);
  }
  t++;
  f[v] = t;
  color[v] = 'B';
  idx++;
  x[idx] = v;
}

void dfsA(){
  INIT();
  idx = 0;
  for(int i = 1; i <= N; i++)
    if(color[i] == 'W')
      dfsA(i);
}

void dfsA1(int u){
  t++;
  color[u] = 'G';
  icc[u] = ncc;
  for(int i = 0; i < B[u].size(); i++){
    int v = B[u][i];
    if(color[v] == 'W')
      dfsA1(v);
  }
  color[u] = 'B';
}


void dfsA1(){
  INIT();
  ncc = 0;
  for(int i = N; i >= 1; i--){
    int v = x[i];
    if(color[v] == 'W'){
      ncc++;
      dfsA1(v);
    }
  }
}



int main(){

  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int u, v; cin >> u >> v;
    A[u].push_back(v);
  }

  dfsA();
  build_residual_graph();
  dfsA1();
  cout << ncc;

  return 0;
}