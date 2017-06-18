#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
using namespace std;

struct Point
{
    int x, y;
    Point(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    };
};

int t, m, n;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
#define MAX 22
char maze[MAX][MAX];
bool visited[MAX][MAX];

bool bfs(Point s, Point f)
{
    queue<Point> q;
    q.push(s);
    int x, y;
    Point u;
    visited[s.x][s.y] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int i = 0; i<4; i++)
        {
            x = u.x + dx[i];
            y = u.y + dy[i];
            if (x >= 0 && x<m && y >= 0 && y<n)
            {
                if (!visited[x][y] && maze[x][y] == '.')
                {
                    visited[x][y] = 1;
                    if (x == f.x && y == f.y)
                        return true;
                    q.push(Point(x, y));
                }
            }
        }
    }
    return false;
}

int main()
{
    //freopen("INPUT.INP", "rt", stdin);
    vector<Point> points;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &m, &n);
        points.clear();
        for (int i = 0; i<m; i++)
        {
            for (int j = 0; j<n; j++)
            {
                scanf("\n%c", &maze[i][j]);
                if (maze[i][j] == '.' && (i == 0 || i == (m - 1) || j == 0 || j == (n - 1)))
                {
                    points.push_back(Point(i, j));
                }
                visited[i][j] = 0;
            }
        }
        if (points.size() == 2)
        {
            if (bfs(points[0], points[1]) == true)
                printf("valid\n");
            else
                printf("invalid\n");
        }
        else
            printf("invalid\n");
    }

    return 0;
}