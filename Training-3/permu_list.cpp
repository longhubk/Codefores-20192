#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
#define ll long long

int N,
    STT;
ll K;
int mark[MAX],
    X[MAX];

void solution(){
  STT++;
  if(STT == K)
    for(int i = 1; i <= N; i++) cout << X[i] << " ";
}

void Try(int k){
  for(int v = 1; v <= N; v++){
    if(!mark[v]){
      X[k] = v;
      mark[v] = 1;
      if(k == N) solution();
      else Try(k+1);
      mark[v] = 0;
      if(STT == K) break;
    }
    if(STT == K) break;
  }
}
int main(){
  cin >> N >> K;
  memset(mark, 0, N);
  STT = 0;
  Try(1);
  if(N == 1 && K > 1) cout << -1;
  return 0;
}