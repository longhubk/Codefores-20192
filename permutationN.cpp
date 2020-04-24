#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void printArr(int * arr, int num){
  for(int index = 1; index <=num; ++index){
    cout << arr[index] << " ";
  }
  cout << "\n";
}

void Try(int * arr,int * check, int n, int k){
  for(int i = 1; i <= n; ++i){
    if(!check[i]){
      arr[k] = i;
      check[i] = 1;
      if(k == n)
        printArr(arr, n);
      else 
        Try(arr, check, n, k+1);
      check[i] = 0;
   }
  }
}
int main(){
  int n;
  cin >> n;
  int arr[n];
  int check[n];
  for(int index = 1; index <= n; ++index){
    check[index] = 0;
  }
  Try(arr,check, n, 1);
  


  return 0;
}