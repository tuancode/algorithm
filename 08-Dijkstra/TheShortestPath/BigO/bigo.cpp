#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 10005
const int INF = 1e9;
vector < vector<pair<int, int> > > graph;
vector<string> listName;
vector<int> dist(MAX, INF);

int getIndex(string name)
{
	for (int i = 0; i < listName.size(); i++)
	{
		if (name == listName[i])
			return i+1;
	}
	return -1;
}

int dijkstra(int source, vector<vector<pair<int, int> > > v, vector<int> distance, int target)
{
	distance = vector<int>(MAX, INF);
	int node, d;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pair<int, int> top, neighbor;
	pq.push(pair<int, int>(0, source));
	distance[source] = 0;
	while (!pq.empty())
	{
		top = pq.top();
		pq.pop();
		node = top.second;
		d = top.first;
		for (int i = 0; i < v[node].size(); i++)
		{
			neighbor = v[node][i];
			if (d + neighbor.second < distance[neighbor.first])
			{
				distance[neighbor.first] = d + neighbor.second;
				pq.push(pair<int, int>(distance[neighbor.first], neighbor.first));
			}
		}
	}
	return distance[target];
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int s, n, p, nr, cost, r, i;
	string NAME, NAME1, NAME2;
	cin >> s;
	while (s--)
	{
		graph = vector<vector<pair<int, int> > >(MAX + 5, vector<pair<int, int> >());
		cin >> n;
		for(int i=1; i<=n; i++)
		{
			cin >> NAME;
			listName.push_back(NAME);
			cin >> p;
			for(int j=0; j<p; j++)
			{
				cin >> nr >> cost;
				graph[i].push_back(pair<int, int>(nr, cost));
			}
		}
		cin >> r;
		while (r--)
		{
			cin >> NAME1 >> NAME2;
			cout << dijkstra(getIndex(NAME1), graph, dist, getIndex(NAME2)) << endl;
		}
		listName.clear();
	}
	return 0;
}
