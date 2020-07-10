#include <bits/stdc++.h>
using namespace std;
#define MAX 30

int N; //so khach hang
int K; //so xe
int Q; //Trong tai xe

int d[MAX]; 		//d[i] : luong hang yeu cau cua khach hang i
int x[MAX]; 		//x[i] : diem tiep theo cua diem i trong lo trinh xe k
int y[MAX]; 		//y[i] : diem dau tien cua lo trinh xe i

bool visited[MAX]; 	//visited[i] = true : da tham diem i

int load[MAX]; 	  	// load[i] : luong hang da co tren xe i 
int ans; 			// ket qua
int segements; 	 	//so doan = N + K (so xe + so khach hang) 
void input(){
	cin >> N >> K >> Q;
	for(int i = 1; i <= N; i++)
		cin >> d[i];
}
void solution(){
	ans++;
	for(int k = 1; k <= K; k++){
		cout << "0 ";
		int u = y[k]; 	//gan u la diem dau tien trong lo trinh xe k
		while(u > 0){
			cout << " -> " << u;
			u = x[u];   //gan u la diem tiep theo cua u
		}
		cout << " -> 0" << endl;
	}
	cout << " ---------------------------------" << endl;
}

bool check_X(int v, int k){
	if(v > 0){
		if(visited[v]) return false;
		if(load[k] + d[v] > Q) return false;
	}
	return true;
}

//tim diem tiep theo cho xe k
void Try_X(int s, int k){ //thu gia tri x[s](diem tiep theo cua diem start) tren lo trinh xe k
	for(int v = 0; v <= N; v++){
		if(check_X(v, k)){
			x[s] = v;  		//_tim duoc tiem tiep theo cua xe k
			visited[v] = true;
			segements++;
			load[k] += d[v];
			
			if(v == 0){ 		//xe da ve kho hang
				if(k == K){
					if(segements == K+N) solution(); // dieu kien so chang = so xe + so khach
				}else{
					Try_X(y[k+1], k+1); //duyet xong xe k thi duyet xe k+1 bat dau tu y[k+1]
				}
			}else{
				Try_X(v,k); 	//neu chua ve kho thi tim diem tiep theo van tren lo trinh xe k
			}
			visited[v] = false;
			segements--;
			load[k] -= d[v];
			
		}
		
	}
	
}
//kiem tra gia v co hop le voi y[k] hay khong
bool check_Y(int v, int k){
	if( visited[v]) return false; 	//neu da tham diem v thi khong tham nua
	if( load[k] > Q) return false; 	// neu trong tai cua xe k > MAX thi khong xet nua
	return true;
}

//tim diem khoi dau cho xe k
void Try_Y(int k){ 				//thu tat ca gia tri cho y[k] (y[1], y[2], y[3] ... y[K]) 
	for(int v = y[k-1]+1; v <= N; v++){
		if(check_Y(v, k)){
			y[k] = v; 			//kq cua Try_Y
			
			//init backtrack
			visited[v] = true; 	//danh dau da tham diem v
			load[k] += d[v];    //them tai cua khach hang v vao trong tai xe
			segements++; 		//tang so doan len +1
			
			
			if(k == K){ 		//neu nhu da duyet xong tat ca y[1] .. y[K]
				Try_X(y[1], 1); //duyet diem tiep theo y[1] theo lo trinh xe 1
			}else{
				Try_Y(k+1);     //nguoc lai duyet tiep gia tri k tiep theo
			}
			
			//backtrack 
			visited[v] = false; 	
			load[k] -= d[v];    
			segements--; 		
			
		}
		
	}
} 
 


void solve(){
	y[0] = 0;
	ans = 0;
	segements = 0;
	for(int i = 1; i <= K; i++){
		load[i] = 0;
	}
	Try_Y(1); //Thu diem y[1] cho lo trinh xe 1
	cout << ans;
}

int main(){
	input();
	solve();

	return 0;
}