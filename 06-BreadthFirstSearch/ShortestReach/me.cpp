#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_NODE 1000

int n; // number of nodes
int m; // number of edge
int s; // starting node
vector<int> graph[MAX_NODE];
int path[MAX_NODE];
bool visited[MAX_NODE];

void breathFirstSearch(int startNode) {
    for (int i = 0; i < n; i++) {
        // init path and visited elements
        visited[i] = false;
        path[i] = -1;
    }
    
    queue<int> queue;
    visited[startNode] = true;
    queue.push(startNode);
    vector<int>::iterator i;
    
    while(!queue.empty()) {
        // deque each node until queue empty
        startNode = queue.front();
        queue.pop();
        
        for (i = graph[startNode].begin(); i != graph[startNode].end(); i++) {
            // find unvisited node
            if (!visited[*i]) {
                visited[*i] = true; // update visited
                queue.push(*i); // 
                path[*i] = path[startNode] + 6; // update path
            }
        }
    }
    
    for (int i = 0; i < path.size(); i++) {
        cout << path[m] << " ";
    }
}

int main() {
    freopen("me.input.txt", "rt", stdin);
    int q; // number of queries
    int u; // node u
    int v; // node v
    
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        cin >> n >> m;
        for (int j = 0; j < m; j++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[u].push_back(v);
        }
        
        cin >> s;
        
        breathFirstSearch(s);
        return 0;
    }
}