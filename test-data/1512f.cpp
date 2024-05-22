//O(tt*n)
//https://codeforces.com/contest/1512/submission/113669103
//https://codeforces.com/contest/1512/problem/F
#include "bits/stdc++.h"

using namespace std;


void solve(){
    int inf = 1000000000;
	int n;
    int c;
	cin>> n>> c;
    int a[n];
    int b[n];
    int ans[n];
	for(int i = 1; i <= n; i++){
		cin>> a[i];
	}
	for(int i = 1; i < n; i++){
		cin>> b[i];
	}
	int x = 0;
    int y = 0;
    int  answer = inf;
    int d = 0;
	for(int i = 1; i <= n; i++){
        d = 0;
        if((c - x) % a[i] != 0){
            d++;
        }
		ans[i] = (c - x) / a[i] + d + y;
		answer = min(answer, ans[i]);
		if(i == n){
			cout<< answer<< endl;
			return;
		}
		int q = b[i];
		b[i] = max(0, q - x);
		x = max(0, x - q);
        d = 0;
        if(b[i] % a[i] != 0){
            d++;
        }
		y += b[i] / a[i] + d + 1;
        d = 0;
        if(b[i] % a[i] != 0){
            d++;
        }
		x = (a[i] * (b[i] / a[i] + d)) - b[i] + x;
	}
}

int main(){
	int tt;
	cin>> tt;
	while(tt>0){
        tt--;
		solve();
	}
}