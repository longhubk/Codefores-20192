#include <iostream>
using namespace std;

void swap_Element(long long &x, long long &y){
  long long temp = x;
  x = y;
  y = temp;
}
long long partition(long long *arr, long long low, long long high){
  long long incre_var = low-1;
  long long pivot = arr[high];
  for(long long index = low; index <= high-1; index++){
    if(arr[index] < pivot){
      incre_var++;
      swap_Element(arr[incre_var], arr[index]);
    }
  }
  swap_Element(arr[incre_var+1], arr[high]);
  return incre_var + 1;
}
void quick_sort(long long *arr, long long low, long long high){
  if(low < high){
    long long pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot-1);
    quick_sort(arr, pivot+1, high);
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
  quick_sort(arr, 0, number_element-1);
  print_arr(arr, number_element);
  return 0;

}