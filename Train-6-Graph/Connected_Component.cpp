#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

vector<int> a[MAX];
int N, M, visited[MAX], ans;

void init(){
  for(int i = 1; i <= N; i++) visited[i] = 0;
  ans = 0;
}

void DFS(int u){
  for(int i =0; i < a[u].size(); i++){
    int v = a[u][i];
    if(!visited[v])
      visited[v] = 1,
      DFS(v);
  }
}
void solve(){
  init();
  for(int i = 1; i <= N; i++){
    if(!visited[i]){
      ans++; //DFS duyet het 1 thanh phan lien thong
      DFS(i);
    }
  }
}
void input(){
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int u, v; cin >> u >> v;
    a[u].push_back(v); a[v].push_back(u);
  }

}
int main(){
  input();
  solve();
  cout << ans;
  return 0;
}