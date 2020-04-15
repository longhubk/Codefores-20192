#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int max(int a, int b){return a > b ? a : b;}

int knapSack(int capacity, int num_items, int * value, int * weight){
  if(capacity == 0 || num_items == 0)
    return 0;
  if(weight[num_items-1] > capacity)
    return knapSack(capacity, num_items-1, value, weight);
  else{
    return max(value[num_items-1] + knapSack(capacity - weight[num_items-1], num_items-1, value, weight), knapSack(capacity, num_items-1, value, weight));
  }
}
int main(){

  int num_items, capacity;
  cin >> num_items >> capacity;
  int value[num_items];
  int weight[num_items];

  for(int index = 0; index < num_items; ++index){
    cin >> weight[index] >> value[index];
  }
  cout << knapSack(capacity, num_items, value, weight);
  
return 0;
}