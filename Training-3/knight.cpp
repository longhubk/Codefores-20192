#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 30

int di[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dj[8] = {2, -2, 1, -1, 2, -2, 1, -1};
bool mark[MAX][MAX];
int Xi[MAX*MAX];
int Xj[MAX*MAX];

int N;
int I, J; //_Start cell
int cnt;
bool check(int r, int c){
  if(r < 1 || r > N) return false; //_vu
  if(c < 1 || c > N) return false;

  return !mark[r][c];

}
void solution(){
  cnt++;
  for(int i = 1; i <= N*N; i++) cout << "(" << Xi[i] << "," << Xj[i] << ")"; cout << endl;
}

void Try(int k){ //_thu o tai buoc k (Xi[k-1] Xj[k-1])
  for(int q = 0; q < 8; q++){
    if(check(Xi[k-1] + di[q], Xj[k-1] + dj[q])){
      Xi[k] = Xi[k-1] + di[q];
      Xj[k] = Xj[k-1] + dj[q];
      mark[Xi[k]][Xj[k]] = true;
      if(k == N*N)
        solution();
      else 
        Try(k+1);
      mark[Xi[k]][Xj[k]] = false;
      
    }
  }

  
}
int main(){
  cin >> N >> I >> J;

  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      mark[i][j] = false;

  Xi[1] = I ; Xj[1] = J;
  mark[I][J] = true;
  cnt = 0;
  Try(2);
  cout << cnt;
  
return 0;
}