#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int N,
    M,
    color[MAX];
vector<int>A[MAX];

bool DFS_bug(int u){
  int res = true;
  for(auto v : A[u]){
    if(color[v] && color[v] != 3-color[u]) res &= false;
    if(!color[v]){
      color[v] = 3-color[u];
      res &= DFS_bug(v);
    }
  }
  return res;
}
void init(){
  for(int i = 1; i <= N; i++) A[i].clear();
  memset(color, 0, sizeof color);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Test; cin >> Test;
  for(int k = 1; k <= Test; k++){
    init();
    cin >> N >> M;
    for(int i = 0; i < M; i++){
      int u, v; cin >> u >> v;
      A[u].push_back(v); A[v].push_back(u);
    }
    auto res = true;
    for(int i = 1; i <= N; i++){
      if(!color[i]){
        color[i] = 1;
        res &= DFS_bug(i);
      }
    }
    if(!res) cout << "Scenario #" << k << ":\n" << "Suspicious bugs found!\n";
    else    cout << "Scenario #" << k << ":\n" << "No suspicious bugs found!\n";
  }
}