#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int X[7];
int appeared[10];
int ans, N;


void solution(){
  int T = X[0]*100 + X[1]*10 + X[2] - X[3]*100 - 62 + X[4]*1000 + X[5]*100 + X[6]*10 + X[2];
  if(T == N){
    ans++;
  }
}

void init(){
  for(int i = 1; i <= 9; i++) appeared[i] = 0;
}

void Try(int k){
  for(int v = 1; v <= 9; v++){
    if(appeared[v] == 0){ //_neu chua xuat hien
      X[k] = v;           //_thu X[k] = v
      appeared[v] = 1;    //_danh dau da thu voi X[k] = v
      if(k == 6)          //_neu k = 6 thi in ra phuong an
        solution(); 
      else
        Try(k+1);         //_thu voi phuong an tiep theo k+1
      appeared[v] = 0;    //_quay lui
    }
  }
}
void solve(){
  scanf("%d", &N);
  init();
  ans = 0;
  Try(0);
  printf("%d", ans);
}

int main(){

  solve();
  
return 0;
}