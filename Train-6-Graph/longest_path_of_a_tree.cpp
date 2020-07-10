#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int N, D[MAX], P[MAX];
vector<int> A[MAX], C[MAX];

void BFS(int u){
  queue<int> Q;
  D[u] = 0;
  Q.push(u);
  while(!Q.empty()){
    int v = Q.front(); Q.pop();
    for(int i = 0; i < A[v].size(); i++){
      int x = A[v][i];
      if(D[x] > -1) continue;
      int w = C[v][i];
      Q.push(x);
      D[x] = D[v] + w;
      P[x] = v;
    }
  }
}

int LongestPath(){
  int max_p = -1, u = -1;
  for(int v = 1; v <= N; v++)
    if(max_p < D[v])
      max_p = D[v], u = v;
  return u;
}

void init(){
  for(int v = 1; v <= N; v++) D[v] = -1, P[v] = -1;
}

int main(){
  cin >> N;
  for(int i = 0; i < N-1; i++){
    int u, v, w; cin >> u >> v >> w;
    A[u].push_back(v); A[v].push_back(u);
    C[u].push_back(w); C[v].push_back(w);
  }
  init();
  BFS(1);
  int u = LongestPath();
  init();
  BFS(u);
  u = LongestPath();
  cout << D[u];
  return 0;
}