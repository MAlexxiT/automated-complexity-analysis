//O(T*n)
//https://codeforces.com/contest/1909/submission/238507886
//https://codeforces.com/contest/1909/problem/A
#include "bits/stdc++.h"
using namespace std;
//  In the Name of ALLAH, the most gracious, the most merciful 
void solve() {
    int n;
    cin >> n;
    set<char> st;
    while (n>0) {
        n--;
        int x;
        int y;
        cin >> x >> y;
        if (x > 0){
            st.insert('R');
        }else{
            if (x < 0){
                st.insert('L');
            } 
        }
        if (y > 0){
            st.insert('U');
        } else{
            if (y < 0){
                st.insert('D');
            } 
        }   
    }
    if(st.size()==4){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }

}

int main() {

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}