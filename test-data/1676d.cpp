//O(n*m*T)
//https://codeforces.com/contest/1676/submission/156644536
//https://codeforces.com/contest/1676/problem/D
#include "bits/stdc++.h"
using namespace std;

int main(){
    int sum1[1010];
    int sum2[1010];
    int a[201][201];
    int T;cin>>T;
    while(T>0){
        T--;
        int n;
        int m;cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                int x=a[i][j];
                sum1[i+j]+=x;
                sum2[i-j+200]+=x;
            }
        }
        
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans=max(ans,sum1[i+j]+sum2[i-j+200]-a[i][j]);
            }
        }
        
        cout<<ans<<endl;
    }
}