#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int n, m, A[MAX], M[MAX][MAX], I[MAX], J[MAX];

void input(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> A[i];
  cin >> m;
  for(int i = 0; i < m; i++) cin >> I[i] >> J[i];
}
void initM(){
  for(int j = 0; (1<<j) <= n; j++)
    for(int i = 0; i < n; i++) M[j][i] = -1;
}
void preprocessing(){
  for(int i = 0; i < n; i++) M[0][i] = i;

  for(int j = 1; (1<<j) <= n; j++){
    for(int i = 0; i+(1<<j)-1 < n; i++){
      if(A[M[j-1][i]] < A[M[j-1][i+(1<<(j-1))]])
        M[j][i] = M[j-1][i];
      else
        M[j][i] = M[j-1][i+(1<<(j-1))];
    }
  }
}
int rmq(int i, int j){
  int k = log(j-i+1)/log(2);
  int p2k = 1<<k;
  if(A[M[k][i]] <= A[M[k][j-p2k+1]])
    return A[M[k][i]];
  else
    return A[M[k][j-p2k+1]];
  
}


int main(){
  
input();
initM();
preprocessing();

int ans = 0;
for(int i = 0; i < m; i++)
  ans += A[rmq(I[i], J[i])];

cout << ans;
return 0;
}