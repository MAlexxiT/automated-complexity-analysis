//O(t*n^2)
//https://codeforces.com/contest/1937/submission/248914712
//https://codeforces.com/contest/1937/problem/B
#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n; cin >> n;
    string s;
    string t; cin >> s >> t;
    int cur = 1;
    string ans;
    ans+=s[0];
    for(int i=1; i<n; i++){
        if(t[i-1]<s[i]){
            for(int j=i-1; j<n-1; j++){
                ans+=t[j];
            } 
            break;
        }
        else{
            if(t[i-1]==s[i]){
                cur++;
                ans+=s[i];
            }
            else{
                cur=1;
                ans+=s[i];
            }
        }
    }
    ans+=t[n-1];
    cout << ans << endl;
    cout << cur << endl;
}



int main(){

    int t=1;
    cin >> t;
    while(t>0){
        t--;
        solve();
    } 
}