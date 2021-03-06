#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define MAX 505

const int INF = 1e9;
vector<vector<pair<int, int> > > graph;
vector<int> dist(MAX, INF);
int path[MAX];

void Dijkstra(int source, vector<vector<pair<int, int> > > &v, vector<int> &distance)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

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
	int N;
	dist = vector<int>(MAX, INF);
	cin >> N;
	graph = vector<vector<pair<int, int> > >(MAX + 10, vector<pair<int, int> >());
	int A, B, W;
	for (int i = 0; i<N; i++)
	{
		cin >> A >> B >> W;
		graph[A].push_back(pair<int, int>(B, W));
		graph[B].push_back(pair<int, int>(A, W));
	}
	int U;
	cin >> U;
	Dijkstra(U, graph, dist);

	int Q, V;
	cin >> Q;
	int ans = 0;
	for (int i = 0; i < Q; i++)
	{
		cin >> V;
		ans = dist[V];
		if (ans != INF)
			cout << ans << endl;
		else
			cout << "NO PATH"<<endl;
	}
	return 0;
}
