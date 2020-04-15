#include <iostream>
#include <stack>
using namespace std;

int cal_area(int * arr, int num){
  stack<int> stack;
  int area = 0;
  int area_on_top;
  int top_i;
  int i = 0;

  while(i < num){
    if(stack.empty() || arr[i] >= arr[stack.top()]){
      stack.push(i++);
    }
    else{
      top_i = stack.top();
      stack.pop();
      area_on_top = arr[top_i]* (stack.empty() ? i : i - stack.top() - 1);
      if(area < area_on_top)
        area = area_on_top;
    }
  }
  while(!stack.empty()){
      top_i = stack.top();
      stack.pop();
      area_on_top = arr[top_i]* (stack.empty() ? i : i - stack.top() - 1);
      if(area < area_on_top)
        area = area_on_top;
  }
  return area;
}

int main(){
  int num_bar = 1;
  int arr_res[100000];
  int index = 0;
  while(num_bar != 0){

    cin >> num_bar;
    if(num_bar > 0){
      int arr[num_bar];
      for(int i = 0; i < num_bar; i++){
        cin >> arr[i];
      }
      arr_res[index++] = cal_area(arr, num_bar);
    }

  }
  for(int i = 0; i < index; i++){
    cout << arr_res[i] << "\n";
  }

  return 0;
  
}