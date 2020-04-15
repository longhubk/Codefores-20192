#include <iostream>
using namespace std;
int main(){
  unsigned long long a, b, c, a1, b1, c1, a0, b0, c0;
  cin >> a >> b;
  a1 = a / 10;
  a0 = a % 10;
  b1 = b / 10;
  b0 = b % 10;
  c1 = a0 + b0;
  c0 = c1 % 10;
  c = c1 / 10;
  cout << (a1 + b1 + c)*10 + c0;
  return 0;
}