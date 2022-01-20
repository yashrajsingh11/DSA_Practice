// Approach : Use DFS traversal and a boolean array which checks if a node was visited earlier or not. Since it is undirected graph
// also check that parent-child double edge is not a cycle.

#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int>* adj, int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int>* adj, int v) {
	for(int i = 0; i < v; i++) {
		cout << "Edges with vertex " << i << " : ";
		for(int j = 0; j < adj[i].size(); j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}

void getDFS(vector<int>* adj, vector<bool> &visited, int start, int parent, bool &isCyclePresent) {
    if(isCyclePresent == true) {
        return;
    }
    for(int i = 0; i < adj[start].size(); i++) {
        if(visited[adj[start][i]] == false) {
            visited[adj[start][i]] = true;
            getDFS(adj, visited, adj[start][i], start, isCyclePresent);
        }
        else {
            if(adj[start][i] != parent) {
                isCyclePresent = true;
                break;
            }
        }
    }
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited;
    bool isCyclePresent = false;
    for(int i = 0; i < V; i++) {
        visited.push_back(false);
    }
    for(int i = 0; i < V; i++) {
        if(visited[i] == false) {
            visited[i] = true;
            getDFS(adj, visited, i, -1, isCyclePresent);
            if(isCyclePresent == true) {
                break;
            }
        }
    }
    return isCyclePresent;
}

int main() {
	int v = 4;
	vector<int> adj[v];
	// addEdge(adj, 0, 0);
	addEdge(adj, 0, 1);
	// addEdge(adj, 0, 2);
	// addEdge(adj, 1, 2);
	// addEdge(adj, 2, 0);
	// addEdge(adj, 1, 3);
	addEdge(adj, 2, 3);
	printGraph(adj, v);
	cout << isCycle(v, adj);
	return 0;
}