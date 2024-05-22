//O(N^2*K)
//https://codeforces.com/gym/105164/submission/260982041
//https://codeforces.com/gym/105164/problem/J
#include "bits/stdc++.h"
using namespace std;
 
int main(){
    int N;
    int K;
    cin >> N >> K;
    string s;
    cin >> s;
    int prev[N][N];
    int dp[N][N];
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            dp[N][N] = 1000000000;
        }
    }
    int sol = 1000000000;
    for(int k = 2 + K % 2; k <= K; k += 2){
        for(int i = k - 1; i < N; i++){
            for(int j = i; j < N; j++){
                dp[j - i][j] = min(dp[j - i][j - 1], dp[j - i + 1][j]);
                int d = 0;
                if(s[j - i] != s[j]){
                    d = 1;
                }
                dp[j - i][j] = min(dp[j - i][j], prev[j - i + 1][j - 1] + d);
                //cout << k << " " << j - i << " " << j << " " << dp[j - i][j] << "\n";
            }
        }
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                prev[i][j] = dp[i][j];
                dp[i][j] = 1000000000;
            }
        }
    }
    cout << prev[0][N - 1] << "\n";
}
