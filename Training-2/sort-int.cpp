#include <iostream>
using namespace std;

void swap_Element(long long &x, long long &y){
  long long temp = x;
  x = y;
  y = temp;
}

void insertion_Sort(long long * arr , long long arr_length){
  for(long long index_const = 0; index_const < arr_length; ++index_const){
    for(long long index_after = index_const+1 ; index_after < arr_length ; ++index_after){
      if(arr[index_const] > arr[index_after])
        swap_Element(arr[index_const], arr[index_after]);
    }
  }
}
void bubble_Sort(long long *arr, long long arr_length){
  for(long long index = 0; index < arr_length; ++index){
    for(long long pair_index = 0; pair_index < arr_length-1; ++pair_index){
      if(arr[pair_index] > arr[pair_index+1])
        swap_Element(arr[pair_index], arr[pair_index+1]);
    }
  }
}
void selection_Sort(long long *arr, long long arr_length){
  long long min_index;
  for(long long index = 0; index < arr_length-1; ++index){
    min_index = index;
    for(long long compare_index = index; compare_index < arr_length ; ++compare_index){
      if(arr[min_index] > arr[compare_index])
        swap_Element(min_index, compare_index);
    }
    swap_Element(arr[index], arr[min_index]);
  }
}

void print_arr(long long * arr, long long arr_length){
  for( long long index = 0; index < arr_length ; ++index){
    cout << arr[index] << " ";
  }
}

void enter_arr(long long * arr, long long arr_length){
  for( long long index = 0; index < arr_length ; ++index){
    cin >> arr[index];
  }
}

int main(){

  long long number_element;
  cin >> number_element;
  long long arr[number_element];
  enter_arr(arr, number_element);
  selection_Sort(arr, number_element);
  print_arr(arr, number_element);
  return 0;

}