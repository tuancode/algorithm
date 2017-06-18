#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string Convert(string x)
{
    string y = "";
    for(int i=0; i<x.length(); i++)
    {
        if( (x[i]>='a' && x[i]<='z')||(x[i]>='A' && x[i]<='Z' ))
            y += tolower(x[i]);
    }
    return y;
}

int main()
{
    //freopen("INPUT.INP", "rt", stdin);
    string x, y, z;
    cin>>x>>y>>z;
    x = Convert(x);
    y = Convert(y);
    z = Convert(z);
    int n;
    cin>>n;
    string xyz = x + y + z, xzy = x + z + y;
    string yzx = y + z + x, yxz = y + x + z;
    string zxy = z + x + y, zyx = z + y + x;
    for(int i=0; i<n; i++)
    {
        string q;
        cin>>q;
        q = Convert(q);
        if(q==xyz || q==xzy || q==zxy || q==zyx || q==yxz || q==yzx)
            cout<<"ACC"<<endl;
        else
            cout<<"WA"<<endl;
    }
    return 0;
}