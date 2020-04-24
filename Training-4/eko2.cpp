#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;



void cutTree(long long * trees, long long N, long long M){
  sort(trees, trees+N);
  for(long long i = trees[N-1] ; i >= 0; i-- ){
    long long totalwoods = 0;

    for(long long j = 0; j < N; ++j){
        if(trees[j] > i)
          totalwoods += trees[j] - i;
    }

    if(totalwoods >= M){
      cout << i << endl;
      break;
    }

  }

}

void cutTreeBinary(long long * trees, long long N, long long M){
  sort(trees, trees+N);

  long long low = trees[0] , high = trees[N-1], mid, totalwoods = 0;
  for(int index = 0; index < 100; ++index){

    mid = (low+high)/2;
    
    for(long long j = 0; j < N; ++j){
        if(trees[j] > mid)
          totalwoods += trees[j] - mid;
    }

    if(totalwoods == M){
      cout << mid << endl;
      break;
    }else if(totalwoods > M){
      low = mid;
    }else if(totalwoods < M){
      high = mid;
    }
    

    
  }

}

// void printArr(long long * arr, int num){
//   for(long long index = 0; index < num; ++index){
//     cout << arr[index] << " ";
//   }
//   cout << endl;

// }
int main(){
  long long N;
  long long M;
  cin >> N >> M;
  
  long long trees[N];
  for(long long i = 0; i < N; ++i){
    cin >> trees[i];
  }
  // printArr(trees, N);
  
  // cutTree(trees, N, M);
  cutTreeBinary(trees, N, M);
return 0;
}