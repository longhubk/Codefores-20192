#include <bits/stdc++.h>
#define FOR(a,c) for (int(a) = 0; (a) < (c) ; (a)++)
using namespace std;

const int MAX = 11;
int n;
int per[2*MAX+1];
bool used[2*MAX+1];
int minRoute = 1e9;
int cost = 0;



void nextSol(int num, int **array, int k){
  if(k > n){
    minRoute = min(minRoute, cost + array[per[n] + n][0]);
    return;
  }
  for(int i = 1; i <= n; ++i){
    if(!used[i]){
      per[k] = i;
      used[i] = true;
      cost += array[per[k-1] + n][per[k]];
      cost += array[per[k]][per[k] + n];
      nextSol(num, array, k+1);
      used[i] = false;
      cost -= array[per[k-1] + n][per[k]];
      cost -= array[per[k]][per[k] + n];

    }
  }
}

int main(){
  ios::sync_with_stdio(0); 
  cin.tie(0);
  cin >> n;
  int num = 2*n+1;
  per[0] = -n;
  int **array = new int *[num];

  FOR(i,num){
    array[i] = new int[num];
    FOR(j, num){
      cin >> array[i][j];
    }
  }


  nextSol(num,array, 1);
  cout << minRoute;

return 0;
}