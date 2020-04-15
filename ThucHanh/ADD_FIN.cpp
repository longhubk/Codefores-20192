/// a, b => a + b
// a, b < 10^19 ===> vuot qua long long
// y tuong cong xau bang string
// co 1 cach khac: dung unsigned long long

#include <iostream>
using namespace std;
int main(){
  unsigned long long a, b;
  cin >> a >> b;
  cout << a + b;
  return 0;
}