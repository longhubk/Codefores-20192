#include <bits/stdc++.h>
using namespace std;
#define MAX 11
int N,
    M,
    res,
    LoadNow,
    visited[2*MAX+1],
    C[2*MAX+1][2*MAX+1],
    X[2*MAX+1];


bool check(int k, int v){
  if(LoadNow > M) return false;
  else{
    if(v <= N){
      if(visited[v])
        return false;
    }
    else{
      if(!visited[v-N])
        return false;
      if(visited[v])
        return false;
    }
  }

  return true;
}
void solution(){
  int cost = C[0][X[1]];
  for(int i = 1; i <= 2*N; i++){
    if(i < 2*N)
      cost += C[X[i]][X[i+1]];
    else
      cost += C[X[i]][0];
  } 
  if(res > cost) res = cost;
}
void Try(int k){
  for(int v = 1; v <= 2*N; v++){
    if(check(k, v)){
      X[k] = v;
      visited[v] = 1;
      v <= N ? LoadNow++ : LoadNow--;

      if(k == 2*N) solution();
      else Try(k+1);

      visited[v] = 0;
      v <= N ? LoadNow-- : LoadNow++;

    }
  }
}
int main(){
  ios::sync_with_stdio(0); 
  cin.tie(0);
  cin >> N >> M;
  for(int i = 0; i <= 2*N; i++)
    for(int j = 0; j <= 2*N; j++)
      cin >> C[i][j];

  LoadNow = 0;
  res = 10000000;
  memset(visited, 0, sizeof visited);
  // for(int i = 1; i <= 2*N; i++) visited[i] = 0;
  Try(1);
  cout << res;
  
  return 0;
}