#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


void Next(int a[], int n){
  int i = n-2; // * find first smaller number from tail
  while(i > 0 && a[i] > a[i+1]) i--; //* now i have i
  if(i > 0){
    int k = n-1;
    while( a[i]  > a[k] ) k--;
    swap(a[i], a[k]);
    int r = i+1;
    int s = n-1;
    while(r <= s){
      swap(a[r], a[s]);
      r++;
      s--;
    }

  }
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
  int a[n];
  for(int index = 0; index < n; ++index){
    cin >> a[index];
  }
  Next(a, n);
  printArr(a, n);
  
return 0;
}