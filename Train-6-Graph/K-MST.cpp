#include <bits/stdc++.h>
using namespace std;
#define MAX_N 101
#define MAX_M 1001
#define INF 100000000
#define ll long long

int N,
    M,
    K,
    b[MAX_M],
    e[MAX_M],
    w[MAX_M],
    X[MAX_N],
    ans,
    W,
    visited[MAX_N],
    r[MAX_N],
    p[MAX_N];

vector<int> A[MAX_N];
set<int> Ax[MAX_N]; //_Ax[v] 

ll rs;


void DFS(int u){
  visited[u] = 1;
  for(set<int>::iterator i = Ax[u].begin(); i != Ax[u].end(); i++){
    int v = *i;
    if(!visited[v])
      DFS(v);
  }
}
int checkConnected(){
  set<int> Vx;
  for(int i = 1; i <= K; i++){
    Vx.insert(b[X[i]]); Vx.insert(e[X[i]]);
  }
  for(auto i : Vx){
    int u = i; visited[u] = 0;
  }
  int cnt = 0;
  for(auto i : Vx){
    int u = i; 
    if(visited[u] == 0){
      cnt++; DFS(u);
    }
  }
  return cnt == 1;
}
void swap(int &a, int &b){
  int tmp = a; a = b; b = tmp;
}
void swapEdge(int i, int j){
  swap(w[i], w[j]);
  swap(b[i], b[j]);
  swap(e[i], e[j]);
}
int partition(int L, int R, int index){
  int pivot = w[index];
  swapEdge(index, R);
  int storeIndex = L;
  for(int i = L; i <= R-1; i++){
    if(w[i] < pivot){
      swapEdge(storeIndex, i);
      storeIndex++;
    }
  }
  swapEdge(storeIndex, R);
  return storeIndex;
}
void quickSort(int L, int R){
  if(L < R){
    int index = (L+R)/2;
    index = partition(L, R, index);
    if(L < index) quickSort(L, index-1);
    if(index < R) quickSort(index+1, R);
  }
}
void quickSort(){
  quickSort(1,M);
}
void input(){
  cin >> N >> M >> K;
  for(int i = 1; i <= M; i++){
    int u, v, wuv; cin >> u >> v >> wuv;
    A[u].push_back(v);
    A[v].push_back(u);
    b[i] = u;
    e[i] = v;
    w[i] = wuv;
  }
}
void makeSet(int x){
  p[x] = x;
  r[x] = 0;
}
void link(int x, int y){
  if(r[x] > r[y]) p[y] = x;
  else{
    p[x] = y;
    if(r[x] > r[y]) r[y] = r[y] + 1;
  }
}
int findSet(int x){
  if(x != p[x]) p[x] = findSet(p[x]);
  return p[x];
}

int check(int val, int k){
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
void solution(){
  if(checkConnected())
    if(W < ans) ans = W;
}
void Try(int k){
  for(int v = X[k-1]+1; v <= M-K+k; v++){
    if(check(v,k)){
      X[k] = v;
      W += w[v];
      Ax[b[v]].insert(e[v]); Ax[e[v]].insert(b[v]);
      if(k == K) solution();
      else{
        int g = W;
        for(int j = 1; j <= K-k; j++) g += w[X[k]+j];
        if(g < ans) Try(k+1);
      }
      Ax[b[v]].erase(e[v]); Ax[e[v]].erase(b[v]);
      W -= w[v];
    }
  }
}
void solve(){
  quickSort();
  ans = INF;
  X[0] = 0;
  W = 0;
  Try(1);
  cout << ans;
}

int main(){
  input();
  solve();
}