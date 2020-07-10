#include<bits/stdc++.h>
using namespace std;

int x[1001], y[1001];
int T;
int n;
bool mark[1001]={false};
int x_min=99999, y_min=99999;
long long res=999999999999999999, f=0;



int TRY(int k){
    for (int v=1; v<=n; v++){
        if (!mark[v]){
            f += x[k]*y[v];
            mark[v]=true;
            if (k==n){
                if (f<res) res=f;
            }
            else{                
                TRY(k+1);
            }
            f-=x[k]*y[v];
            mark[v]=false;
        }
    }
}


int main(){
    cin>>T;
    for (int t=1; t<=T; t++){

            cin>>n;
            for (int i=1; i<=n; i++) {
                cin>>x[i];
                if (x[i]<x_min) x_min=x[i];
            }
            for (int i=1; i<=n; i++) {
                cin>>y[i];
                if (y[i]<y_min) y_min=y[i];
            }
            res=999999999999999999;
            TRY(1);
            cout<<"Case #"<<t<<": "<<res<<endl;
    }
}