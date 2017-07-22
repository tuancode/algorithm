#include <sstream>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define max 1100

int main()
{
    //freopen("INPUT.INP", "rt", stdin);
    int Test = 0;
    cin>>Test;
    char Expression[max];
    while(Test--)
    {
        cin>>Expression;
        stack<char> s;
        for(int i=0; i<strlen(Expression); i++)
        {
            if(isalpha(Expression[i]))
            {
                printf("%c", Expression[i]);
            }
            else if(Expression[i]==')')
            {
                cout<<s.top();
                s.pop();
            }
            else if(Expression[i] != '(')
            {
                s.push(Expression[i]);
            }
        }
        cout<<endl;
    }
    return 0;
}