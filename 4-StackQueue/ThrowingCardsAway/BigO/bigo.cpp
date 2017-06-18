#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

int main()
{
    // freopen("INPUT.INP","r",stdin);
    //freopen("OUTPUT.TXT","w",stdout);
    queue <int> q;
    int n = 1;
    while (n != 0)
    {
        cin >> n;
        if (n == 0)
            return 0;
        // bỏ toàn bộ lá bài vào trong queue
        for (int i = 1; i <= n; i++)
            q.push(i);

        cout << "Discarded cards:";
        while (q.size()>2)
        {
            cout << " " << q.front() << ",";
            q.pop();
            int k = q.front();
            q.pop();
            q.push(k);
        }
        if (q.size() == 1)
        {
            cout << endl << "Remaining card: " << q.front() << endl;
            q.pop();
            continue;
        }
        cout << " " << q.front();
        q.pop();
        cout << endl << "Remaining card: " << q.front() << endl;
        q.pop();
    }
    return 0;
}