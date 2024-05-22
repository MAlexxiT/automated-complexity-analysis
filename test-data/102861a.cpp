//O(n+l)
//https://codeforces.com/gym/102861/submission/122399379
//https://codeforces.com/gym/102861/problem/A
#include "bits/stdc++.h"

using namespace std;

int main() {
	int N = 1000007;  
    int n;
    int l;
    int r;
    double dp[N];
    double pre[N]; 
    cin>>n>>l>>r;
	dp[0] = 1; pre[0] = 1;
	if(l == 0){
		for(int i = 1 ; i <= n ; i++){
			dp[i] = (pre[max(0,i - l - 1)] - pre[max(0, i - r - 1)] + r - l + 1) / (r - l) ;
			pre[i] = pre[i - 1] + dp[i];
		}
	}
	else{
		for(int i = 1 ; i <= l ; i++){
            dp[i] = 1;
            pre[i] = pre[i - 1] + dp[i];
        }   
		for(int i = l + 1 ; i <= n ; i++){
			dp[i] = (pre[i - l] - pre[max(0, i - r - 1)]) / ( r - l + 1 ) + 1;
			pre[i] = pre[i - 1] + dp[i];
		}
	}
	cout<<dp[n]<<endl;
    return 0;
}