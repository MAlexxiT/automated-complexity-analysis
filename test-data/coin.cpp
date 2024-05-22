//O(n*target)
//https://cses.fi/problemset/task/1636
//Solucion por CF: icecuber

#include "bits/stdc++.h"
using namespace std;

int main() {
  int mod = 1000000007;
  int n;
  int target;
  cin >> n >> target;
  int x[n];
  for (int i = 0; i<n; i++){
    cin>>x[i];
  }

  int dp[n+1][target+1];

  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-x[i-1];
      if (left >= 0) {
	    dp[i][j] += dp[i][left];
	    dp[i][j] = dp[i][j]%mod;
      }
    }
  }
  cout << dp[n][target] << endl;
}