#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int factorial(int num){
  if (num == 0)
  {
    return 1;
  }
  else
  {
    return num*factorial(num-1);
  }
  
}

void findPermutation(int * arr, int left,  int right, int num_town, int arr2[][3]){
  int num_route = right-1;

  if(left == right){
    for(int index = 0; index < num_town; ++index){
      for(int row = 0; row < num_route; ++row){
        if(arr2[row][0] == arr[row] && arr2[row][1] == arr[row+1]){}
      
      }
    }
  }
  else
  {
    for (int index = left; index < right; index++)
    {
      swap(arr[left], arr[index]); //!swap
      findPermutation(arr, left+1, right, num_town, arr2); //!call recursive
      swap(arr[index], arr[left]); //!back track
    }
  }
}
void printArr(int * arr, int num){
  for(int index = 0; index < num; ++index){
    cout << arr[index] << " ";
  }
}

void min_distance(int arr[][3], int num_route, int num_town)
{
 
  
}

int main()
{
  int num_town, num_route;
  cin >> num_town >> num_route;
  int arr_town[num_route][3];
  for(int route = 0; route < num_route; route++){
    for(int col = 0; col < 3; ++col){
      cin >> arr_town[route][col]; //col:  0-from -- 1-to -- 2: value
    }
  }
  int row = factorial(num_town-1);
  int col = num_town+1;
  int arr_in[col];
  //int arr_sev[row][col];
  arr_in[0] = arr_in[col-1] = 1;
  for(int index = 1; index < col-1; ++index){
    arr_in[index] = index+1;
  }
  findPermutation(arr_in, 0, col+1, num_town, arr_town);
 // min_distance(arr_town, num_route, num_town);

  return 0;
}