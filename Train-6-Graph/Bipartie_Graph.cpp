#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int N, M, deg[MAX], ans;
vector<int> A[MAX];

int BFS(int u){
  queue<int> Q;
  Q.push(u);
  deg[u] = 0;
  while(!Q.empty()){
    int v = Q.front(); Q.pop();
    for(int i = 0; i < A[v].size(); i++){
      int x = A[v][i];
      if(deg[x] > -1){
        if(deg[v] % 2 == deg[x] % 2) return 0;
      }
      else{
        deg[x] = deg[v] + 1;
        Q.push(x);
      }
    }
  }
  return 1;
}
int main(){
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int u, v; cin >> u >> v; A[u].push_back(v); A[v].push_back(u);
  }

  for(int i = 1; i <= N; i++)
    deg[i] = -1;

  ans = 1;

  for(int i = 1; i <= N; i++){
    if(deg[i] == -1){
      if(!BFS(i)){
        ans = 0; break;
      }
    }
  }

  cout << ans;
  return 0;
}