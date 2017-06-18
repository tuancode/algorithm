#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <functional>
using namespace std;

int main()
{
    //freopen("INPUT.INP", "rt", stdin);
    long long p, c, x;
    string s;
    long long count = 1;
    while(true)
    {
        queue<long long> q;
        cin>>p>>c;
        //scanf("%lld %lld", &p, &c);
        if(p==0 && c==0)
            break;
        if(p<=c)
        {
            for(long long i=1; i<=p; i++)
            {
                q.push(i);
            }
        }
        else
        {
            for(long long i=1; i<=c; i++)
            {
                q.push(i);
            }
        }
        cout<<"Case "<<count++<<":"<<endl;
        //printf("Case %lld:\n", count++);
        for(long long i=0; i<c; i++)
        {
            cin>>s;
            if(s=="N")
            {
                long long temp = q.front();
                cout<<temp<<endl;
                //printf("%lld\n", temp);
                q.pop();
                q.push(temp);
            }
            else
            {
                cin>>x;
                queue<long long> temp;
                temp.push(x);
                long long n = q.size();
                for(long long j=0; j<n; j++)
                {
                    long long k = q.front();
                    if(x==k)
                        q.pop();
                    else
                    {
                        temp.push(q.front());
                        q.pop();
                    }
                }
                swap(temp, q);
            }
        }
    }
    return 0;
}