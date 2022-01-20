// Approach : Use a queue and a boolean array which marks if a node is visited or not.
// This doesnt work for disconnected graphs.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> result;
    queue<int> q;
    vector<bool> visited;
    for(int i = 0; i < V; i++) {
        visited.push_back(false);
    }
    q.push(0);
    visited[q.front()] = true;
    while(!q.empty()) {
        int temp = q.front();
        for(int i = 0; i < adj[temp].size(); i++) {
            if(visited[adj[temp][i]] == false) {
                q.push(adj[temp][i]);
                visited[adj[temp][i]] = true;
            }
        }
        result.push_back(temp);
        q.pop();
    }
    return result;
}

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

int main() {
	int v = 5;
	vector<int> adj[v];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);
	printGraph(adj, v);
	vector<int> answer = bfsOfGraph(v, adj);
	for(int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}