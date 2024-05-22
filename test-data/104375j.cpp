//O(n+q)
//https://codeforces.com/gym/104375/submission/206685942
//https://codeforces.com/gym/104375/problem/J
#include "bits/stdc++.h"

using namespace std;


int main(){
    int mod = 1000000007;
    

    int n;
    int q;
    cin >> n >> q;
    int v[n];
    int ps[n+1];
    int ql[n+1];
    int qr[n+1];

    for(int i = 0; i < n; i++){
        cin >> v[i];

        ps[i+1] = (ps[i] + v[i]) % mod;
        qr[i+1] = (qr[i] + (ps[i] * v[i]) % mod) % mod;
    }

    for(int i = 0; i < n; i++){
        ql[i+1] = (ql[i] + (v[i] * ((ps[n] - ps[i+1] + mod) % mod)) % mod) % mod;
    }

    while(q>0){
        q--;
        int l;
        int r;
        cin >> l >> r;

        int ans = qr[r];
        ans = (mod + ans - (mod + ql[l-1] - ((ps[l - 1] * (ps[n] - ps[r]) % mod))) % mod) % mod;
        if(l == r){
            ans += v[l-1];
        } 
        cout << ans << "\n";
    }

    return 0;
}