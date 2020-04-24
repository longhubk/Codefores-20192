#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void printArr(int * arr, int num){
  for(int index = 0; index < num; ++index){
    cout << arr[index] << " ";
  }
  cout << '\n';
}

void Try(int *arr, int k, int n){
  
  int i;
  for(i=0; i <= 1 ; i++){
    arr[k-1] = i;
    if(k == n)
      printArr(arr, n);
    else
      Try(arr, k+1, n);
  }

}
int main(){
  int n;
  cin >> n;
  int arr[n];
  Try(arr,0,n);
  
return 0;
}