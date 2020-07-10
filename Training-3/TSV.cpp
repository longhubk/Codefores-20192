#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int N,
    X[MAX],
    appear[MAX];


void solution(){
  for(int i = 1; i <=N; i++) cout << X[i] << " ";
  cout << endl;
}

bool check(int v, int k){
  return appear[v] == 0;
}

void Try(int k){ //_thu_gia_tri_cho_X[k]
  for(int v = 1; v <= N; v++){
    if(check(v,k)){
      X[k] = v;
      appear[v] = 1;
      if(k == N) solution();
      else Try(k+1);
      appear[v] = 0;
    }
  }
  
}

int main(){
  cin >> N;
  for(int i = 1; i <= N; i++) appear[i] = 0;
  Try(1);
  
  return 0;
}