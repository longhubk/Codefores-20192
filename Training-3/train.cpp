#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

void function(){
  
}
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
void findPermutation(int arr[], int num){
  //!sort array to find
  sort(arr, arr + num);
  //!find all possible permultations
  cout << "Possible permultations are:";
  do{
    printArr(arr, num);
  }while(next_permutation(arr, arr + num)); 

  
}

int main(){
  int number;
  cin >> number;
  int array[number];
  enterArr(array, number);
  findPermutation(array, number);

  return 0;
}