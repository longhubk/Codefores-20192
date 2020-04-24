#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;


string binaryNext(string str, int num){

if(str.length() > 0 && str.length() == num){

  int index = 0;
  for(index = num-1; index >= 0; index--){
    if(str.at(index) == '0'){
      str.at(index) = '1';
      break;
    }
    else
    {
      str.at(index) = '0';
    }
  }
    if(index < 0){
      str  = '1' + str;
    }
    return str;

}else
{
  return "-1";
}


  
}
int main(){
  int num;
  cin >> num;
  string str;
  cin >> str;

  cout << binaryNext(str,num);

  
return 0;

}