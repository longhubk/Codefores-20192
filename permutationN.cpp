#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


void Try(int  * arr, int  * arr2, int  * arr3,int  * check, int  n, int  k, int * min){

  for(int  i = 1; i <= n; ++i){
    if(!check[i]){
      arr[k] = arr2[i];
      check[i] = 1;
      if(k == n){
        int  sum = 0;
        for(int  index = 1; index <= n; ++index){
          sum += arr[index]*arr3[index];
        }
        if(sum < *min)
          *min = sum;
       
      }
      else 
        Try(arr, arr2, arr3, check, n, k+1, min);
      check[i] = 0;
   }
  }
}



int main(){
  int soTest = 1001;
 
  
    cin >> soTest;
    int testNum[soTest];

    int * arrayY[soTest];
    int * arrayX[soTest];
    int * check[soTest];
  for(int index = 0; index < soTest; ++index){
    testNum[index] = 1001;
    int  arr[testNum[index]];
    int  min = 999999;
    cin >> testNum[index];
    arrayX[index]= new int  [testNum[index]];
    arrayY[index]= new int  [testNum[index]];
    check[index]= new  int [testNum[index]];

    for(int j = 1; j <= testNum[index]; ++j){
      check[index][j] = 0;
      cin >> arrayX[index][j];
    }
    for(int k = 1; k <= testNum[index]; ++k){
      cin >> arrayY[index][k];
    }
    Try(arr, arrayY[index], arrayX[index] , check[index], testNum[index], 1 , &min);
    cout << "Case #" << index+1 << ": " << min << endl;

  }


  return 0;
}