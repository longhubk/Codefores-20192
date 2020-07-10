#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;

float res = 999999999999;
int p[10000];
const float PI = 3.14159265358979323846;

float min(float x, float y){
  return (x < y) ? x : y;
}

float Try(int i,int f, int n, float v, float V){
  if(i > f){
    return min(res, v);
  }
  for(int k = 1; k <= n; k++){
    p[i] = k;
    v = min(v, (V/p[i]));
    Try(i+1,f, n, v, V);
  }
}
int main(){
  int t; 
  cin >> t;
  for(int i = 0; i < t; ++i){
    int n, f;
    cin >> f >> n;
    int r;
    cin >> r;
    float V =  PI*r*r;
    // cout << V << endl;
    printf("%6f",Try(0,f, n, 9999999999999, V));
    cout << endl;
  }

  
return 0;
}