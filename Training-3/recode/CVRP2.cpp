
/*
	================================= CVRP =================================================
	
	- Có K xe tải giống nhau cùng có trọng tải Q
	- Các xe bắt đầu tại điểm 0, giao hàng cho N khách hàng tại N địa điểm khác nhau. 
	- Khách hàng i yêu cầu d[i] kiện hàng. 
	- Tìm tổng số phương án giao hàng sao cho:
		+ mỗi khách hàng chỉ được giao đúng 1 lần
		+ tổng số kiện hàng của các khách hàng không được vượt quá tải trọng.
		+ mỗi xe tải phải giao cho ít nhất 1 khách hàng.
	- lưu ý: đường đi route: 0 -> 1 -> 2 -> 3 -> 0 khác 0 -> 3 -> 2 -> 1 -> 0
	- input:
	
		N P K ( 2 < N < 10) (1 < K < 5) (1 < Q < 20) 
		d[1], d[2].. d[N]
	
	- output:
		R mod 10^9 + 7
	
	- example:
		IN: 	3 2 4 
				3 2 1
		OUT:	4
		
		Explain: phương án 1: 	route[1] = 0 -> 1 -> 0 
								route[2] = 0 -> 2 -> 3 -> 0
								
				phương án 2:	route[1] = 0 -> 1 -> 3 -> 0
								route[2] = 0 -> 2 -> 0
								
				phương án 3:	route[1] = 0 -> 1 -> 0
								route[2] = 0 -> 3 -> 2 -> 0
								
				phương án 4: 	route[1] = 0 -> 2 -> 0
								route[2] = 0 -> 3 -> 1 -> 0
								
	=========================================================================================
	
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 30

int N, K, Q, y[MAX], x[MAX], d[MAX], load[MAX], segements, ans;
bool visited[MAX];

void solution(){
	ans++;
	return;
	for(int k = 1; k <= K; k++){
		cout << "0 ";
		int u = y[k];
		while(u > 0){
			cout << " -> " << u;
			u = x[u];
		}
		cout  << " -> 0" << endl;
	}
	cout << "--------------------------" << endl;
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
	
	for(int i = 1; i <= K; i++) load[i] = 0;
	segements = 0; ans = 0; y[0] = 0;
	
	Try_Y(1);
	cout << ans;
	
	return 0;
}