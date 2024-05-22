//O(1)
//https://codeforces.com/gym/104375/submission/220152662
//https://codeforces.com/gym/104375/problem/B
#include "bits/stdc++.h"
using namespace std;

int main(){
    long long int N;
    long long int K;
    long long int L;
    cin>>N>>K>>L;

    long long int ans = (N*K) / L;
    if((N*K)%L != 0){
        ans++;
    } 
    cout << ans << '\n';
}