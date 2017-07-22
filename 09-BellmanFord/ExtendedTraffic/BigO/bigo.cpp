#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <functional>
using namespace std;
#define MAX 205
#define INF 1000000000

struct triad
{
    int source;
	int target;
	int weight;
};

vector<int> dist(MAX, INF);
vector<triad> graph((MAX*MAX)/2);

int n, m;
int path[MAX];

void BellmanFord(int source, vector<triad> &graph, vector<int> &dist)
{
    int u, v, w;
	dist[source] = 0;
    for (int i = 1; i <= n-1; i++)
    {
        for (int j = 0; j < m; j++)
        {
			u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
				dist[v] = dist[u] + w;
				path[v] = u;
			}
        }
    }
    return;
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	freopen("OUTPUT.INP", "wt", stdout);
	int T, u, v, w, q, t, count = 1;
	scanf("%d", &T);
	while(T--)
	{
		dist = vector<int>(MAX, INF);
		graph = vector<triad>((MAX*MAX)/2);
		vector<int> weight;
		scanf("%d", &n);
		weight.push_back(0);
		for(int i=0; i<n; i++)
		{
			scanf("%d", &w);
			weight.push_back(w);
		}
		scanf("%d", &m);
		for(int i=0; i<m; i++)
		{
			scanf("%d %d", &u, &v);
			graph[i].source = u;
			graph[i].target = v;
			graph[i].weight = pow((weight[v] - weight[u]), 3);
		}
		BellmanFord(1, graph, dist);
		scanf("%d", &q);
		printf("Case %d:\n", count);
		for(int i=0; i<q; i++)
		{
			scanf("%d", &t);
			int res = dist[t];
			if(res!=INF && res>=3)
			{
				printf("%d\n", res);
			}
			else
			{
				printf("?\n");
			}
		}
		count++;
	}
	return 0;
}
