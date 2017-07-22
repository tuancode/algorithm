#include <iostream>
#include <string>
#include <vector>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() 
{
    //freopen("INPUT.INP","rt",stdin);
    faster;
    string wheel;
    char ch = 'a';
    cin>>wheel;
    int count = 0;
    int m = 0;
    for(int i=0; i<wheel.size(); i++)
    {
        m = abs(ch-wheel[i]);
        if(m<13)
            count = count + m;
        else
            count = count + 26 - m;
        ch = wheel[i];
    }
    cout<<count<<endl;
    return 0;
}