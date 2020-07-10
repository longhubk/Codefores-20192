#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

int n,
	c,
	X[MAX];
	
int getCow(int u){
	int res = 0;
	int last = -(int)1e9-10;
	for(int i = 1; i <= n; i++){
		if(X[i] - last  >= u){
			res++;
			last = X[i];
		}	
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		cin >> n >> c;
		for(int i = 1; i <= n; i++){
			cin >> X[i];
		}
			sort(X+1, X+n+1);
			int low = 0;
			int high = (int)1e9+10;
			
			while(high - low > 1){
				int mid = (low + high)/2;		
				int maxCow = getCow(mid);
				if(maxCow >= c) low = mid;
				else high = mid;
			}
		cout << low << endl;
	}
	return 0;
}