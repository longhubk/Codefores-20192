#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n,
    M,
    X[MAX],
    T;

int check(int v,int k){
  if(k < n) return 1;
  return T+v==M;
}
void solution(){
  for(int i = 1; i <=n; i++)cout << X[i] << " ";
  cout << endl;
}
void Try(int k){
  for(int v = 1; v <= M-T-n+k;v++){
    if(check(v, k)){
      X[k] = v;
      T += X[k];
      if(k == n) solution();
      else Try(k+1);
      T -= X[k];
    }
  }
}

int main(){
  cin >> n >> M;
  T = 0;
  Try(1);
  cout << "hello";
  return 0;
}