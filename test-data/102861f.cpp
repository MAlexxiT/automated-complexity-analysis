//O(n)
//https://codeforces.com/gym/102861/submission/117751827
//https://codeforces.com/gym/102861/problem/F
#include "bits/stdc++.h"
using namespace std;

int main(){
	int t = 1;
	// cin>>t;

	while(t>0){
        t--;
		string s;
		cin>>s;
		bool service = false; //false = left
		int gl = 0;
        int pl = 0;
        int gr = 0;
        int pr = 0;
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'S')
			{
				if (service == true)
				{
					pr++;
				}
				else{
					pl++;
				}
			}
			else{
                if (s[i] == 'R')
                {
                    if (service == true)
                    {
                        pl++;
                        service = false;
                    }
                    else{
                        pr++;
                        service = true;
                    }
                }
                else{
                    if (gr == 2 || gl == 2)
                    {
                        if (gr == 2)
                        {
                            cout<<gl<<" - "<<gr<<" (winner)"<<endl<<endl;
                            
                            //cout<<endl;
                        }
                        else{
                            cout<<gl<<" (winner) - "<<gr<<endl<<endl;
                            
                            //cout<<endl;
                        }
                    }
                    else{
                        if (service == true)
                        {
                            cout<<gl<<" ("<<pl<<") - "<<gr<<" ("<<pr<<"*)"<<endl;
                            
                        }
                        else{
                            cout<<gl<<" ("<<pl<<"*) - "<<gr<<" ("<<pr<<")"<<endl;
                           
                        }
                    }
                }
            }
			if (pr == 10)
			{
				gr++;
				pr = 0;
				pl = 0;
			}
			else{
                if (pl == 10)
                {
                    gl++;
                    pr = 0;
                    pl = 0;
                }else{
                    if (pl >= 5 && (pl - pr) >= 2)
                    {
                        gl++;
                        pr = 0;
                        pl = 0;
                    }
                    else{
                        if (pr >= 5 && (pr - pl) >= 2)
                        {
                            gr++;
                            pr = 0;
                            pl = 0;
                        }
                    } 
                } 
            } 
			
		}
	}
	return 0;
}