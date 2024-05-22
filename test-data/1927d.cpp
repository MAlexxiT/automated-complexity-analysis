//O(tc*(n+Q))
//https://codeforces.com/contest/1927/submission/245120041
//https://codeforces.com/contest/1927/problem/D
#include "bits/stdc++.h"
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  } 
  int prv[n];

  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) {
      prv[i] = i - 1;
    } else {
      prv[i] = prv[i - 1];
    }
  }

  int Q;
  cin >> Q;
  int l;
  int r;
  for (int q = 0; q < Q; q++) {
    cin >> l >> r;
    l--; r--;
    if (prv[r] >= l) {
      cout << prv[r] + 1 << " " << r + 1 << endl;
    } else {
      cout << 0-1 << " " << 0-1 << endl;
    }
  }
  cout << "\n";
}

int main() {
  int tc;
  cin >> tc;
  while (tc>0) { tc--;solve(); }
}