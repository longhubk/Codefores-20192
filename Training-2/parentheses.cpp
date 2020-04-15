#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int test_parenthese(string str){
  stack<char> stack;
  for(int index = 0; index < str.length(); ++index){
    char c = str[index];
    if(c == '(' || c == '[' || c == '{'){
      stack.push(c);
      continue;
    }

    if(stack.empty()){
      return 0;
    }
    switch (c)
    {
    case ')': 
      if(stack.top() != '('){
        return 0;
      }else{
        stack.pop();
      }
      break;
    case ']': 
      if(stack.top() != '['){
        return 0;
      }else{
        stack.pop();
      }
      break;
    case '}': 
      if(stack.top() != '{'){
        return 0;
      }else{
        stack.pop();
      }
      break;

    }
  }
  if(stack.empty())
    return 1;
  else
    return 0;
}

int main(){
  int number_test;
  cin >> number_test;
  string str_char[number_test];

  for(int index = 0; index < number_test; index++){
    cin >> str_char[index];
  }
  for(int index = 0; index < number_test; index++){
    cout << test_parenthese(str_char[index]) << "\n";
  }

  return 0;
}