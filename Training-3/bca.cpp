#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <vector>
#define FOR(a,c) for (int(a) = 0; (a) < (c) ; (a)++)
using namespace std;

// vector<int> teach[100];
// vector<int> conflict[100];
// vector<int> cant_assign[100];
// vector<int> load;

int * teach[1000] = {0};
int * conflict[1000] = {0};
int * cant_assign[1000] = {0};
int * load;

const int INF = 1e9; 


int m, //!number teacher
    n, //!number course
    ans,
    q; //!number conflict


int get_ans(){
  return *max_element(load, load+n);
}

bool cmp (int p, int q){ 
  return load[p] < load[q];
}

void arrange(int i){
  if(get_ans() >= ans) return; //_state in future alway better than this branch
  if(i > n){  //_ search all course
    ans = min(ans, get_ans()); //* update answer
    return;
  }
  vector<int> index; //_ store teachers who can teach course i

  FOR(j, m){ //_for all teachers
    //* if teacher j can have couse i
    //* and teacher j don't have course conflict with course i before
    if(teach[j][i] == 1 && cant_assign[j][i] == 0)
      index.push_back(j);
  } 
  sort(index.begin(), index.end(), cmp); //_sort all teacher follow number course


  for(int j : index) //_c++ 11
  {
    //*update load and cant_assign 
    load[index[j]]++; //_index[j] is index of teacher have teach course i
    FOR(k, m){
      cant_assign[index[j]][i] = 1;
    }

    arrange(i+1); //_call recursion

    //*backtrack re update load and cant_assign
    load[index[j]]--;
    FOR(k, m){
      cant_assign[index[j]][i];
    }
  }
  
}
int main(){
  cin >> n >> m ;
  FOR(i, m){
    int k; //_number course avalable of teacher i
    cin >> k;
    while(k--){
      int p; //_index of course
      cin >> p;
      teach[i][p] = 1; //_mark that course is teach avalable by teacher i
    }
  }

  cin >> q;
  while(q--){
    int q1, q2; //_ two course conflict
    cin >> q1 >> q2;
    if(q1 > q2)
      swap(q1, q2); //_ sort course 1 alway smaller than course 2
    conflict[q1][q2] = 1; //_ mark that q1 and q2 is conflict
  } 
  
  ans = INF; //_answer iniatal with infinity 
  arrange(1);
  cout << ans << endl;

  // int n; 
  // cin >> n;
  // // memset(load, load + n, )
  // for(int i = 0 ; i < n; i++){
  //   int m;
  //   cin >> m;
  //   int j = 0;
  //   load[i] = new int[m];
  //   while(m--){
  //     cin >> load[i][j];
  //     j++;
  //   }
  // }

  // FOR(i, n){
  //   int rows = sizeof(load[i]);
  //   // cout << rows << endl;
  //   FOR(j, rows){
  //     if(load[i][j] > 0)
  //     cout << load[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  
return 0;
}