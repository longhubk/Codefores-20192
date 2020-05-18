/*
  ________________________________C BUS______________________________________
  _Cho N hanh khach(1->N)
  _Hanh khach i muon toi i + N
  _Xe bus bat dau tai 0
  _Xe bus tro toi da q hanh khach tai 1 thoi diem
  _Ma tran C(i,j) trong do ( 1 < i,j < 2N)
  _Tinh S min Xe bus phuc vu het hanh khach va tro lai vi tri 0 (xe khong di qua 1 diem 2 lan)

*/
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAX_N 100



int N;              //_So khach
int Q;              //_So cho tren xe
int X[2*MAX_N+1];   //_bieu dien phuong an lo trinh X[1], X[2], ... X[2N]
int q;              //_So khac thuc su dang co tren Xe
bool appear[2*MAX_N+1];

bool check(int v, int k){
  if(appear[v]) return false;
  if(v <= N){
    if(q >= Q) return false; //_neu so hk hien tai > MAX HK
  }                 //_v duoc chon
  else{
    if(!appear[v-N]) return false;
  }                       //_ v > N thi phai tra HK
  return true;
}
void solution(){
  for(int i = 1; i <= 2*N; i++) cout << X[i] << " "; cout << endl;
}

void Try(int k){             //_thu gia tri cho X[k]
  for(int v = 1; v <= 2*N; v++){
    if(check(v, k)){
      X[k] = v;
      appear[v] = true;
      if(v <= N) q++; else q--; //_cap_nhat_q
      if(k == 2*N) solution();  //_ghi_nhan_phuong_an
      else Try(k+1);
      appear[v] = false;
      if(v <= N) q--; else q++; //_quay_lui
    }
  }
}


int main(){
  N = 3, Q = 2;
  q = 0;
  for(int v = 1; v <= 2*N; v++) appear[v] = false;
  Try(1);
  cout << "hello";

  return 0;
}