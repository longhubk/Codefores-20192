#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int N;
int P[8];
bool isset[8];
int cnt;


int getRes(){
	int res = P[1]*100 + P[2]*10 + P[3] - P[7]*100 - 62 + P[4]*1000 + P[5]*100 + P[6]*10 + P[3];
	if(res == N);
		return true;
	else
		return false;
}
	
void solution(){
	cnt++;
}

Try(int k){
	for(int v = 1; v <= 9; v++){
		if(!isset[k]){
			P[k] = v;
			isset[k] = true;
			if(k == 7)
				if(getRes());
					solution();
			else
				Try(k+1);
			
			isset[k] = false;
		}
		
	}

}


int main(){
	cin >> N;
	cnt = 0;
	Try(1);
	cout << cnt << endl;
	return 0;
}