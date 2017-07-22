#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 1005

int main()
{
    //freopen("INPUT.INP", "rt", stdin);
    long n;
    long a[MAX];

    cin >> n;

    for (int i = 0; i<n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int total_number = 1;
    int high_current = 1;
    int high_tower = 1;
    for (int i = 0; i<n-1; i++)
    {
        if (a[i] != a[i + 1])
        {
            total_number++;
            high_current = 1;
        }

        else
        {
            high_current++;
            if (high_current>high_tower)
                high_tower = high_current;
        }
    }
    cout<<high_tower<<" ";
    cout<<total_number;
    return 0;
}