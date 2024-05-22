//O(ms*log(log(ms)) + q)
//https://codeforces.com/gym/103274/submission/129847767
//https://codeforces.com/gym/103274/problem/C
#include "bits/stdc++.h"
using namespace std;



void solve() {
    int ms = 1000005;
    int notPrime[ms];
    vector<int> v;
    int q;
    cin >> q;
    for (int i = 2; i < ms; i++) {
        if(notPrime[i] == 0){
            continue;
        } 
        v.push_back(i);
        for(int j = i+i; j < ms; j += i){
            notPrime[j] = 1;
        } 
    }
    while(q>0) {
        q--;
        int l;
        int r;
        cin >> l >> r;
        cout << upper_bound(v.begin(), v.end(), r) -  lower_bound(v.begin(), v.end(), l) << '\n';
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while(t>0) {
        t--;
        solve();
    }
}