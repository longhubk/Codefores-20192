#include <iostream>
#include <math.h>
using namespace std;

int main(){
  long long a;
  long long b;
  long long c = pow(10,9);
  cin >> a >> b;
  long long d = pow(a,b);
  cout << d % (c + 7);

  return 0;
}