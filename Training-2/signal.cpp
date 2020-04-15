#include <iostream>
using namespace std;

long long maxNumber(long long *sub_arr,int start, int end){
  long long max = 0;
  for(long long index = start; index < end; index++ ){
    if(max < sub_arr[index])
      max = sub_arr[index];
  }
  return max;
}

long long isDoubleSignal(long long *arr, int num, int b){
  long long max_num = 0;
  int index_res = 0;
  for(int index = 0; index < num; index++){
    if(arr[index] < b){
       if(index != 0 && index != num-1){
         long long max_left = maxNumber(arr,0,index);
         long long max_right = maxNumber(arr,index+1, num);
         if( max_left >= b && max_right >= b){
           long long total = max_left - 2*arr[index] + max_right;
           if(max_num < total){
            max_num = total;
            index_res = index;
           }
         }

       }
    }
  }
  return max_num;

}

int main(){
  int n,b;
  cin >> n >> b;
  long long array[n];
  for(int index = 0; index < n; index++){
    cin >>  array[index];
  }
  cout << isDoubleSignal(array, n, b);
  return 0;
}
