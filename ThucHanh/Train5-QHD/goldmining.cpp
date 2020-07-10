#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int N, L1, L2, A[MAX], maxGold;
vector<int> B;

  void countMax(){
    int sum = 0;
    for(int i = 0; i < B.size(); i++){
      sum += B[i];
    }
    if(maxGold < sum) maxGold = sum;
  }


  void Try(int k){
    for(int v = 2; v <= N; v++){
      int dis = v-k;
      if(dis >= L1 && dis <= L2){
        B.push_back(A[v]);
        if(k == N){
          countMax();
          cout << "has finish\n";
        }else{
          cout << "next\n";
          Try(k+1);
        }
      }
    }
  }
  int main(){
    cin >> N >> L1 >> L2;
    for(int i = 1; i <= N; i++)
      cin >> A[i];

    Try(1);
    cout << maxGold;
    return 0;
}