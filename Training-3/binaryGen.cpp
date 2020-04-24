#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
void printArr(int * arr, int num){
  for(int index = 0; index < num; ++index){
    cout << arr[index] << " ";
  }
  cout << endl;
}


void binaryNext(int * chain, int num, int index){


  if(index == num){
    printArr(chain, num);
    return;
  }
  chain[index] = 0;
  binaryNext(chain, num, index+1);

  chain[index] = 1;
  binaryNext(chain, num, index+1);
  
}
int main(){
  int num;
  cin >> num;
  int binarychain[num];

  binaryNext(binarychain, num, 0 );

  
return 0;

}