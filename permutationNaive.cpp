#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void naivePermutation(int * arr, int step){
  
}
void printArr(int * arr, int num){
  for(int index = 0; index < num; ++index){
    cout << arr[index] << " ";
  }
  cout << endl;
}
int main(){
  int n;
  cin >> n;
  int arr[n];
  bool flag[n];
  // naivePermutation(arr, 1);
  int i,j,k;
  for(i = 0; i < n; ++i){
    
    arr[0] = i+1;
    flag[i] = true;
    for( j = 0; j < n; ++j){
      arr[1] = j+1;
      flag[j] = true;
      for( k = 0; k < n; k++){
        arr[2] = k+1;
        flag[k] = true;
      }

      flag[j] = false;
    }
    flag[i] = false;
  }

    

return 0;
}