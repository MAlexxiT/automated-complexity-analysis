//O(t*n)
//https://codeforces.com/contest/1472/submission/103569662
//https://codeforces.com/contest/1472/problem/B
#include "bits/stdc++.h"

using namespace std;

void solve() {
  int n;
  cin >> n;
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    if (c == 1) {
      cnt1++;
    } else {
      cnt2++;
    }
  }
  if ((cnt1 + 2 * cnt2) % 2 != 0) {
    cout << "NO\n";
  } else {
    int sum = (cnt1 + 2 * cnt2) / 2;
    if (sum % 2 == 0 || sum % 2 == 1 && cnt1 != 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t>0) {
    t--;
    solve();
  }
  return 0;
  
  
}