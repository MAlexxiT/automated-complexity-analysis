//O(t)
//https://codeforces.com/gym/101502/submission/204369140
//https://codeforces.com/gym/101502/problem/A

#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t = 1; cin>>t;
    while(t>0){
        t--;
        long long int y;
        long long int x; cin>>y>>x;

        y*= 100;

        x+=100;


        long long int ans = y / x;

        cout<<ans<<"\n";
    }
}