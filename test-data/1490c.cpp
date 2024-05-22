//O(10^4*log(10^4) + t*x^0.333)
//https://codeforces.com/contest/1490/submission/107558542
//https://codeforces.com/contest/1490/problem/C
#include "bits/stdc++.h"
using namespace std;
 
int main () {
	set<long long int> is_cube;
	for(long long int a = 1; a * a * a <= 1000000000000; a++){
        is_cube.insert(a * a * a);
    }
	int t = 1;
	cin >> t;
	while(t>0){
        t--;
		long long int x;
		cin >> x;
		bool flg = false;
		for(long long int a = 1; (a * a * a) < x; a++){
			long long int b = x - a * a * a;
			if(is_cube.count(b)>0){
				flg = true;
				break;
			}
		}
        if(flg==true){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
	}
	return 0;
}