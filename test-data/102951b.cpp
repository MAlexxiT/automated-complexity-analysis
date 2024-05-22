//O(algoritmos*log(algoritmos))
//https://codeforces.com/gym/102951/submission/231602843
//https://codeforces.com/gym/102951/problem/B

#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    int a;
    vector<int> algoritmos;
    long long int x;
    cin >> n >> x;
    while (n>0) {
        n--;
        cin >> a; 
        algoritmos.push_back(a);
    }
    sort(algoritmos.begin(), algoritmos.end());

    int sum = 0;
    int alg = 0;
    for (int i = 0; i < algoritmos.size(); i++) {
        if (sum + algoritmos[i] <= x) {
            alg++; 
            sum = sum + algoritmos[i];
        }else {
            break;
        }
    }
    cout << alg;
    return;
}

int main() {

    solve();
    
    return 0;
}