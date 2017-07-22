#include <sstream>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    //freopen("INPUT.INP", "rt", stdin);
    int car, n, flag = 0, street = 1;
    stack <int> track;

    while (1)
    {
        cin >> n;
        if (n == 0)
            return 0;
        street = 1;
        flag = 0;
        while (!track.empty())
        {
            track.pop();
        }
        track.push(1001);
        for (int i = 0; i<n; i++)
        {
            cin >> car;
            // Nếu còn xe
            if (car != 0)
            {
                if (car == street)
                    street++;
                else
                {
                    while (street == track.top())
                    {
                        street++;
                        track.pop();
                    }

                    if (car > track.top())
                    {
                        flag = 1;
                    }
                    else
                        track.push(car);
                }
            }
        }
        if (flag == 0)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}