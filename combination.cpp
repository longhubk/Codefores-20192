#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void printArr(int * arr, int num){
  for(int index = 1; index <= num; ++index){
    cout << arr[index] << " ";
  }
  cout << endl;
}

void Try(int * arr, int n, int m, int k){

  for(int i = arr[k-1]+1; i <= n-m+k; ++i){
    arr[k] = i;
    if(k == m) printArr(arr, m);
    else Try(arr, n, m, k+1);
  } 

}

int main(){
  int n,m;
  cin >> n >> m;
  int arr[n];
  for(int index = 0; index <= n; ++index){
    arr[index] = index;
  }
  printArr(arr,n);
  int k = 1;
  Try(arr, n, m, k);
return 0;
}