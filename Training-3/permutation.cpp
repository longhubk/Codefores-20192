#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

void printArr(int * arr, int num){
  for(int index = 0; index < num; ++index){
    cout << arr[index] << " ";
  }
  cout << "\n";
}
void enterArr(int * arr, int num){
  for(int index = 0; index < num; ++index){
    cin >> arr[index];
  }
}

void findPermutation(int * arr, int left,  int right){

  if(left == right)
    printArr(arr, right);
  else
  {
    for (int index = left; index < right; index++)
    {
      swap(arr[left], arr[index]); //!swap
      findPermutation(arr, left+1, right); //!call recursive
      swap(arr[index], arr[left]); //!back track
    }
    
  }
  
  
}
int main(){
  int number;
  cin >> number;
  int array[number];
  enterArr(array, number);
  findPermutation(array, 0, number);
  
return 0;
}