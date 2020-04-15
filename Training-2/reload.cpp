#include <iostream>
using namespace std;

long long count_part_road(long long * arr, long long num_road){
  long long kind_plastic = arr[0];
  long long count_part  = 1;
  for(long long index = 1; index < num_road; index++){
    if(arr[index] != kind_plastic){
      kind_plastic = arr[index];
      count_part++;
    }
  }
  return count_part;
}

void cal_change(long long * arr_road, long long arr_change[][2], long long num_road, long long num_change){
  for(long long row = 0; row < num_change; row++){
      long long index_change = arr_change[row][0];
      long long plastic_change = arr_change[row][1];
      arr_road[index_change-1] = plastic_change;
      cout <<  count_part_road(arr_road, num_road) << '\n';
  }



}

int main(){
  long long num_road_part, num_change_plastic;
  cin >> num_road_part;
  long long array_plastic_road[num_road_part];
  for(long long index = 0; index < num_road_part; index++){
    cin >> array_plastic_road[index];
  }
  cin >> num_change_plastic;
  long long arr_change_plastic[num_change_plastic][2];
  for(long long row = 0; row < num_change_plastic; row++){
    for(long long col = 0; col < 2; col++){
      cin >> arr_change_plastic[row][col];
    }
  }
  cal_change(array_plastic_road, arr_change_plastic, num_road_part, num_change_plastic);

  return 0;
}