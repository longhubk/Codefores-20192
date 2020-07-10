#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int N,
    M,
    Y[MAX],
    mark[MAX],
    X[MAX],
    Z[MAX];

bool check(int v, int k){
  // if(mark[v]) return false;
  return true;
}
void solution(){
  for(int i = 1; i <= M; i++) cout << X[i] << " ";
  cout << endl;
}

void Try(int k){
  for(int v = k; v < N-M+k; v++){
    // if(check(v,k)){
      X[k] = v;
      // mark[v] = 1;
      if(k == M) solution();
      else Try(k+1);
      // mark[v] = 1;
    // }
  }
}

int main(){
  cin >> N >> M;

  // for(int i = 1; i <= N; i++) Z[i] = i;

  // for(int i = 1; i <= M; i++)
  //   cin >> Y[i];

  memset(mark, 0, sizeof mark);
  Try(0);
  return 0;
}