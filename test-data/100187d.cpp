//O(log(n))
//https://codeforces.com/gym/100187/submission/241505831
//https://codeforces.com/gym/100187/problem/D
#include "bits/stdc++.h"
using namespace std;
long long int binpow(long long int b, long long int e,long long int inf) {
    long long int res = 1;
    if(e == 0){
        return 1;
    } 
    res = binpow(b,e/2,inf);
    res*=res;
    res%=inf;
    if(e%2==1){
        res *= b;
    } 
    res%=inf;
    return res;
}
//--------------------SOLBEGIN---------------------------------
int main() {
	long long int inf = 1000000009;
    long long int n; cin>>n;
	
    long long int res = 0;
    res =binpow(3,n,inf)-binpow(2,n+1,inf)+1;
    res%=inf;
    res+=inf;
    res%=inf;
    cout<<res<<endl;
}
//--------------------EOSOLUTION---------------------------------