/*
	============================== TSP ==========================================
	- Một người đi du lịch muốn thăm quan tất cả n-1 thành phố.
	- Mỗi thành phố thăm đúng 1 lần rồi quay trở lại thành phố xuất phát.
	- Đã Cho chi phí đi lại giữa các thành phố, tính tổng chi phí nhỏ nhất.
	
	- input:
			N M 		(N <= 20 : số thành phố, M <= 400 : số cặp k/c giữa 2 thành phố) 
	M dòng:	i j c[i,j]	(i,j <= n,c <= 10^6)
	
	- output: 
			Min_Cost
			
	- lưu ý: nếu từ thành phố i -> j không có mô tả chi phí thì không có đường đi trực tiếp
	từ i -> j
	
	ví dụ: 
			input: 	
					2 2
					1 2 3
					2 1 2
			output: 
					5
					
	==================================================================================
*/


#include <bits/stdc++.h>
using namespace std;
#define INF 999999
#define MAX 20
#define ll long long
ll N, M, Min_Cost, f, f_min, x[MAX], dis[400][400], cmin, ans;
bool visited[MAX];


void solution(){
	if(f + dis[x[N]][x[1]] < f_min){
		f_min = f + dis[x[N]][x[1]];
		ans = f_min;
	}
}


void Try(ll k){
	
	for(ll v = 1; v <= N; v++){
		if(!visited[v] && dis[x[k-1]][v] != -1 && dis[x[k-1]][v] != 0){
			x[k] = v;
			
			f += dis[x[k-1]][x[k]]; 
			visited[v] = true;
			if(k == N){
				solution();
			}else{
				ll g = f + cmin*(N-k+1);
				if(g < f_min)
					Try(k+1);
			}
			
			f -= dis[x[k-1]][x[k]]; 
			visited[v] = false;
		}
	}
	
}


int main(){
	cmin = INF;
	f_min = INF;
	cin >> N >> M;
	memset(dis, -1, sizeof(dis));
	for(ll i = 1; i <= N; i++){
		visited[i] = false;
	}
	for(ll i = 1; i <= M; i++){
		
		ll start, end, cost;
		cin >> start >> end >> cost;		
		if(cmin > cost) cmin = cost;
		dis[start][end] = cost;
	}
	x[1] = 1; visited[1] = true; f = 0;
	Try(2);
	cout << ans;
	
	return 0;
}