//O(nTest*n^2)
//https://codeforces.com/contest/1450/submission/100530405
//https://codeforces.com/contest/1450/problem/B
#include "bits/stdc++.h"
using namespace std;

int abs(int n){
    if(n<0){
        return 0-n;
    }else{
        return n;
    }
}
int main() {
	int nTest; cin >> nTest;
	while (nTest>0) {
		int n;
        int k; cin >> n >> k;
        int x[n];
        int y[n];
		for (int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
        }
			
		int ans = 0-1;
		for (int i = 0; i < n; i++) {
			bool wrong = false;
			for (int j = 0; j < n; j++){
                if ((abs(x[i] - x[j]) + abs(y[i] - y[j])) > k){
                    wrong = true;
                }
            }
				
			if (wrong==false){
                ans = 1;
            } 
		}
		cout << ans << endl;
	}
	return 0;
}