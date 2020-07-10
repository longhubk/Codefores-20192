#include <bits/stdc++.h>
using namespace std;
#define MAX 30

int N,//_so_mon_hoc
    M,//_so_hoc_ky
    C[MAX],//_C[i]_so_tin_chi_mon_i
    A[MAX][MAX], //_A[i][j]=1_mean_course_i_must_assign_before_j
    X[MAX],//_X[k]=v_mean_assign_course_k_to_semester_v
    load[MAX], //_load[i]_total_tin_chi_Hoc_ky_i
    f_best; //_optimal objective value

void input(){
  cin >> N >> M;
  for(int i = 1; i <= N; i++)
    cin >> C[i];
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      cin >> A[i][j]; 
}

bool check(int v, int k){
  for(int i = 1; i <= k-1; i++){
    if(A[i][k] == 1 && X[i] >= v) //_course_i_must_assign_before_course_k
      return false;
    if(A[k][i] == 1 && X[i] <= v) //_course_k_must_assign_before_course_i
      return false;
  }
  return true;
}
void solution(){
  int max_load = 0;
  for(int j = 1; j <= M; j++)
    if(max_load < load[j]) max_load = load[j];

  if(max_load < f_best) f_best = max_load;
}

void Try(int k){
  for(int v = 1; v <= M; v++){
    if(check(v, k)){
      X[k] = v; 
      load[v] += C[k]; //_update_load
      if(k == N)
        solution();
      else
        Try(k+1);
      load[v] -= C[k];//_back_tracking
    }
  }
}

int main(){
  input();
  f_best = 1000000;
  for(int j = 0; j <= M; j++) load[j] = 0;
  
  Try(1);
  cout << f_best;
  
  return 0;
}