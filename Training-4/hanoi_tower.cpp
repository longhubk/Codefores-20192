#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void move(char root, char des, char mid, int* arr, int n){
  if( n == 2)
    cout << "move " << arr[n-2] << " from " << root << " to " << mid << endl;
  else
    move(root, mid, des, arr, n-1);

  cout  << "move " << arr[n-1] << " from " << root << " to " << des << endl;

  if( n == 2)
    cout << "move " << arr[n-2] << " from " << mid << " to " << des << endl;
  else
    move(mid, des, root, arr, n-1);


}
int main(){
  int n;
  cin >> n;
  int arr[n];
  for(int index = n-1; index >= 0; index--){
    arr[index] = n-index;
  }
  move('A', 'C', 'B', arr, n);
  
return 0;
}