/*
	------------------------------ BCA ----------------------------------
	phân công n khóa học cho m giáo viên.
	mỗi giáo viên có 1 danh sách các khóa học.
	có 1 danh sách các khóa học không được trùng lặp
	
	
	
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 30
#define INF 999999
#define MAX_M 10
int m,
	n,
	teach[MAX_M][MAX_N],
	conflict[MAX_N][MAX_N],
	load[MAX_M],
	cant_assign[MAX_M][MAX_N],
	ans;
vector <int> teachK[MAX_M];
bool cmp(int p, int q){
	return load[p] < load[q];
}
int get_ans(){
	return *max_element(load +1, load + m + 1);
}

void Try(int k){
	if(get_ans() >= ans) return;
	if(k > n){
		ans = min(ans, get_ans());
		return;
	}
	vector <int> index; // cac giao vien co the day course k
	for(int j = 1; j <= m; j++){
		if(teach[j][k] == 1 && cant_assign[j][k] == 0){
			index.push_back(j);
			teachK[j].push_back(k);
		}
			
	}
	sort(index.begin(), index.end(), cmp);
	for(int j : index){
		load[j]++;
		for(int i : teachK[j]){
			if(conflict[k][i] == 1 && teachK[j][i] != k)
				cant_assign[j][k] == 1;
		}
		
		Try(k+1);
		load[j]--;
		for(int i : teachK[j]){
			if(conflict[i][k] == 1 && teachK[j][i] != k)
				cant_assign[j][k] == 0;
		}
		
	}
}	

int main(){
	cin >> m >> n;
	
	for(int i = 1; i <= m; i++){
		int k; cin >> k;
		load[i] = 0;
		for(int j = 1; j <= k; j++){
			int ct; cin >> ct;
			teach[i][ct] = 1;
		}
	}
	int c; cin >> c;
	for(int i = 1; i <= c; i++){
		int c1, c2; cin >> c1 >> c2;
		if(c1 > c2){
			swap(c1, c2);
		}
		conflict[c1][c2] = 1;
	}
	memset(cant_assign, 0, sizeof(cant_assign));
	memset(load, 0, sizeof(load));

	ans = INF;
	//for(int i = 0; i < sizeof(load); i++){
		//cout << load[i];
	//}
	Try(1);
	cout << ans << endl;
}
	