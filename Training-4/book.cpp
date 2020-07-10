 #include <bits/stdc++.h>
 using namespace std;
 #define ll long long
 const int N = 510;
 int m, k, p[N], a[N];
 
 bool check(ll u, int output = 0){ //u is the max page need to copy
	ll cur = 0;  //num pages of current people
	int res = 1;
	if(output){
		memset(a, 0, sizeof a);
	}
	int numA = 0;
	for(int i = m; i >= 1; i--){
		if(p[i] > u) return 0; //none exist sulution num page of 1 book > max page need to copy
		if(cur + p[i] <= u ){
			cur += p[i]; //give next book for current people
		}else{
			res++;
			cur = p[i]; //else give next book for next people
			a[i] = 1;
			numA++;
		}
	}
	if(output){
		for(int i = 1; i <= m; i++){
			if(numA < k-1 && a[i] == 0){
				a[i] = 1;
				numA++;
			}
		}
		for(int i = 1; i <= m; i++){
			cout << p[i] <<  ' ';
			if(a[i]) cout << "/ ";
		}
		cout << endl; 
	}
	return res <= k;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc; 
	cin >> tc;
	while(tc--){
		cin >> m >> k;
		for(int i = 1; i <= m; i++){
			cin >> p[i];
		}
		ll low = 0, high = 1e10, mid;
		while(high - low > 1){
			mid = (low + high)/2;
			if(check(mid)) high = mid;
			else low = mid;
		}
		check(mid, 1);
	}
	return 0;
}