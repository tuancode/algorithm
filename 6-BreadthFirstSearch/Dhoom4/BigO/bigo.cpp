#include<iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100005
int n;
int path[MAX];
vector<int> a;

int BFS(int s, int d)
{
    queue<int> q;
    q.push(s);
    path[s] = 0;
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        if (s == d)
            break;
        for (int i = 0; i<n; i++) 
        {
            long long value = (1LL*a[i]*s);
            value %= 100000;
            if (path[value] == -1)
            {
                path[value] = path[s] + 1;
                q.push(value);
            }
        }
    }
    return path[d];
}

int main()
{
    //freopen("INPUT.INP", "rt", stdin);
    int s, d, temp;
    cin >> s >> d;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    memset(path, -1, sizeof(path));

    int ans = BFS(s, d);

    printf("%d\n", ans);

    return 0;
}