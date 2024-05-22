//O(s)
//https://codeforces.com/gym/103061/submission/257847447
//https://codeforces.com/gym/103061/problem/B
#include "bits/stdc++.h"
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0-1;
    for(int i = 0; i+1 < s.size(); i++) {
        if(s[i] != s[i+1]) {
            ans = 2;
            break;
        }
    }
    cout <<ans <<'\n';
}