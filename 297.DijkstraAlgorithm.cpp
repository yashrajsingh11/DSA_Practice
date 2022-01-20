// Approach : Dijkstra Algorithm : Run a for loop for n nodes, each time we find the unvisited node with smallest distance(from origin) 
// and update its neightbours distance if unvisited nodes's distance + edge weight(neightbour-unvisited) < neighbour's distance and 
// the neighbour is unvisited.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMin(vector<bool> &visited, vector<int> &minDistance, int n) {
	int mn = INT_MAX;
	int minIndex = -1;
	for(int i = 0; i < n; i++) {
		if(visited[i] == false) {
			if(minDistance[i] < mn) {
				mn = minDistance[i];
				minIndex = i;
			}
		}
	}
	return minIndex;
}

void dijkstra(vector<vector<int>> adjM, vector<bool> visited, vector<int> minDistance, int n) {
	int start = 0;
	minDistance[0] = 0;
	for(int i = 0; i < n; i++) {
		for(int v = 0; v < n; v++) {
			if(adjM[start][v] != -1 and visited[v] == false) {
				if(minDistance[start] + adjM[start][v] < minDistance[v]) {
					minDistance[v] = minDistance[start] + adjM[start][v];
				}
			}
		}
		visited[start] = true;
		start = getMin(visited, minDistance, n);
	}
	for(int i = 0; i < n; i++) {
		cout << i << " -> " << minDistance[i] << endl;
	}
}

void addEdge(vector<vector<int>> &adjM, int i, int j, int weight) {
	adjM[i][j] = weight;
	adjM[j][i] = weight;
}

int main() {
	int n = 9;
	vector<int> minDistance;
	vector<bool> visited;
	for(int i = 0; i < n; i++) {
		minDistance.push_back(INT_MAX);
		visited.push_back(false);
	}

	vector<vector<int>> adjM;
	for(int i = 0; i < n; i++) {
		vector<int> temp;
		for(int j = 0; j < n; j++) {
			temp.push_back(-1);
		}
		adjM.push_back(temp);
	}

	addEdge(adjM, 0, 1, 4);
	addEdge(adjM, 0, 7, 8);
	addEdge(adjM, 1, 2, 8);
	addEdge(adjM, 1, 7, 11);
	addEdge(adjM, 2, 3, 7);
	addEdge(adjM, 2, 5, 4);
	addEdge(adjM, 2, 8, 2);
	addEdge(adjM, 3, 4, 9);
	addEdge(adjM, 3, 5, 14);
	addEdge(adjM, 4, 5, 10);
	addEdge(adjM, 5, 6, 2);
	addEdge(adjM, 6, 7, 1);
	addEdge(adjM, 6, 8, 6);
	addEdge(adjM, 7, 8, 7);

	dijkstra(adjM, visited, minDistance, n);
	return 0;
}