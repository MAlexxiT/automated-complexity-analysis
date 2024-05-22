//O(t*400*log(ans))
//https://codeforces.com/contest/1933/submission/250005548
//https://codeforces.com/contest/1933/problem/C
#include "bits/stdc++.h"
using namespace std;

int main(){
	int t; 
    cin>>t;
	
    while(t>0){
		t--;
        long long int a;
        long long int b;
        long long int l; 
        
        cin>>a>>b>>l;
		
		long long int p=1;
		set<long long int> ans;
		
		for(int i = 0; i<20; i++){
			long long int q=1;
			for(int j = 0; j<20; j++){
                long long int modulo = l%(p*q);
				if(modulo==0){
                    ans.insert(l/(p*q));
                } 
				q*=b;
				if(q>l){
                    break;
                }
			}
			p*=a;
			if(p>l){
                break;
            }
		}
		
		cout<<ans.size()<<"\n";
	}
    
}