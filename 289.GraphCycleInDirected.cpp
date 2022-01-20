// Approach : Perform DFS traversal. Now, if we reach a node which is already visited then cycle is present.
// This doesnt work for disconnected graph.

#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int>* adj, int u, int v) {
	adj[u].push_back(v);
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

void getDFS(vector<int>* adj, vector<bool> &visited, int v, int start, bool &isCyclePresent) {
	if(isCyclePresent == true) {
		return;
	}
	for(int i = 0; i < adj[start].size(); i++) {
		if(visited[adj[start][i]] == false) {
			visited[adj[start][i]] = true;
			getDFS(adj, visited, v, adj[start][i], isCyclePresent);
		}
		else {
			isCyclePresent = true;
			break;
		}
	}
}

bool dfs(vector<int>* adj, int v) {
	bool isCyclePresent = false;
	vector<bool> visited;
	for(int i = 0; i < v; i++) {
		visited.push_back(false);
	}
	visited[2] = true;
	getDFS(adj, visited, v, 2, isCyclePresent);
	return isCyclePresent;
}

int main() {
	int v = 4;
	vector<int> adj[v];
	addEdge(adj, 0, 1);
	// addEdge(adj, 0, 2);
	// addEdge(adj, 1, 2);
	// addEdge(adj, 2, 0);
	addEdge(adj, 2, 3);
	// addEdge(adj, 3, 3);
	printGraph(adj, v);
	cout << dfs(adj, v);
	return 0;
}