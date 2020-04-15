#include <iostream>
using namespace std;

int min(int a, int b){
  int min;
  if(a<b){
    min = a;
  }
  else 
    min = b;
  return min;
}

int greatestCommonDivisor(int a, int b){
  if(a == 0)
    return b;
  return greatestCommonDivisor(b % a, a);
  
}
int minStepPump(int fromJup, int toJup, int c){
  int from = fromJup;
  int to = 0;

  int step = 1;
  while(from != c && to != c){
    int max_can_pour = min(from, toJup - to);
    from -= max_can_pour;
    to += max_can_pour;

    step++;
    if(from == c || to == c){
      break; 
    }
    if(from == 0){
      from = fromJup;
      step++;
    }
    if(to == toJup){
      to = 0;
      step++;
    }
  }
  return step;

}

int minStep(int a, int b, int c){
  int big, small;
  if(a > b){
    big = a;
    small = b;
  }else{
    big = b;
    small = a;
  }
  int gcd = greatestCommonDivisor(small, b);
  if(c > big)
    return -1;
    
  if(c % gcd == 0){

  }else{
    return -1;
  }
  return min(minStepPump(big,small,c), minStepPump(small,big,c));



}

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  cout << minStep(a,b,c);

  return 0;
}