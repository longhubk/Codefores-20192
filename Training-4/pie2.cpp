#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
const double PI  = 3.141592653589793238463;


int N,
    F,
    R[MAX],
    STT,
    P[MAX];

double V[MAX], RES;

    

void solution(){
  STT++;
  // cout << STT << ": ";
  for(int i = 1; i <= N; i++){
    // cout << P[i] << " ";
    RES = min(RES, V[i]/P[i]);
    // cout << RES << endl;
  } 
  // cout << endl;
}
bool check(int v,int  k){
  return true;
}


void Try(int k){
  for(int v = 1; v <= F; v++){
    if(check(v, k)){
      P[k] = v;
      if(k == N){
        solution();
      }
      else Try(k+1);
    }
  }
}
int main(){
  int T; cin >> T;
  while(T--){
    cin >> N >> F;
    for(int i = 1; i <= N; i++){
      cin >> R[i];
      V[i] = PI*pow(R[i], 2);
    }

    STT = 0;
    RES = 10000000.0;
    Try(1);
    printf("%.6f", RES);
  }
  
  return 0;
}