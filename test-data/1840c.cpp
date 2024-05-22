//O(ttt*n)
//https://codeforces.com/contest/1840/submission/208735508
//https://codeforces.com/contest/1840/problem/C
#include "bits/stdc++.h"
using namespace std;

void solve(int tt){
    int n;
    int k;
    int q;
    cin>>n>>k>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int r=0-1;
    int ans=0;
    for(int l = 0;l<n;l++){
        if(r<l){
            r=l;
            while(a[r]<=q&&r<n){
                r++;
            }
            r--;
        }
        ans+=max(0,r-l+2-k);
    }
    cout<<ans<<'\n';
}

int main(){
    int tt=1;
    int ttt;cin>>ttt;
    for(int tt=1;tt<=ttt;tt++){
        solve(tt);
    }
    
}