#include <iostream>
#include <math.h>
using namespace std;

int main(){
  long long a;
  long long b;
  long long c = pow(10,9);
  cin >> a >> b;
  cout << (a+b) % ( c + 7);

  return 0;
}