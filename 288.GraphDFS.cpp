// Approach : Use recursion to reach the deepest node and a boolean array which marks if a node is visited or not.
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

void getDFS(vector<int>* adj, vector<bool> &visited, int v, vector<int> &result, int start) {
	for(int i = 0; i < adj[start].size(); i++) {
		if(visited[adj[start][i]] == false) {
			result.push_back(adj[start][i]);
			visited[adj[start][i]] = true;
			getDFS(adj, visited, v, result, adj[start][i]);
		}
	}
}

vector<int> dfs(vector<int>* adj, int v) {
	vector<int> result;
	vector<bool> visited;
	for(int i = 0; i < v; i++) {
		visited.push_back(false);
	}
	result.push_back(2);
	visited[2] = true;
	getDFS(adj, visited, v, result, 2);
	return result;
}

int main() {
	int v = 4;
	vector<int> adj[v];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 0);
	addEdge(adj, 1, 3);
	addEdge(adj, 3, 3);
	printGraph(adj, v);
	vector<int> answer = dfs(adj, v);
	for(int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}