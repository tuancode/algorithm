#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    //freopen("INPUT.INP", "rt", stdin);
    int n = 0, l = -1, r = -1, temp = 0;
    vector<int> a;
    vector<int> b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    b = a;
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i] && l == -1)
        {
            l = i;
        }
        if (a[i] != b[i])
        {
            r = i;
        }
    }
    if (l == -1 && r == -1)
    {
        l = r = 0;
    }

    for (int u = l, v = r; u<v; u++, v--)
    {
        swap(a[u], a[v]);
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << "no";
            return 0;
        }
    }

    cout << "yes" << endl;
    cout << l+1 << " " << r+1;

    return 0;
}