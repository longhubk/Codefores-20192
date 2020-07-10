#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
const double PI = 3.141592653589793238463;

int N,
    F,
    R[MAX];

int count_pie(double mid){
  int cnt = 0;
  for(int i = N; i >= 1 && cnt <= F; i--)
    cnt += (int)floor(PI * R[i] * R[i] / mid);
  return cnt;
}
void count_eater(){
  sort(R, R+N);
  double low = 0, high = 4e8, mid;
  for(int i = 0; i < 100; i++ ){
    mid = (high+low)/2;
    if(count_pie(mid) > F) low = mid;
    else high = mid;
    // cout << low << " - " << high << " - " << mid  << " - " << count_pie(mid) << endl;
  }
  printf("%0.6f", low);
}
int main(){
  int T;
  cin >> T;
  while(T--){
    cin >> N >> F;
    for(int i = 1; i <= N; i++) cin >> R[i];
    count_eater();
  }
  return 0;
}