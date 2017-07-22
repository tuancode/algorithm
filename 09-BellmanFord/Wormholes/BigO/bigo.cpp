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
#define MAX 1005
const int INF = 0x3f3f3f3f;

struct triad
{
    int source;
	int target;
	int weight;

};

vector<int> dist(MAX, INF);
vector<triad> graph(MAX*2);
int n, m;

bool BellmanFord(int source, vector<triad> &graph, vector<int> &dist)
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
                dist[v] = dist[u] + w;
        }
    }

	for (int i = 0; i < m; i++)
    {
        u = graph[i].source;
        v = graph[i].target;
        w = graph[i].weight;
        if (dist[u] != INF && dist[u] + w < dist[v])
            return false;
    }

    return true;
}

int main()
{
	//freopen("INPUT.INP", "rt", stdin);
	int T, u, v, w;
	scanf("%d", &T);
	while(T--)
	{
		dist = vector<int>(MAX, INF);
		graph = vector<triad>(MAX*2);
		scanf("%d %d", &n, &m);
		for(int i=0; i<m; i++)
		{
			scanf("%d %d %d",&u, &v, &w);
			graph[i].source = u;
			graph[i].target = v;
			graph[i].weight = w;
		}
		if(BellmanFord(0, graph, dist)==false)
		{
			printf("possible\n");
		}
		else
		{
			printf("not possible\n");
		}
	}
	return 0;
}
