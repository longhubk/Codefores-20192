#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k, m;

//cal x * y mod m
ll mod1(ll a, ll b, ll m){
	if (b==0) 
		return 0;
	ll res = mod1(a, b/2, m);
	if (b%2 == 0) 
		return (res + res) % m;
	else
		return (res + res + a) % m;
}

//cal a^b mod m
ll mod2(ll b, ll mx, ll m){
	
	if (mx == 0)
		return 1LL; 
	if (mx == 1)
		return b%m; 
	
	ll res = mod2(b, mx/2, m);
	if (mx % 2 == 0)
		return mod1(res, res, m);
	else
		return mod1(mod1(res, res, m), b, m);
}

//cal CkN
ll CKN(){
	ll a = 1LL, b = 1LL;

	for (ll i=n-k+1; i<=n; i++)
		a = mod1(a, i, m);

	for (ll i=1; i<=k; i++) 
		b = mod1(b, i, m);

	return mod1(a, mod2(b, m-2, m), m);
}

int main(){
	int T; cin>>T;
	while(T--){
		cin >> n >> k >> m;
		cout << CKN() << endl;
	}
}
