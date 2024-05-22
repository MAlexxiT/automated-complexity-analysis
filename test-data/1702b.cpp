//O(ut*s)
//https://codeforces.com/contest/1702/submission/163661987
//https://codeforces.com/contest/1702/problem/B
#include "bits/stdc++.h"
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();ans++)
    {
        set<char>used;
        while(used.size()<=3)
        {
            used.insert(s[i++]);
        }
        i--;
    }
    cout<<ans<<endl;
}
int main()
{
    int ut=1;
    cin>>ut;
    while(ut>0){
		ut--;
		solve();
	}
}
