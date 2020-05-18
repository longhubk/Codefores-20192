#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAX 30

int N; //_so_khach_hang
int K; //_so_xe
int Q; //_trong_tai_xe

int d[MAX];         //_luong_hang_yeu_cau_cua_cac_khach_hang

int y[MAX];         //_diem_bat_dau_cua_lo_trinh_xe_k
int x[MAX];         //_diem_tiep_theo_cua_diem_i
int segements;      //_so_chang
bool visited[MAX];  //_danh_dau_da_tham
int load[MAX];      //_load[k]_la_tong_luong_hang_da_co_tren_xe_k
int ans;            //_ket_qua

void input(){
  cin >> N >> K >> Q;
  for(int i=1; i <= N; i++) cin >> d[i];
}
bool check_X(int v, int k){              //_kiem_tra_xe_k_di_den_diem_v
  if(v > 0){
    if(visited[v]) return false;
    if(load[k] + d[v] > Q) return false; //_rang_buoc_tai_trong_xe
  }
  return true;
}
void solution(){
  ans++;
  // return;
  for(int k = 1; k <= K; k++){ //_duyet_tat_ca_cac_xe
    cout << "0 ";
    int u = y[k];              //_diem_giao_dau_tien_cua_lo_trinh_xe_k
    while(u > 0){
      cout << " -> " << u;
      u = x[u];
    }
    cout << " -> 0" << endl;
  }
  cout << "----------------------" << endl;

}
void Try_X(int s, int k){     //_thu_gia_tri_x[s]_tren_lo_trinh_xe_k
  for(int v=0; v <= N; v++){
    if(check_X(v, k)){
      x[s] = v;               //_thu_dc_diem_tiep_theo_cua_diem_s_la_v_tren_lo_trinh_xe_k
      visited[v] = true;
      segements++;
      load[k] += d[v];
      if(v == 0){             //_xe_k_da_ve_kho
        if(k == K){
          if(segements == N+K) //_tong_so_chang_phai_bang_N+K_thi_moi_dam_bao_kh_da_dc_giao
            solution(); 
        }else{
          Try_X(y[k+1], k+1); //_duyet_tiep_cho_lo_trinh_xe_k+1,bat_dau_tu_y[k+1]
        }
      }else{
        Try_X(v,k);           //_diem_tiep_theo_cua_diem_v_la_gi_van_tren_lo_trinh_xe_k
      }
      visited[v] = false;
      segements--;
      load[k] -= d[v];
    }
  }
}
bool check_Y(int v, int k){               //_diem_dau_tien_cua_lo_trinh_xe_thu_k
  if(visited[v]) return false;
  if(load[k] > Q) return false;
  else return true;
}
void Try_Y(int k){                        //_thu_gia_tri_cho_y[k]_y[1]_y[2]_y[3]_...._y[N];
  for(int v = y[k-1]+1; v <= N; v++ ){
    if(check_Y(v, k)){                    //_y_co_phu_hop_gan_vao_k_hay_khong
      y[k] = v; 
      visited[v] = true;
      segements++;
      load[k] += d[v];
      if(k == K)                        //_day_duyet_duoc_y[1]_y[2]..._y[K]
        Try_X(y[1],1);                  //_duyet_diem_tiep_theo_cua_y[1]_tren_lo_trinh_xe_thu_1
      else
        Try_Y(k+1);

      visited[v] = false;
      load[k] -= d[v];
      segements--;
      
    }
  }

}


void solve(){
  ans = 0;
  y[0] = 0;
  segements = 0;
  for(int k = 1; k <= K; k++) load[k] = 0;
  Try_Y(1);
  cout << ans;
  
}
int main(){
  input();
  solve();
return 0;
}