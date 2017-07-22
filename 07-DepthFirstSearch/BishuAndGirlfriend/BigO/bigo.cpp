#include<iostream> 
#include <list> 
#include <stack> 
using namespace std; 
#define MAX 1005
int V; 
bool visited[MAX]; 
int path[MAX]; 
list<int> graph[MAX];
int dist[MAX];
void PrintPath(int u, int v, int back[]) 
{ 
    if (u == v) 
        cout << v << " "; 
    else 
        if (back[v] == -1) 
             cout << "Khong co duong di\n"; 
        else 
        { 
             PrintPath(u, back[v], back); 
             cout << v << " "; 
        } 
}
void PrintPath2(int s, int f, int back[]) 
{ 
    int b[MAX]; 
    int m = 0; 
    while (1) 
    { 
        b[m++] = f; 
        f = back[f]; 
        if (f == s) 
        { 
             b[m++] = s; 
             break; 
        } 
     } 
     for (int i = m - 1; i >= 0; i--) 
     { 
         cout << b[i] << " "; 
     } 
}
void DFS(int src) 
{ 
    for (int i = 0; i < V; i++)
    { 
        visited[i] = false;
        path[i] = -1; 
    } 
    stack<int> s; 
    visited[src] = true; 
    dist[src] = 0; 
    s.push(src); 
    list<int>::iterator i;
    while (!s.empty()) 
    { 
        src = s.top(); 
        s.pop(); 
        for (i = graph[src].begin(); i != graph[src].end(); i++) 
        { 
            if (!visited[*i]) 
            { 
                 visited[*i] = true; 
                 s.push(*i); 
                 dist[*i] = dist[src] + 1; 
                 path[*i] = src; 
            } 
        } 
    } 
}
int main() 
{ 
    //freopen("INPUT.INP", "rt", stdin); 
    int E, u, v; 
    cin >> V; 
    E = V - 1; 
    for (int i = 0; i<E; i++) 
    { 
         cin >> u >> v; 
         graph[u].push_back(v); 
         graph[v].push_back(u); 
     } 

     DFS(1); 
     int Q; 
     cin >> Q;
     int mini = MAX; int index; 

     while (Q--) {
     	int u;
     	cin >> u; 

     	if (mini > dist[u]) {
     		mini = dist[u];
     		index = u; 
     	}
     }

     cout << index; 
     return 0; 
}