#include <bits/stdc++.h>
using namespace std;
#define MAX_N 101
#define MAX_M 1001
#define ll long long

int N,
    M,
    b[MAX_M], //_edge
    e[MAX_M], //_edge
    X[MAX_N], //_indice
    r[MAX_N], //_rank
    p[MAX_N]; //_parent

ll  ans,
    rs;


void link (int x, int y){
  if(r[x] > r[y]) p[y] = x; //_if_rank[x]>rank[y]=>x_is_parent_y;
  else{
    p[x] = y;
    if(r[x] == r[y]) r[y]++;
  }
}
void makeSet(int x){
  p[x] = x;
  r[x] = 0;
}

int findSet(int x){
  if(x != p[x]) p[x] = findSet(p[x]);
  return p[x];
}

void input(){
  cin >> N >> M;
  for(int i = 1; i <= M; i++) cin >> b[i] >> e[i];
}
void solution(){ans++;}

int checkNoCycle(int val, int k){
  for(int i = 1; i <= N; i++) makeSet(i);
  for(int j = 1; j < k; j++){
    int u = b[X[j]]; int v = e[X[j]];
    int ru = findSet(u); int rv = findSet(v);
    if(ru == rv) return 0;
    link(ru, rv);
  }
  if(findSet(b[val]) == findSet(e[val])) return 0;
  return 1;
}
void Try(int k){
  for(int v = X[k-1]+1; v <= M; v++){
    if(checkNoCycle(v, k)){
      X[k] = v;
      if(k == N-1) solution();
      else Try(k+1);
    }
  }
}
void solve(){
  ans = 0;
  X[0] = 0;
  Try(1);
  cout << ans;
}
int main(){
  input();
  solve();
}


