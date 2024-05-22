//O(t*log(k))
//https://codeforces.com/contest/1612/submission/136683300
//https://codeforces.com/contest/1612/problem/C
#include "iostream"
#include "cmath"
#include "vector"
#include "set"
#include "chrono"
#include "random"
#include "queue"
#include "cassert"
#include "map"
#include "algorithm"

using namespace std;

long long int emotes (long long int rows, long long int k) {
    //we do row rows
    if (rows <= k) {
        return rows * (rows + 1)/2;
    }
    rows -= k;
    return k * (k + 1)/2 + (2 * k - 1 - rows) * rows/2;
}
void solve() {
    long long int k;
    long long int x;
    cin >> k >> x;
    long long int l = 0;
    long long int m;
    long long int r = 2 * k - 1;
    while (l < r) {
        m = (l + r)/2;
        if (emotes(m, k) >= x) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l << "\n";
}
int main() {
    int t;
    cin >> t;
    while (t>0) {
        t--;
        solve();
    }
}