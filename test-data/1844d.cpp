//O(t*n)
//https://codeforces.com/contest/1844/submission/213338119
//https://codeforces.com/contest/1844/problem/D
#include"bits/stdc++.h"
using namespace std;
/*
K.D. Vinit  /,,/
*/

void solve()
{
    int n;
    cin>>n;

    int j=1;
    while(j<n && n%j==0){
        j++;
    } 

    for(int i=0; i<n; i++)
    {
        int ii = i%j;
        char x = 'a'+ii;
        cout<<x;
    }
    cout<<"\n";
}

int main()
{

    int t; cin>>t;
    while(t>0){
        solve();
        t--;
    } 
    return 0;
}