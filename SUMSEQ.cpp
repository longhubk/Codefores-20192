#include <iostream>
#include <math.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  long long a[n];
  long long c = pow(10,9);
  long long sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    sum += a[i];
  }
  long long kq = sum % (c+7);
  cout << kq;
  return 0;
}