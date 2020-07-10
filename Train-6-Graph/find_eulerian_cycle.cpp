#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int N;
vector<int>a[MAX];
stack<int> S, CE;

void deleteEdge(int x, int y){
  a[x].erase(a[x].begin(), a[x].begin()+1);
  
  for(int i = 1; i <= N; i++){
    for(int j = 0; j <= a[i].size(); j++){
      if(a[i][j] == x){
        a[i].erase(a[i].begin(), a[i].begin()+1);
      }
    }
  }
}

void find_eulerian_cycle(int u){
  S.push(u);
  while(!S.empty()){
    int x = S.top();
    if(!a[x].empty()){
      int y = a[x][0];
      S.push(y);
      deleteEdge(x, y);
    }else{
      x = S.top(); S.pop(); CE.push(x);
    }
  }
}
void printStack(stack<int> Stack){
  while(!Stack.empty()){
    cout << Stack.top() << ",";
    Stack.pop();
  }
}

int main(){
  int M;
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int u, v; cin >>u >> v;
    a[u].push_back(v); a[v].push_back(u);
  }
  find_eulerian_cycle(1);
  printStack(CE);


  
return 0;
}