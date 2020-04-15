#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;


void TSP(int num_town ,int *arr, vector<bool> &v, int currPos, int count, int cost, int &kq){

  // for(int row = 0; row < num_town; ++row){
  //   for(int col = 0; col < num_town; ++col){
  //     cout << *((arr + row*num_town) + col) << " ";
  //   }
  //   cout << "\n";
  // }
  if(count == num_town && *((arr + currPos*num_town)+0)){
    kq = min(kq, cost + *((arr + num_town*currPos)+0));
    return;
  }
  for(int index = 0; index < num_town; ++index){
    if(!v[index] && *((arr + num_town*currPos) + index)){
      v[index] = true;
      TSP(num_town, arr, v, index, count+1, cost + *((arr + currPos*num_town)+index), kq);
      v[index] = false;
    }
    
  }
}
int main(){
  int num_town, num_route;
  do{
    cin >> num_town >> num_route;
  }while (num_town > 20 || num_route > 400);
    
  
  int arr_town[num_route][3];
  for(int route = 0; route < num_route; route++){
    for(int col = 0; col < 3; ++col){
      cin >> arr_town[route][col]; // *col:  0-from -- 1-to -- 2: value
    }
  }

  int arr_in[num_town][num_town];
    for(int row = 0; row < num_town; ++row){
       for(int col = 0; col < num_town; ++col){
            arr_in[row][col] = 0;
    }
    
  }

  for(int row = 0; row < num_route; ++row){
    // for(int col = 0; col < num_town; ++col){
    int row_in = arr_town[row][0];
    int col_in = arr_town[row][1];
    arr_in[row_in-1][col_in-1] = arr_town[row][2];
    
  }


  //   for(int row = 0; row < num_town; ++row){
  //      for(int col = 0; col < num_town; ++col){
  //     cout << arr_in[row][col] << " ";
  //   }
  //   cout << "\n";
  // }
    
    



  vector<bool> vector(num_town);

for(int index = 0; index < num_town; ++index){
  vector[index] = false;
}

vector[0] = true; //* starting point is set
int kq = INT_MAX;

TSP(num_town, (int*)arr_in, vector, 0, 1, 0, kq );



cout << kq;

return 0;
}