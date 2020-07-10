#include<bits/stdc++.h>
using namespace std;
#define MAX_T 11
#define MAX_C 31

bool	T[MAX_T][MAX_C], // T[i][j] = true giao vien i co the day lop j, false nguoc lai
			X[MAX_C][MAX_C]; // X[i][j]=1 lop i conflict lop j
int	m, // number teacher
		n, // number course
		load[MAX_T],    // dem so lop ma giao vien i phai day
		res=99,
		C[MAX_C];     // C[i]=j co j giao vien co the day lop i

void TRY(int i){ 
	for(int j = 1; j <= m; j++){		 //_try
		if(T[j][i] && C[i]>0){

			T[j][i] = false;							//_
			load[j]++;
			C[i] = 0;
			bool mark[n+1];
			for(int k = 1+i; k <= n; k++){
				mark[k] = false;
				if(X[i][k])
					T[j][k] = false,
					mark[k] = true;
			}

			int g = *max_element(load, load+m);
			if(i == n){
				if(res > g) res = g;
			}
			else
				if(g < res) TRY(i+1);
			
			
			T[j][i] = true;
			load[j]--;
			C[i]=2;
			for (int k = 1+i; k <= n; k++){
				if(mark[k])
					T[j][k] = true,
					mark[k] = false;
			}
		}
	}
	
}

void init(){
	for (int i = 0; i < MAX_T; i++){
		load[i] = 0;
		for (int j = 0; j < MAX_C; j++)
			T[i][j] = false;
	}
	for (int i = 0 ; i < MAX_C; i++){
		C[i] = 0;
		for (int j = 0; j < MAX_C; j++)
			X[i][j] = false;
	}
}
int main(){
		init();
		cin>> m >> n;
		int k, c;
		for (int i = 1; i <= m; i++){
			cin >> k;					//_teacher_i_can_teach_k_course
			for (int j = 1; j <= k ; j++){
				cin >> c;
				T[i][c] = true;	//_teacher_i_can_teach_course_c
				C[c]++;					//_course_c_has_more_teacher_can_teach
			}
		}
		cin >> k;						//_k_is_number_pair_course_conflict
		for (int i = 1; i <= k; i++){
			int u, v; cin >> u >> v;
			X[u][v] = true;
		}

		TRY(1);
		if (res == 99) cout << -1;
		else cout << res;
}