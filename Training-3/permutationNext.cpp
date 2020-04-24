
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
using namespace std;
int main () {
  // int myints[] = {3, 2, 1};

  // sort (myints,myints+3);

  // cout << "The 3! possible permutations with 3 elements:\n";
  // do {
  //   cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
  // } while (next_permutation(myints, myints+3) );

  // cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  string s = {"gfg"};
  bool val = next_permutation(s.begin(), s.end());
  cout << val;
  if(val)
    cout << s;

  return 0;
}