/*
	================================== C B A =========================================
	
	- Có n môn học (1..n) phân công cho m giáo viên (1,2...m).
	- Mỗi giáo viên có danh sách lớp có thể dạy
	- Vì thời biểu được sắp trước nên sẽ giữa n môn học sẽ có các cặp trừng thời khóa biểu.
	- Dùng ma trận A(i,j) (0 - 1) : A(i,j) = 1 nghĩa là môn i và j trùng thời khóa biểu
	
	=> Hãy liệt kê tất cả các phương án phân công giảng dạy.
	
	- input: 
			n m 					(1 <= m < n <= 10) 
			k t[1] t[2] ... t[k] 	(k : số giáo viên có thể dạy môn i; t[1..k] giáo viên
			i = 1,...,n 			(phần tử dòng thứ i của ma trận A)




*/
#include <bits/stdc++.h>
#define MAX_N 100
#define MAX_M 30
using namespace std;

int N,					// số course
	M,					// số giáo viên
	sz[MAX_N], 			// sz[c] : số giáo viên có thể dạy môn c
	t[MAX_N][MAX_M], 	// t[c][i]: giáo viên thứ i có thể dạy môn c
	h[MAX_N],			// h[c] : số giờ dạy của môn c mỗi tuần
	A[MAX_N][MAX_N],	// A[i][j] = 1 có nghĩa là môn i và j bị xung đột
	f[MAX_M],			// f[i] : tổng số giờ dạy của giáo viên i
	X[MAX_N],			// X[i] : là giáo viên đã dạy course i
	cnt;				// số phương án
	
	
	
void input(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++) 		
		cin >> h[i];
	
	for(int i = 1; i <= N; i++){ 		
		cin >> sz[i];
		for(int j = 1; j <= sz[i]; j++)	
			cin >> t[i][j];
	}
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)		
			cin >> A[i][j];
	
}
void solution(){
	cnt++;
	cout << "solution: " << cnt << endl;
	for(int t = 1; t <= M; t++){
		cout << "course of teach " << t << ": ";
		for(int i = 1; i <= N; i++) 
			if(X[i] == t) cout << i << ", ";
		cout << "hour = " << f[t] << endl;
	}
	cout << "--------------------------------------"<< endl;
}
bool check(int v, int k){
	for(int i = 1; i <= k-1; i++){
		if(A[i][k] && v == X[i]) return 0;
	}
	return 1;
}
void Try(int k){
	for(int i = 1; i <= sz[k]; i++){
		int v = t[k][i];
		if(check(v,k)){
			X[k] = v;
			f[v] += h[k];
			if(k == N){
				solution();
			}else{
				Try(k+1);
			}
			f[v] -= h[k];
		}
	}
}


void solve(){
	for(int i = 1; i <= M; i++) 
		f[i] = 0;
	cnt = 0;
	Try(1);
}
	
int main(){
	input();
	solve();
	return 0;
}