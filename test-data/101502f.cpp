//O(tt*n*log(num) + tt*q)
//https://codeforces.com/gym/101502/submission/255801577
//https://codeforces.com/gym/101502/problem/F
#include "bits/stdc++.h"
using namespace std;


void solve() {
    int n;
    int q;
    cin >> n >> q;
    int vec[n];
    int dp[n + 1];
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    } 
    for (int i = 0; i < n; i++) {
        int num = vec[i];
        while (num>1) {
            if (num %2 == 1){
                dp[i + 1]++;
                num--;
            } 
            num /= 2;
            dp[i + 1]++;
        }
    }
    for (int i = 1; i <= n; i++){
        dp[i] += dp[i - 1];
    } 
    while (q>0) {
        q--;
        int l;
        int r;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl;
    }
}


int main() {
    int tt = 1;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++){
        solve();
    } 
}