#include <stdio.h> 
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 100001

bool option(int a, int b)
{
    return (a>b);
}

int main()
{
    //freopen("INPUT.INP", "rt", stdin);
    long h[MAX];
    int n, a, b;
    
    cin >> n >> a >> b;
    for (int i = 0; i<n; i++)
    {
        cin >> h[i];
    }

    sort(h, h + n, option);

    int x = h[a - 1] - h[a];
    if (x > 0)
        cout << x;
    else
        cout << "0";

    return 0;
}