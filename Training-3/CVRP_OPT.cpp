
/*
	================================= CVRP OPT =================================================
	
	- Có K xe tải giống nhau cùng có trọng tải Q
	- Các xe bắt đầu tại điểm 0, giao hàng cho N khách hàng tại N địa điểm khác nhau. 
	- Khách hàng i yêu cầu d[i] kiện hàng. 
	- khoảng cách từ vị trí i -> j là c[i,j], (0 <= i,j <= n)
	
	- Tìm phương án giao hàng có tổng số quãng đường ngắn nhất sao cho:
		+ mỗi khách hàng chỉ được giao đúng 1 lần
		+ tổng số kiện hàng của các khách hàng không được vượt quá tải trọng.
		+ mỗi xe tải phải giao cho ít nhất 1 khách hàng.
		
	- lưu ý: đường đi route: 0 -> 1 -> 2 -> 3 -> 0 khác 0 -> 3 -> 2 -> 1 -> 0
	
	- input:
	
		N P K                      ( 2 < N < 12) (1 < K < 5) (1 < Q < 50) 
		d[1], d[2].. d[N] 
		c[0,0],c[0,1],.....c[0,N]  (1 <= c[i,j] <= 30)
		.		.			.
		.  		.			.
    	.		.			.
		c[N,0],c[N,1,......c[N,N]
	
	- output:
		R (minimal total travel distance)
	
	- example:
		IN: 	4 2 15
				7 7 11 2
				0 12 12 11 14
				14 0 11 14 14
				14 10 0 11 12
				10 14 12 0 13
				10 13 14 11 0
				
		OUT:	70
		

	=========================================================================================
	
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 30
#define INF 999999999

int N, K, Q, y[MAX], x[MAX], d[MAX], load[MAX], dis[MAX][MAX], segements, ans;
bool visited[MAX];

void solution(){
	int total_dis = 0;
	for(int k = 1; k <= K; k++){
		int u = y[k];
		total_dis += dis[0][u];
		while(u > 0){
			total_dis += dis[u][x[u]];
			u = x[u];
		}
	}
	if(ans > total_dis) ans = total_dis;
}
bool check_x(int v, int k){
	if(v > 0){ // if v == 0 ---> auto true because 0 don't need check
		if(visited[v]) return false;
		if(load[k] + d[v] > Q) return false;
	}
	return true;
}

void Try_X(int s, int k){
	for(int v = 0; v <= N; v++){
		if(check_x(v, k)){
			x[s] = v;
			visited[v] = true; load[k] += d[v]; segements++;
			
			if(v == 0){
				if(k == K){
					if(segements == N+K) solution();
				}else
					Try_X(y[k+1], k+1);
			}else
				Try_X(v, k);

			visited[v] = false; load[k] -= d[v]; segements--;
		}
	}
}

void Try_Y(int k){
	for(int v = y[k-1]+1; v <= N; v++){
		if(!visited[v] && load[k] < Q){
			y[k] = v;
			visited[v] = true; load[k] += d[v]; segements++;
			if(k == K)
				Try_X(y[1], 1); 
			else
				Try_Y(k+1);
			
			visited[v] = false; load[k] -= d[v]; segements--;
		}	
	}
}

int main(){
	cin >> N >> K >> Q;
	for(int i = 1; i <= N; i++) cin >> d[i];
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			cin >> dis[i][j];
		}
	}
	
	for(int i = 1; i <= K; i++) load[i] = 0;
	segements = 0; ans = INF; y[0] = 0;
	
	Try_Y(1);
	cout << ans;
	
	return 0;
}