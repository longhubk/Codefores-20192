#include <iostream>
#include <math.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  long long a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  long long max1 = 0;
  long long max2 = 0;
  for(int i = 0; i < n; i++){
    max2 += a[i];
    if(max1 < max2){
      max1 = max2;
    }
    if(max2 < 0){
      max2 = 0;
    }
  }
  cout << max1;
  return 0;
}