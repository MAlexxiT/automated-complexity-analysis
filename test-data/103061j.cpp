//O(n)
//https://codeforces.com/gym/103061/submission/136377827
//https://codeforces.com/gym/103061/problem/J
#include"bits/stdc++.h"
using namespace std;

int main()
{
    int mod= 998244353;
    
    int n;
    cin>>n;
    long long int f[n][3];
    f[0][0]=1;
    for(int i=2;i<=n;i++)
    {
        f[i][0]=(f[i-1][1]+f[i-1][2])%mod;
        f[i][1]=(f[i-2][0]+f[i-2][1])%mod;
        f[i][2]=(f[i-2][0]+f[i-2][2])%mod;
    }
    cout<<f[n][1]<<endl;
    return 0;
}