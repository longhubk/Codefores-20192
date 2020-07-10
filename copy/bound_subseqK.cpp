#include<bits/stdc++.h>
using namespace std;

int m, M, n, Q=0;;
int a[20001];
int S[20001];
int mark=2;
int sub(){
    if (a[1]<=M && a[1]>=m) {
        S[1]=a[1];
        Q=1;
    }
    else {
        S[1]=a[1];
        Q=0;
    }
    for (int i=2; i<=n; i++){
        int t = S[i-1]+a[i];
        if (t<=M && t>=m){
            Q++;
            S[i]=t;
            int s=a[i];
            for (int j=i-1; j>mark; j--){
                if (s+a[j]>M || s+a[j]<m ) break;
                s+=a[i];
                Q++;
            }
        }
        else{
            S[i]=a[i];            
            if (S[i]>=m && S[i]<=M) Q++; 
            int s=a[i];
            for (int j=i-1; j>mark; j--){
                if (s+a[j]>M || s+a[j]<m ) break;
                s+=a[i];
                Q++;
            }
            mark=i;
        }

    }
}
int main(){
    cin>>n>>m>>M;
    for (int i=1; i<=n; i++) {
        cin>>a[i];
    }
    sub();
    cout<<Q;
}