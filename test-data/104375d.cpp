//O((n+q)*logn)
//https://codeforces.com/gym/104375/submission/227734580
//https://codeforces.com/gym/104375/problem/D
#include "bits/stdc++.h"
using namespace std;

int main(){
	int n;
    int q;
    int e;
    int x;
    int y;
	cin>>n>>q;
	vector<int> a;
    for(int i = 0; i<n; i++){
        cin>>e;
        a.push_back(e);
    }
	sort(a.begin(),a.end());
	//forn(i,n)ce(a[i],i,n);
	for(int i = 0; i<q; i++){
		cin>>e;
		if(e==1){
			cin>>x;
			int j=lower_bound(a.begin(),a.end(),x)-a.begin();
			if(j<a.size()&&a[j]==x){
                continue;
            }
			else{
                if(a.back()<x){
                    a.push_back(x);
                }else{
                    int jj=upper_bound(a.begin(),a.end(),x)-a.begin();
                    a[jj]=x;
                }
            }
		}
		else{
			cin>>x>>y;
			int j=lower_bound(a.begin(),a.end(),x)-a.begin();
			int k=upper_bound(a.begin(),a.end(),y)-a.begin();
			k--;
			cout<<k-j+1<<endl;
		}
	}
}