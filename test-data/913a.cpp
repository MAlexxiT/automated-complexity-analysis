//O(log(n))
//https://codeforces.com/contest/913/submission/34011810
//https://codeforces.com/contest/913/problem/A
#include "bits/stdc++.h"
using namespace std;
 
long long int modularExponentiation(long long int x,long long int n)
{
    if(n==0){
        return 1;
    }
    long long int mult;
    if(n%2==0){
        mult = 1;
    }else{
        mult = x;
    }
    
    return (mult*modularExponentiation((x*x),n/2));
}
 
int main()
{
    long long int n;
    long long int m;
    long long int mod;
    cin>>n>>m;
    if(n<30){
        mod =modularExponentiation(2,n);
        cout<<m%mod<<endl;
    }
    else{
        cout<<m<<endl;
    }
    return 0;
}