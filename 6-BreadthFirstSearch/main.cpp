#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100

int node, edge;
vector<int> graph[MAX];
int back[MAX];
bool visited[MAX];

void breathFirstSearch(int startNode) {
	for (int i = 0; i < node; i++) {
		// init back and visited elements
		visited[i] = false;
		back[i] = -1;
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
				back[*i] = startNode;
			}
		}
	}
}

void printPath(int startNode, int targetNode, int back[]) {
	if (startNode == targetNode) {
		cout << targetNode << " ";
	} else {
		if (back[targetNode] == -1) {
			cout << "Khong co duong di\n";
		} else {
			printPath(startNode, back[targetNode], back);
			cout << targetNode << " ";
		}
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	int n, e;
	int startNode = 0, targetNode = 5;
	
	cin >> node >> edge;
	
	for (int i = 0; i < edge; i++) {
		cin >> n >> e;
		graph[n].push_back(e);
		graph[e].push_back(n);
	}
	
	breathFirstSearch(startNode);
	printPath(startNode, targetNode, back);
	return 0;
}