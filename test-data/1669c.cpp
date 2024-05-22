//O(t*n^2)
//https://codeforces.com/contest/1669/submission/156366095
//https://codeforces.com/contest/1669/problem/C
#include "iostream"
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        int a[n];
        for(int j=0;j<n;j++){
            cin >> a[j];
        }
        for (int j = 0; j <= n; j++){
            int cond=0;
            for(int k=0;k<n;k++){
                if(a[k]%2==0){
                    cond++;
                }
            }
            if(cond==n || cond==0){
                cout << "YES \n";
                break; 
            } 
            if(j==n){
                cout << "NO \n";
                break;
            }
            if(j%2!=0){
                for(int k=0;k<n;k+=2){
                    a[k]++;
                }
            }
            if(j%2==0){
                for(int k=1;k<n;k+=2){
                    a[k]++;
                }
            }
           
        }
    }
    

    return 0;
}