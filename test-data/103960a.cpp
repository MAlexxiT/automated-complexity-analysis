//O(|s|) /  O(n) 
//https://codeforces.com/gym/103960/submission/236811403
//https://codeforces.com/gym/103960/problem/A
#include "bits/stdc++.h"
using namespace std;

void cursi(){
    
}

void uwo(){
    int n; cin>>n;
    string s;cin>>s;
    
    s+='b';
    int res=0;
    int cont=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            cont++;
        }else{
            if(cont>1){
                res+=cont;
            }
            cont=0;
        }
    }
    cout<<res;
}

int main(){
    int tc=1;
    //cin>>tc;
    while(tc>0){
        tc--;
        uwo();
    }
    return 0;
}