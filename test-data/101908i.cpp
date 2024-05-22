//O(n*m + l)
//https://codeforces.com/gym/101908/submission/70164963
//https://codeforces.com/gym/101908/problem/I
#include "bits/stdc++.h"
using namespace std;
int main()
{
	int m;
    int n;
    int l;
    int sum = 0;
    int counter = 0;
    int koniec = 0;
    cin>>n>>m>>l;
	int lights[m+1];
    int switches[n][m+1];
	for(int i = 0; i < m; i++){
        lights[i] = 0;
    }
		
	int pom;
	for(int i = 1; i <= l; i++)
	{
		cin>>pom;
		lights[pom] = 1;
		sum++;
	} 
	int k;
    int p;
	for(int i = 0; i < n; i++)
	{   
        //a lo sumo m
		cin>>k;
		switches[i][0] = k;
		for(int j = 1; j <= k; j++)
		{
			cin>>switches[i][j];
		}
	}
	for(int i = 0; i < n*2; i++)
	{
		int a = i %n;
		if(sum == 0)
		{
			koniec = 1;
			break;
		}
		k = switches[a][0];
		for(int j = 1; j <= k; j++)
		{
			p = switches[a][j];
			if(lights[p] == 1)
			{
				lights[p] = 0;
				sum--;
			}
			else
			{
				lights[p] = 1;
				sum++;
			}
		}
		counter++;
	}
	if(koniec == 1){
        cout<<counter;
    }else{
        cout<<"-1"<<endl;
    }
}