#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100010

int main()
{
    //freopen("INPUT.INP", "rt", stdin);
    long long n, x;
    long long c[MAX];
    long long res = 0;

    cin >> n >> x;
    for (int i = 0; i<n; i++)
    {
        cin >> c[i];
    }

    sort(c, c + n);

    for (int i = 0; i<n; i++)
    {
        if (x>1)
        {
            res = res + c[i] * x;
            x--;
        }
        else
            res = res + c[i];

    }
    cout << res << endl;

    return 0;
}