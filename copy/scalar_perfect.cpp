#include<iostream>
#include<algorithm>
using namespace std;
int T,n;
int i,j,p;
long long rs,x[1000],y[1000];

int main(){
	cin >> T;
	for (p=1;p<=T;p++){
		rs = 0;
		cin >> n;
		for (i=0;i<n;i++) cin >> x[i];
		for (i=0;i<n;i++) cin >> y[i];	
		sort(x,x+n);
		sort(y,y+n);
		for (i=0;i<n;i++) rs += x[i]*y[n-1-i];
		cout << "Case #" << p << ": " << rs << endl;
	}
}