/*
  _the building have F floor
  _elvator current in S floor
  _need go to G floor
  _elvator just up U floor and down D floor
  _find minimun step press button up or down to get to G floor


*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int F, G, S, U, D;
vector<int> a[MAX];

void build_graph(){
 	for(int i = 1; i <= F; i++) {
 		if(i+U < F){
 			a[i].push_back(i+U);
 			
 		}
 		if(i-D > 0){
 			a[i].push_back(i-D);

 		}
 	}
}

int BFS(){

}
int main(){
  cin >> F >> S >> G >> U >> D;

  build_graph();
  cout << BFS();
  
return 0;
}