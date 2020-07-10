#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int N, K, I; //_in_ra_xau_nhi_phan_do_dai_n_thu_k_ma_khong_co_i_so_0_lien_tiep
int mark[MAX], X[MAX], STT, STT2;


void solution(){
  STT++;

  int count = 0;
  int max_cnt = 0;
  for(int i = 1; i <= N; i++){
    if(X[i] == 0){
      count++;
      if(max_cnt < count) 
        max_cnt = count;
      if(X[i+1] == 0)
        count++;
      else
        count = 0;
    }
  }

  if(max_cnt < I){
    STT2++;
    if(STT2 == K){
      
      for(int i = 1; i <=N; i++)
        cout << X[i] << " ";
    }
  }
}
bool check(int v, int k){
  return true; 
}

void Try(int k){
  for(int v = 0; v <= 1; v++){
    if(check(v, k)){
      X[k] = v;
      // mark[v] = 1;
      if(k == N) solution();
      else Try(k+1);
      // mark[v] = 0;
    }
    if(STT2 == K) break;
  }
}
int main(){
  cin >> N >> K >> I;

  for(int j = 1; j <= N; j++) mark[j] = 0;
  Try(1);
  // cout << STT2;
  if(K > STT2 || K < STT2 || K == 0) cout << -1;

  return 0;
}