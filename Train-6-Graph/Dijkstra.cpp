#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

vector<int> A[MAX], //_edge
            c[MAX]; //_weight

int n, //_num_node
    m, //_num_pair
    s, //_source
    t, //_des
    d[MAX],     //_d[v]_can_tren_tu_s_to_v
    node[MAX],  //_node[i]_ element ith of HEAP
    idx[MAX],   //_idx[v] is index of v in HEAP (idx[node[i]] = i)
    sH;         //_size of HEAP

bool Fixed[MAX];

void swap(int i , int j){
  int tmp = node[i]; node[i] = node[j]; node[j] = tmp;
  idx[node[i]] = i; idx[node[j]] = j;
}
void upHeap(int i){
  if(i == 0) return ;
  while(i > 0){
    int pi = (i-1)/2;
    if(d[node[i]] < d[node[pi]]){
      swap(i, pi);
    }
    else{
      break;
    }
    i = pi;
  }
}
void downHeap(int i ){
  int L = 2*i+1;
  int R = 2*i+2;
  int maxIdx = i;
  if(L < sH && d[node[L]] < d[node[maxIdx]]) maxIdx = L;
  if(R < sH && d[node[R]] < d[node[maxIdx]]) maxIdx = R;
  if(maxIdx != i){
    swap(i, maxIdx); downHeap(maxIdx);
  }
}
void insert(int v, int k){
  d[v] = k;
  node[sH] = v;
  idx[node[sH]] = sH;
  upHeap(sH);
  sH++;
}
int inHeap(int v){
  return idx[v] >= 0;
}
void updateKey(int v, int k){
  if(d[v] > k){
    d[v] = k;
    upHeap(idx[v]);
  }else{
    d[v] = k;
    downHeap(idx[v]);
  }
}
int deleteMin(){
  int sel_node = node[0];
  swap(0, sH-1);
  sH--;
  downHeap(0);
  return sel_node;
}
void input(){
  cin >> n >> m;
  for(int k = 1; k <= m; k++){
    int u, v, w; cin >> u >> v >> w;
    A[u].push_back(v);
    c[u].push_back(w);
  }
  cin >> s >> t;
}
void init(int s){
  sH = 0;
  for(int v = 1; v <= n; v++){
    Fixed[v] = false; idx[v] = -1;
  }
  d[s] = 0; Fixed[s] = true;
  for(int i = 0; i < A[s].size(); i++){
    int v = A[s][i];
    insert(v, c[s][i]);
  }
}
void solve(){
  init(s);
  while(sH > 0){
    int u = deleteMin();
    Fixed[u] = true;
    for(int i = 0; i <= A[u].size(); i++){
      int v = A[u][v];
      if(Fixed[v]) continue;
      if(!inHeap(v)){
        int w = d[u] + c[u][i];
        insert(v, w);
      }else{
        if(d[v] > d[u] + c[u][i]){
          updateKey(v, d[u]+c[u][i]);
        }
      }
    }
  }
  int rs = d[t]; if(!Fixed[t]) rs = -1;
  cout << rs;
}

int main(){
  input();
  solve();
  return 0;
}