#include <bits/stdc++.h>
#include <map>
using namespace std;
#define MAX 100001

map<int,char> un_map = {{1, 'a'}, {200, 'b'}};

void function(){
  
}
int main(){
  cout << "un_map[1]: " << un_map[1] << endl;
  cout << "un_map[2]: " << un_map[200] << endl;
  
  un_map[200] = 'c';

  cout << "un_map[2] after: " << un_map[200] << endl;

  for(auto& elm : un_map){
    cout << elm.first << " ; " << elm.second << endl;
  }
  cout << endl;

  auto result = un_map.find(202);
  if(result != un_map.end()){
    cout << "found " << result->first << " ; " << result->second << endl;
  }else{
    cout << "not found" << endl;
  }

  return 0;
}