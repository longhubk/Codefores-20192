#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f[11] = {1, 1, 1, 1, 2, 1, 2, 1, 1, 3, 1};
int c[11] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3, 2};
ll p[16];

int main(){
	p[0] = 1;
	for (int i = 1; i < 16; i++)
		p[i] = p[i-1] * 10;

	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		ll w, m; cin >> w >> m;
		ll n = 0, s = 1;
		if(w % 1000){
			cout << 0 << endl;
			continue;
		}
		w /= 1000;
		for(int i = 0; i < m; i++){
			int d = w % 10;
			w /= 10;
			n += c[d];
			s *= f[d];
		}

		bool a = (w >= 5);
		n += (w - 5 * a) / 5;
		w = w % 5;

		n += c[w + 5 * a];
		s *= f[w + 5 * a];

		cout << n << " " << s << endl;
	}

	return 0;
}
