//O(T*n)
//https://codeforces.com/contest/1833/submission/206485185
//https://codeforces.com/contest/1833/problem/D
#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    int ys[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ys[a[i]] = i;
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }
    int pos = ys[n];
    if (pos == 1){
        pos = ys[n - 1];
    } 
    if (pos == n && a[pos - 1] < a[1]) {
        cout << a[n] << " ";
        for (int i = 1; i < n; i++){
            cout << a[i] << " ";
        } 
        cout << "\n";
        return;
    }
    for (int i = pos; i <= n; i++){
        cout << a[i] << " ";
    }   
    cout << a[pos - 1] << " ";
    int id = pos - 2;
    for (int i = pos - 2; i >= 1; i--) {
        if (a[i] <= a[1]) {
            id = i;
            break;
        }
        cout << a[i] << " ";
    }
    for (int i = 1; i <= id; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++) {
        solve();
    }
    return 0;
}