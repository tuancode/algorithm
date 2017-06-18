#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	//freopen("INPUT.INP","rt",stdin);
	string s;
	string t;
	string res;
    cin>>s>>t;
    res=s;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(res[i]=='z')
            res[i]-=25;
        else
        {
            res[i]++;
            break;
        }
    }
	int flag = 0;
    for(int i=0;i<s.size();i++)
    {
        if(res[i]<t[i])
        {
            flag = 1;
            break;
        }
        if(res[i]>t[i])
        {
            flag = 0;
            break;
        }
    }
	if(flag == 0)
		cout<<"No such string"<<endl;
	else
		cout<<res<<endl;
   return 0;
}