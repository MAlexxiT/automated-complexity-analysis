//O(N)
//https://codeforces.com/gym/100187/submission/119089080
//https://codeforces.com/gym/100187/problem/L
#include "bits/stdc++.h"

using namespace std;


int main()
{
   

    string cad;
    cin >> cad;

    int N = cad.size();

    for(int i = 0 ; i < N/2 ; i++)
    {
    	if(cad[i] != cad[N-i-1])
    	{
    		cad[i] = cad[N-i-1];
    	}
    }

    cout << cad << '\n';

    return 0;
}