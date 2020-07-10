#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int N, M;
int inputArray[MAX];
pair<int, int> pairIJ[MAX];

int maxFromTo(int a, int b){
  int min = inputArray[a];
  for(int i = a; i <= b; i++){
    if(min > inputArray[i]) min = inputArray[i];
  }
  return min;
}
int main(){
  cin >> N;
  for(int i = 0;  i < N; i++)
    cin >> inputArray[i];
  
  cin >> M;
  for(int i = 0;  i < M; i++){
    int u, v; cin >> u >> v;
    pairIJ[i].first = u;
    pairIJ[i].second = v;
  }
  int sum = 0;
  for(int i = 0; i < M; i++){
    sum += maxFromTo(pairIJ[i].first, pairIJ[i].second);
  }
  cout << sum;
  
return 0;
}