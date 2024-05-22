//O(sqrt(n)*(log(n)+log(|res|)))
//https://codeforces.com/gym/104736/submission/229509316
//https://codeforces.com/gym/104736/problem/F

#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
bool convertir(long long int n, long long int b){
    if(b*b>n){
        return n/b == n%b;
    }
    vector<long long int> res;

    while(n>0){res.push_back(n%b); n/=b;}
    int t = res.size();
    for(int i = 0; i<t; i++){
        if(res[i]!=res[t-1-i]){
            return false;
        } 
    }
    return true;
}
//--------------------SOLBEGIN---------------------------------
int main() {

	long long int n; cin>>n;
    if(n==2){
        cout<<"*"<<endl;
        return 0;
    }
    
    set<long long int> res; res.insert(n-1);
    long long int alt;
    
    for(long long int curr = 2; curr*curr<=n; curr++){
        if((convertir(n,curr))>0){
            res.insert(curr);
        } 
    }
    for(long long int curr = 2; curr*curr<=n; curr++){
        if(n%curr != 0){
            continue;
        }
        alt = n/curr;
        if(alt==2){
            continue; 
        }
        if((convertir(n,alt-1))>0){
            res.insert(alt-1);
        } 
    }
    
    bool shit = true;
    return 0;
}
//--------------------EOSOLUTION---------------------------------