// Approach : Use DFS traversal to count the number of disjoint components in the graph and to find the number of cycles in the graph.
// If cycles + 1 >= disjoint components then we have to make disjoint component - 1 connections to connect all.

#include <iostream>
#include <vector>

using namespace std;

void getDFS(vector<int>* adj, vector<bool> &visited, int start, int parent, int &cycles) {
    for(int i = 0; i < adj[start].size(); i++) {
        if(visited[adj[start][i]] == false) {
            visited[adj[start][i]] = true;
            getDFS(adj, visited, adj[start][i], start, cycles);
        }
        else {
            if(adj[start][i] != parent and parent != -1) {
                cycles++;
            }
        }
    }
}

void dfs(vector<int>* adj, int n, int &disjoint, int &cycles) {
    vector<bool> visited;
    for(int i = 0; i < n; i++) {
        visited.push_back(false);
    }
    for(int i = 0; i < n; i++) {
        if(visited[i] == false) {
            disjoint++;
            visited[i] = true;
            getDFS(adj, visited, i, -1, cycles);
        }
    }
}

void addEdge(vector<int>* adj, int u, int v) {
    adj[u].push_back(v);
	adj[v].push_back(u);
}

int makeConnected(int n, vector<vector<int>>& connections) {
    vector<int> adj[n];
    for(int i = 0; i < connections.size(); i++) {
        addEdge(adj, connections[i][0], connections[i][1]);
    }
    
    int disjoint = 0;
    int cycles = 0;
    dfs(adj, n, disjoint, cycles);
    if(cycles >= disjoint - 1) {
        return disjoint - 1;
    }
    return -1;
}

int main() {
	int n = 6;
	vector<vector<int>> connections = {
		{0, 1},
		{0, 2},
		{0, 3},
		{1, 2},
		{1, 3}
	};
	cout << makeConnected(n, connections);
	return 0;
}