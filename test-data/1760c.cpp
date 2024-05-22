//O(T*(n^2+200^2))
//https://codeforces.com/contest/1770/submission/187264527
//https://codeforces.com/contest/1770/problem/C
#include "bits/stdc++.h"
using namespace std;

int main()
{
	int a[1000005]; 
	int T;
	cin >> T;
	while(T>0)
	{
        T--;
		int n;
        int m;
		cin >> n;
		int nw=1;
        int p=m;
		for(int i=1;i<=n;i++){
            cin >> a[i];
        } 
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++){
                if(a[i]==a[j]){
                    flag=0;
                } 
            }
				
		}
		for(int p=2;p<=200;p++)
		{
			int cnt[205];
			for(int j=1;j<=n;j++){
                cnt[a[j]%p]++;
            }
				
			int x=0;
			for(int t=0;t<p;t++){
                if(cnt[t]<2){
                    x=1;
                }
            }
				
			if(x==0){
                flag=0;
            } 
		}
		if(flag==true){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
	}
	return 0;
}