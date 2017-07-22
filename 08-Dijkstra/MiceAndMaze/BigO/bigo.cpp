#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define MAX 100

const int INF = 1e9;
vector<vector<pair<int, int> > > graph;
vector<int> dist(MAX, INF);
int path[MAX];

void Dijkstra(int source, vector<vector<pair<int, int>>> &v, vector<int> &distance)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

	pq.push(pair<int, int>(0, source));

	distance[source] = 0;
	while (!pq.empty())
	{
		pair<int, int> top = pq.top();
		pq.pop();
		int node = top.second;
		int d = top.first;
		for (int i = 0; i<v[node].size(); ++i)
		{
			pair<int, int> neighbor = v[node][i];
			if (d + neighbor.second < distance[neighbor.first])
			{
				distance[neighbor.first] = d + neighbor.second;
				pq.push(pair<int, int>(distance[neighbor.first], neighbor.first));
				path[neighbor.first] = node;
			}
		}
	}
}



int main()
{
	//freopen("INPUT.INP", "rt", stdin);
	int N, E, T, M;
	int a, b, temp;
	dist = vector<int>(MAX, INF);
	graph = vector<vector<pair<int, int> > >(MAX + 1, vector<pair<int, int>>());

	scanf("%d", &N);
	scanf("%d", &E);
	scanf("%d", &T);
	scanf("%d", &M);

	for (int i = 0; i<M; i++)
	{
		scanf("%d%d", &a, &b);
		scanf("%d", &temp);
		graph[b-1].push_back(pair<int, int>(a-1, temp));
	}
	Dijkstra(E-1, graph, dist);
	int count = 0;
	for (int i = 0; i<N; i++)
	{	
		if (dist[i] <= T)
			count++;
	}
	printf("%d", count);

	return 0;
}
