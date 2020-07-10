
#include <algorithm>
#include <iostream>
using namespace std;



int main(){

	int n = 5;
	double d[n] = {1,-2, 29, 21, 9};
	sort(d+3, d+n, greater<double>());
	
	for(int i = 0; i < n; i++){
		cout << d[i] << " ";
	}
	cout << endl;
	sort(d, d+n);
	for(int i = 0; i < n; i++){
		cout << d[i] << " ";
	}
}