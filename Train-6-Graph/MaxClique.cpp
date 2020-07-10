#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int N,
    M,
    X[MAX],
    best,
    X_best[MAX];

set<int> A[MAX];

void input(){
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int u, v;
    cin >> u >> v;
    A[u].insert(v);
    A[v].insert(u);
  }
}
bool check(int v, int k){
  for(int i = 1; i <= k-1; i++)
    if(A[X[i]].find(v) == A[X[i]].end())
      return false;
  return true;
}
void Try(int k){
  for(set<int>::iterator i = A[X[k-1]].begin(); i != A[X[k-1]].end(); i++){
    int v = *i;
    if(check(v, k)){
      X[k] = v;
      if(k > best){
        best = k;
        for(int i = 1; i <= k; i++) X_best[i] = X[i];
      }
      if(k < N) Try(k+1);
    }
  }
}
void solve(){
  best = 1;for(int v = 1; v <= N; v++){
    X[1] = v;
    Try(2);
  }
  cout << best;
}

int main(){
  input();
  solve();
}