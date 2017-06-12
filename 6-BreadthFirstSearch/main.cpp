#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100

int node, edge;
vector<int> graph[MAX];
int path[MAX];
bool visited[MAX];

void breathFirstSearch(int startNode) {
	for (int i = 0; i < node; i++) {
		// init path and visited elements
		visited[i] = false;
		path[i] = -1;
	}
	
	queue<int> queue;
	visited[startNode] = true;
	queue.push(startNode);
	vector<int>::iterator i;
	
	while(!queue.empty()) {
		startNode = queue.front();
		queue.pop();
		for (i = graph[startNode].begin(); i != graph[startNode].end(); i++) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push(*i);
				path[*i] = startNode;
			}
		}
	}
}

void printPath(int startNode, int targetNode, int path[]) {
	if (startNode == targetNode) {
		cout << targetNode << " ";
	} else {
		if (path[targetNode] == -1) {
			cout << "Khong co duong di\n";
		} else {
			printPath(startNode, path[targetNode], path);
			cout << targetNode << " ";
		}
	}
}

int main() {
	freopen("input.inp", "rt", stdin);
	int n, e;
	int startNode = 0, targetNode = 5;
	
	cin >> node >> edge;
	
	for (int i = 0; i < edge; i++) {
		cin >> n >> e;
		graph[n].push_back(e);
		graph[e].push_back(n);
	}
	
	breathFirstSearch(startNode);
	printPath(startNode, targetNode, path);
	return 0;
}